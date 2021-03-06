
#ifndef FEATURE_EXTRACTION_BEZIERPREPROCESSOR_H
#define FEATURE_EXTRACTION_BEZIERPREPROCESSOR_H
#include "BezierCurve.h"
#include "BezierFeatures.h"
#include "vector"
typedef struct CurveWithError{
    BezierCurve curve;
    double error{};
    size_t index;
} curve_with_error;

class BezierPreprocessor {
private:
    double max_error;
    double lamda_error;
    int max_curve_count;
    int max_updates;
    double lr;
    static double find_min_y_of_curves(std::vector<BezierCurve> curves);
    static double find_max_y_of_curves(const std::vector<BezierCurve>& curves);
    static double find_min_y(MatrixXd points);
    static double find_max_y(MatrixXd points);
    static bool is_edge_case(BezierCurve& curve);
    static double determinant(Matrix2d mat);
public:
    BezierPreprocessor(double max_error,
                       double lamda_error,
                       int max_curve_count,
                       int max_updates,
                       double lr){
        BezierFeatures features = BezierFeatures();
        this->max_error = max_error;
        this->lamda_error = lamda_error;
        this->max_curve_count = max_curve_count;
        this->max_updates = max_updates;
        this->lr = lr;
    };
    BezierPreprocessor(){
        BezierFeatures features = BezierFeatures();
        this->max_error = 10;
        this->lamda_error = 1e-5F;
        this->max_curve_count = 100;
        this->max_updates = 10;
        this->lr = 1e-3F;
    }

    double getMaxError() const;

    void setMaxError(double maxError);

    std::vector<VectorXd> preprocess(Matrix3Xd& mat);
    std::vector<BezierCurve> to_bezier_curves(Matrix3Xd &mat);
    static void normalize_curve(std::vector<BezierCurve>& curves,double epsilon = 1e-20);
    BezierCurve fit_curve(Matrix4Xd parametrized_points) const;
    void fit(Matrix3Xd offset_points,std::vector<BezierCurve>& curves);
    CurveWithError fit_with_error(const MatrixXd& offset_points);
    static Matrix4Xd arclength_parametrization(Matrix3Xd offset_points);
    static Matrix4Xd uniform_parametrization(const Matrix3Xd& offset_points);
    static std::vector<VectorXd> extract_features(const std::vector<BezierCurve>& curves);
    static void prune_edge_case(std::vector<BezierCurve>& curves);
    static void shift_coordinate(MatrixXd& points,Vector2d o);
    static void normalize_point(MatrixXd& points);

};


#endif //FEATURE_EXTRACTION_BEZIERPREPROCESSOR_H
