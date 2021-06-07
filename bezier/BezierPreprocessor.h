//
// Created by phuc on 07/06/2021.
//

#ifndef FEATURE_EXTRACTION_BEZIERPREPROCESSOR_H
#define FEATURE_EXTRACTION_BEZIERPREPROCESSOR_H
#include "BezierCurve.h"
#include "BezierFeatures.h"

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
    BezierFeatures* preprocess(MatrixXd mat);
    BezierCurve* to_bezier_curves(MatrixXd mat);
    BezierCurve normalize_curve(BezierCurve* curves,double epsilon = 1e-20);
    BezierCurve fit_curve(MatrixX4d parametrized_points);
    BezierCurve* fit(MatrixXd offset_points);
    auto fit_with_error(MatrixXd offset_points);
    MatrixXd arclength_parametrization(MatrixXd offset_points);
    MatrixXd uniform_parametrization(MatrixXd offset_points);
    BezierFeatures* extract_features(BezierCurve* curves);


};


#endif //FEATURE_EXTRACTION_BEZIERPREPROCESSOR_H
