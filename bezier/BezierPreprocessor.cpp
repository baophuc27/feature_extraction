#include "BezierPreprocessor.h"

#include "iostream"
#include "string"
#define MIN(x,y) ((x)<(y)?(x):(y))

std::vector<VectorXd> BezierPreprocessor::preprocess(MatrixXd mat) {
    std::vector<BezierCurve> bezier_curves = this->to_bezier_curves(mat);
    return BezierPreprocessor::extract_features(bezier_curves);
}

std::vector<BezierCurve> BezierPreprocessor::to_bezier_curves(const Matrix3Xd& mat) {

    std::vector<BezierCurve> bezier_curves = this->fit(mat);
    int num = 0;
    if (bezier_curves.size() > 1){
        std::vector<BezierCurve> results;
        for (BezierCurve curve : bezier_curves){
            if (curve.getPenUp()) num++;
            if (!BezierPreprocessor::is_edge_case(curve)){
                results.push_back(curve);
            }
        }
        return results;
    }

}

std::vector<BezierCurve> BezierPreprocessor::fit(MatrixXd offset_points) {
    double error = 0;
    int total_point = offset_points.rows();
    std::vector<BezierCurve> curves;
//    while (total_point >= 4){
//        int anchor = int(5);
//    }
    BezierCurve curve = fit_with_error(offset_points,error);
    curves.push_back(curve);
    if (error < this->lamda_error || offset_points.rows() < 4){
        return curves;
    }
    else{
        int anchor = int(offset_points.rows()/2);
        MatrixXd first_half = offset_points.topRows(anchor);
        MatrixXd second_half = offset_points.bottomRows(anchor);
//        curves.push_back(this->fit(first_half));
    }



}

BezierCurve BezierPreprocessor::fit_with_error(MatrixXd offset_points,double& max_error)
    /*
     * Evaluate maximum error for a produced bezier curve
     * @param offset_points: MatrixXd with shape(3,X) of eigen matrix - X rows, 3 columns
     * @param error: reference for maximum error after evaluated
     * @return bezier curve for a given set of offset points.
     */
{
    Matrix4d parametrized_points = this->arclength_parametrization(offset_points);

    BezierCurve curve = this->fit_curve(parametrized_points);

    // No need to check if not curve cause it always generate a curve in any conditions
    max_error = 0.0;

    for (int i = 0 ; i< offset_points.rows() - 1;i++){
        double s = offset_points(i,3);
        VectorXd array_at_t = curve.evaluate(s);
        double error_offset = offset_points(i,0);
        double error = (array_at_t.array() - error_offset).matrix().norm();

        max_error = (max_error > error) ? max_error : error;
    }

    return curve;

}

Matrix4Xd BezierPreprocessor::arclength_parametrization(Matrix3Xd offset_points)
/*
 * Arclength parametrization base on distance. t is in range [0,1]
 * @param offset_points: Matrix3Xd has a shape of (3,X), with each row is (x,y,pen_up)
 * @return parametrized_points: Matrix4Xd with shape of (4,X), with each row is (x,y,pen_up,t)
 */
{
    Matrix4Xd parametrized_points;

    const int total_points = offset_points.cols();
    // Get key_points matrix for only (x,y). Remove last row, which is pen_up data.
    VectorXd row_x = offset_points.row(0);
    VectorXd row_y = offset_points.row(1);

    VectorXd lengths(7);
    lengths(0) = 0;
    int i = 1;
    while(i < total_points){

        double length = sqrt(pow((row_x(i)-row_x(i-1)),2) + pow((row_y(i)-row_y(i-1)),2));
        lengths(i) = lengths(i-1) + length;
        i++;
    }
    if (lengths(total_points -1) <= 0.005) {
        return BezierPreprocessor::uniform_parametrization(offset_points);
    }

    lengths = lengths / lengths(total_points -1);

    parametrized_points.row(0) = row_x;
    parametrized_points.row(1) = row_y;
    parametrized_points.row(2) = offset_points.row(2);
//    parametrized_points.row(3) = lengths;
    std::cout<<parametrized_points;
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

}

std::vector<VectorXd> BezierPreprocessor::extract_features(const std::vector<BezierCurve>& curves) {

    std::vector<VectorXd> all_curve_features;
    BezierFeatures features = BezierFeatures();
    for(BezierCurve curve : curves){
        all_curve_features.push_back(features.extract_features(curve));
    }

    return all_curve_features;
}

BezierCurve BezierPreprocessor::fit_curve(MatrixX4d parametrized_points){
    Vector4d v0 = parametrized_points.row(0);
    Vector4d v3 = parametrized_points.row(-1);

    double a11 = 0.0;
    double a12 = 0.0;
    double a22 = 0.0;
    Vector4d y1 = Vector4d::Zero();
    Vector4d y2 = Vector4d::Zero();
    double s,s2,s3,one_minus_s,one_minus_s2,one_minus_s3,b0,b1,b2,b3,b0b1,b0b2,b1b1,b1b2,b2b2,b2b3,b1b3;
    bool pen_up = false;
    for(int i = 0; i < parametrized_points.rows() -1;i++){
        Vector4d p = parametrized_points.row(i);
        s = p(3);
        s2 = s*s;
        s3 = s2*s;

        one_minus_s = 1 - s;
        one_minus_s2 = 1 - s2;
        one_minus_s3 = 1- s3;

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
    a12 += this->lamda_error;

    y1 = this->lamda_error * (v0 + (v3 - v0)/3) - y1;
    y2 = this->lamda_error * (v0 + (v3 - v0)*2/3) - y2;

    Matrix2d A,v1x,v2x,v1y,v2y,v1t,v2t;
    A << a11,a12,a12,a22;
    double detA,det_v1x,det_v2x,det_v1y,det_v2y,det_v1t,det_v2t;
//    detA = A.determinant();

    v1x << y1(0),a12,y2(0),a22;
//    double det_v1x = v1x.determinant()/detA;
//
//    v2x << a11,y1(0),a12,y2(0);
//    double det_v2x = v2x.determinant()/detA;
//
//    v1y << y1(1),a12,y2(1),a22;
//    double det_v1y = v1y.determinant()/detA;
//
//    v2y << a11,y1(1),a12,y2(1);
//    double det_v2y = v2y.determinant();
//
//    v1t << y1(3),a12,y2(3),a22;
//    double det_v1t = v1t.determinant()/detA;
//
//    v2t << a11,y1(3),a12,y2(3);
//    double det_v2t = v2t.determinant()/detA;

    Vector4d v1,v2,dt;
    v1 << det_v1x,det_v1y,0,det_v1t;
    v2 << det_v2x,det_v2y,0,det_v2t;

    dt << 0.0, v1(3),v2(3),v3(3)-v0(3);

    Matrix<double,4,2> nodes;
    nodes << v0(0),v1(0),v2(0),v3(0),
            v0(1),v1(1),v2(1),v3(1);


    BezierCurve curve = BezierCurve(pen_up,dt,3,nodes);
    return curve;
}

bool BezierPreprocessor::is_edge_case(BezierCurve &curve) {
    Eigen::Matrix<double,4,2> nodes =  curve.getNodes();

    if ((nodes(0,0) == nodes(0,3)) &&( nodes(1,0) == nodes(1,3))){
        return false;
    }
    return true;
}
