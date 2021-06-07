//
// Created by phuc on 07/06/2021.
//

#include <numeric>
#include "BezierPreprocessor.h"

BezierFeatures* BezierPreprocessor::preprocess(MatrixXd mat) {

    BezierCurve* curves = this->to_bezier_curves(mat);
    return extract_features(curves);
}

BezierCurve * BezierPreprocessor::to_bezier_curves(MatrixXd mat) {
    BezierCurve * curves = fit(mat);
    auto prune_edge_case = [](){

    };
}

MatrixXd BezierPreprocessor::uniform_parametrization(MatrixXd offset_points) {

}

BezierCurve * BezierPreprocessor::fit(MatrixXd offset_points) {

}

auto BezierPreprocessor::fit_with_error(MatrixXd offset_points) {

}

MatrixXd BezierPreprocessor::arclength_parametrization(MatrixXd offset_points) {

}

BezierCurve BezierPreprocessor::normalize_curve(BezierCurve* curves, double epsilon) {
    double first_point = curves[0].getNodes()(0,0);
    return curves[0];
}

BezierFeatures * BezierPreprocessor::extract_features(BezierCurve *curves) {

}

BezierCurve BezierPreprocessor::fit_curve(MatrixX4d parametrized_points) {
    Vector4d v0 = parametrized_points.row(0);
    Vector4d v3 = parametrized_points.row(-1);

    double a11 = 0.0;
    double a12 = 0.0;
    double a22 = 0.0;
    Vector4d y1 = Vector4d::Zero();
    Vector4d y2 = Vector4d::Zero();
    double s,s2,s3,one_minus_s,one_minus_s2,one_minus_s3,b0,b1,b2,b3,b0b1,b0b2,b1b1,b1b2,b2b2,b2b3,b1b3;
    bool pen_up = false;
    for(int i = 0; i < parametrized_points.rows();i++){
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

    double detA = A.determinant();

    v1x << y1(0),a12,y2(0),a22;
    double det_v1x = v1x.determinant()/detA;

    v2x << a11,y1(0),a12,y2(0);
    double det_v2x = v2x.determinant()/detA;

    v1y << y1(1),a12,y2(1),a22;
    double det_v1y = v1y.determinant()/detA;

    v2y << a11,y1(1),a12,y2(1);
    double det_v2y = v2y.determinant();

    v1t << y1(3),a12,y2(3),a22;
    double det_v1t = v1t.determinant()/detA;

    v2t << a11,y1(3),a12,y2(3);
    double det_v2t = v2t.determinant()/detA;

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