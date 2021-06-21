
#ifndef FEATURE_EXTRACTION_BEZIERPREPROCESSOR_H
#define FEATURE_EXTRACTION_BEZIERPREPROCESSOR_H
#include "BezierCurve.h"
#include "BezierFeatures.h"
#include "vector"

class BezierPreprocessor {
private:
    double max_error;
    double lamda_error;
    int max_curve_count;
    int max_updates;
    double lr;
public:
    BezierPreprocessor(double max_error,
                       double lamda_error,
                       int max_curve_count,
                       int max_updates,
                       double lr ){
        BezierFeatures features = BezierFeatures();
        this->max_error = max_error;
        this->lamda_error = lamda_error;
        this->max_curve_count = max_curve_count;
        this->max_updates = max_updates;
    };
    BezierPreprocessor(){
        BezierFeatures features = BezierFeatures();
        this->max_error = 0.25F;
        this->lamda_error = 1e-5F;
        this->max_curve_count = 100;
        this->max_updates = 10;
    }
    std::vector<VectorXd> preprocess(MatrixXd mat);
    std::vector<BezierCurve> to_bezier_curves(const Matrix3Xd& mat);
    static void normalize_curve(std::vector<BezierCurve>& curves,double epsilon = 1e-20);
    BezierCurve fit_curve(MatrixX4d parametrized_points);
    std::vector<BezierCurve> fit(MatrixXd offset_points);
    BezierCurve fit_with_error(MatrixXd offset_points,double& error);
    Matrix4Xd arclength_parametrization(Matrix3Xd offset_points);
    static Matrix4Xd uniform_parametrization(const Matrix3Xd& offset_points);
    static std::vector<VectorXd> extract_features(const std::vector<BezierCurve>& curves);
    static bool is_edge_case(BezierCurve& curve);
};


#endif //FEATURE_EXTRACTION_BEZIERPREPROCESSOR_H
