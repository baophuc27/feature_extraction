#include "BezierPreprocessor.h"

#include "iostream"
#define LOG(x) std::cout<<x<<std::endl

std::vector<VectorXd> BezierPreprocessor::preprocess(const MatrixXd& mat)

{
    std::vector<BezierCurve> bezier_curves = this->to_bezier_curves(mat);
    return BezierPreprocessor::extract_features(bezier_curves);
}

std::vector<BezierCurve> BezierPreprocessor::to_bezier_curves(const Matrix3Xd& mat)
/*
 * Produce and prune edge cases of bezier curves
 * @param reference for a list of given points. Each point has 3 dimension (x,y,pen_up)
 * @return a vector of Bezier Curve
 */
{

    std::vector<BezierCurve> bezier_curves;
    this->fit(mat,bezier_curves);
    int num = 0;
    if (bezier_curves.size() > 1){
        std::vector<BezierCurve> results ;
        for (BezierCurve curve : bezier_curves){
            if (curve.getPenUp()) num++;
            if (BezierPreprocessor::is_edge_case(curve)){
                results.push_back(curve);
            }
        }
        return results;
    }
    return bezier_curves;
}

void BezierPreprocessor::fit(Matrix3Xd offset_points,std::vector<BezierCurve>& curves)
/*
 * Main function for fitting bezier curve
 * @param offset_points: Matrix of given offset points. Each point has 3 dimension (x,y,pen_up)
 * @return a vector of Bezier Curves.
 */
{
    int total_point = offset_points.cols();
    CurveWithError curve_with_error = fit_with_error(offset_points);
    BezierCurve curve = curve_with_error.curve;
    double error = curve_with_error.error;
    if (this->getMaxError() > error || total_point < 3){
        curves.push_back(curve);
        return;
    }
    // Find the point which have maximum error to split CAN BE the better method
    this->fit(offset_points.leftCols(int(total_point/2)+1),curves);
    this->fit(offset_points.rightCols(int(total_point/2)+1),curves);


}

CurveWithError BezierPreprocessor::fit_with_error(const MatrixXd& offset_points)
    /*
     * Evaluate maximum error for a produced bezier curve
     * @param offset_points: MatrixXd with shape(3,X) of eigen matrix - X rows, 3 columns
     * @param error: reference for maximum error after evaluated
     * @return bezier curve for a given set of offset points.
     */
{
    Matrix4Xd parametrized_points = BezierPreprocessor::arclength_parametrization(offset_points);

    BezierCurve curve = this->fit_curve(parametrized_points);

    // No need to check if not curve cause it always generate a curve in any conditions
    double max_curve_error = 0.0;
    for (int i = 0 ; i< parametrized_points.cols();i++){
        double s = parametrized_points(3,i);
        VectorXd array_at_t = curve.evaluate(s);
        Vector2d error_offset;
        error_offset<<parametrized_points(0,i),parametrized_points(1,i);
        double error = (array_at_t - error_offset).matrix().norm();

        max_curve_error = (max_curve_error > error) ? max_curve_error : error;
    }

    return {curve,max_curve_error};

}

Matrix4Xd BezierPreprocessor::arclength_parametrization(Matrix3Xd offset_points)
/*
 * Arclength parametrization base on distance. t is in range [0,1]
 * @param offset_points: Matrix3Xd has a shape of (3,X), with each row is (x,y,pen_up)
 * @return parametrized_points: Matrix4Xd with shape of (4,X), with each row is (x,y,pen_up,t)
 */
{
    const int total_points = offset_points.cols();

    MatrixXd lengths(1,total_points);
    Matrix4Xd parametrized_points(offset_points.rows() + lengths.rows(),total_points);
    // Get key_points matrix for only (x,y). Remove last row, which is pen_up data.
    VectorXd row_x = offset_points.row(0);
    VectorXd row_y = offset_points.row(1);

    lengths(0,0) = 0;
    int i = 1;
    while(i < total_points){

        double length = sqrt(pow((row_x(i)-row_x(i-1)),2) + pow((row_y(i)-row_y(i-1)),2));
        lengths(i) = lengths(0,i-1) + length;
        i++;
    }
    if (lengths(total_points -1) <= 0.005) {
        return BezierPreprocessor::uniform_parametrization(offset_points);
    }

    lengths = lengths / lengths(0,total_points -1);


    parametrized_points << offset_points,lengths;
    parametrized_points = parametrized_points.reshaped(4,total_points);
    return parametrized_points;
}


Matrix4Xd BezierPreprocessor::uniform_parametrization(const Matrix3Xd& offset_points) {

    Matrix4Xd parametrized_points;
    const int total_point = offset_points.rows();
    VectorXd uniform_length = Eigen::VectorXd::LinSpaced(total_point,0,total_point-1) / total_point;
    parametrized_points << offset_points,uniform_length;

    return parametrized_points;
}


void BezierPreprocessor::normalize_curve(std::vector<BezierCurve>& curves, double epsilon) {
    double first_point = curves[0].getNodes()(0,0);

    double minY = findMinY(curves);

    for (BezierCurve& curve: curves){
        Matrix<double,2,4> diff = Matrix<double,2,4>::Zero();
        diff.row(0).fill(first_point);
        diff.row(1).fill(minY);
        Matrix<double,2,4> newNodes = curve.getNodes() - diff;
        curve.setNodes(newNodes);
    }

    double maxY  = findMaxY(curves);

    if (maxY == 0.0) maxY =1.0;

    for (BezierCurve& curve:curves){
        Matrix<double,2,4> diff = curve.getNodes();
        curve.setNodes(diff/maxY);
    }
}

std::vector<VectorXd> BezierPreprocessor::extract_features(const std::vector<BezierCurve>& curves) {

    std::vector<VectorXd> all_curve_features;
    BezierFeatures features = BezierFeatures();
    for(const BezierCurve& curve : curves){
        all_curve_features.push_back(features.extract_features(curve));
    }

    return all_curve_features;
}

BezierCurve BezierPreprocessor::fit_curve(Matrix4Xd parametrized_points) const{
    Vector4d v0 = parametrized_points.col(0);
    Vector4d v3 = parametrized_points.col(parametrized_points.cols() -1);
    double a11 = 0.0;
    double a12 = 0.0;
    double a22 = 0.0;
    Vector4d y1 = Vector4d::Zero();
    Vector4d y2 = Vector4d::Zero();
    double s,s2,s3,one_minus_s,one_minus_s2,one_minus_s3,b0,b1,b2,b3,b0b1,b0b2,b1b1,b1b2,b2b2,b2b3,b1b3;
    bool pen_up = false;
    for(int i = 0; i < parametrized_points.cols() ;i++){
        Vector4d p = parametrized_points.col(i);
        s = p(3);
        s2 = s*s;
        s3 = s2*s;

        one_minus_s = 1 - s;
        one_minus_s2 = one_minus_s * one_minus_s;
        one_minus_s3 = one_minus_s2 * one_minus_s;

        b0 = one_minus_s3;
        b1 = 3*one_minus_s2*s;
        b2 = 3*one_minus_s*s2;
        b3 = s3;

        b0b1 = b0*b1;
        b0b2 = b0*b2;
        b1b1 = b1*b1;
        b1b2 = b1*b2;
        b1b3 = b1*b3;
        b2b2 = b2*b2;
        b2b3 = b2*b3;

        a11 += b1b1;
        a12 += b1b2;
        a22 += b2b2;

        y1 += v0*b0b1 + v3*b1b3 - b1*p;
        y2 += b0b2 * v0 + b2b3*v3 - b2*p;
        pen_up = pen_up | bool(p(2));
    }
    a11 += this->lamda_error;
    a22 += this->lamda_error;

    y1 = this->lamda_error * (v0 + (v3 - v0)/3) - y1;
    y2 = this->lamda_error * (v0 + (v3 - v0)*2/3) - y2;
    Matrix2d A;
    Matrix2d v1x,v2x,v1y,v2y,v1t,v2t;
    A << a11,a12,a12,a22;
    double detA = determinant(A);

    v1x << y1(0),a12,y2(0),a22;
    double det_v1x = determinant(v1x)/detA;

    v2x << a11,y1(0),a12,y2(0);
    double det_v2x = determinant(v2x)/detA;

    v1y << y1(1),a12,y2(1),a22;
    double det_v1y = determinant(v1y)/detA;

    v2y << a11,y1(1),a12,y2(1);
    double det_v2y = determinant(v2y) /detA;

    v1t << y1(3),a12,y2(3),a22;
    double det_v1t = determinant(v1t)/detA;

    v2t << a11,y1(3),a12,y2(3);
    double det_v2t = determinant(v2t)/detA;

    Vector4d v1,v2,dt;
    v1 << det_v1x,det_v1y,0,det_v1t;
    v2 << det_v2x,det_v2y,0,det_v2t;

    dt << 0.0, v1(3),v2(3),v3(3)-v0(3);

    Matrix<double,2,4> nodes;
    nodes << v0(0),v1(0),v2(0),v3(0),
            v0(1),v1(1),v2(1),v3(1);


    BezierCurve curve = BezierCurve(pen_up,dt,3,nodes);
    return curve;
}
double BezierPreprocessor::determinant(Matrix2d mat) {
    return mat(0,0)*mat(1,1) - mat(1,0)*mat(0,1);
}
bool BezierPreprocessor::is_edge_case(BezierCurve &curve) {
    Eigen::Matrix<double,2,4> nodes =  curve.getNodes();
    if ((nodes(0,0) == nodes(0,3)) &&( nodes(1,0) == nodes(1,3))){
        return false;
    }
    return true;
}

double BezierPreprocessor::getMaxError() const {
    return max_error;
}

void BezierPreprocessor::setMaxError(double maxError) {
    max_error = maxError;
}

double BezierPreprocessor::findMaxY(const std::vector<BezierCurve>& curves) {
    double maxY = 0.0;
    for (BezierCurve curve: curves){
        Matrix<double,2,4> nodes = curve.getNodes();
        if (nodes.row(1).maxCoeff() > maxY){
            maxY = nodes.row(1).maxCoeff();
        }
    }
    return maxY;
}

double BezierPreprocessor::findMinY(std::vector<BezierCurve> curves) {
    double minY = 0.0;
    for (BezierCurve curve: curves){
        Matrix<double,2,4> nodes = curve.getNodes();
        if (nodes.row(1).minCoeff() < minY){
            minY = nodes.row(1).minCoeff();
        }
    }
    return minY;
}