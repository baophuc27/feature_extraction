#include "ExtractBezierFeatures.h"
#include "iostream"


#define LOG(x) std::cout<<x<<std::endl

ExtractBezierFeatures::ExtractBezierFeatures() {
    this->preprocessor = BezierPreprocessor();
}



std::vector<VectorXd> ExtractBezierFeatures::extract(std::vector<Matrix3Xd> stk_list)
/*
 * Extract all features by a given set of strokes.
 * @param: stk_list std::vector of Matrix3Xd. Each row in the matrix is a point with (x,y,pen_up)
 * @return: std::vector<VectorXd> A vector of 10-d extracted by bezier features.
 */
{
    std::vector<BezierCurve> curves;
    for (int index = 0 ; index < stk_list.size();index++){
        Matrix3Xd points = stk_list[index];
        points(points.rows()-1,2) = 0;

        if (points.cols() == 1){
            Vector3d q;
            q<<points(0,0),points(0,1)+1,0;
            Matrix3d new_points;
            new_points << points,q;
            points = new_points;
        }

        std::vector<BezierCurve> feats = this->preprocessor.to_bezier_curves(points);
        for (BezierCurve& feat: feats){
            curves.push_back(feat);
        }

//        if (index < stk_list.size() -1){
//            Matrix3Xd off_stroke = Matrix<double,3,2>::Zero();
//            Vector3d last_points  = points.col(points.cols() -1);
//            off_stroke(0,0) = last_points(0);
//            off_stroke(1,0) = last_points(1);
//            off_stroke(2,0) = 1.0;
//            Vector3d start_point = stk_list[index +1].col(0);
//            off_stroke(0,1) = start_point(0);
//            off_stroke(1,1) = start_point(1);
//            feats = this->preprocessor.to_bezier_curves(off_stroke);
//
//            for (const BezierCurve& feat: feats){
//                curves.push_back(feat);
//            }
//        }
    }
    curves[curves.size()-1].setPenUp(true);
    LOG(curves.size());
    BezierPreprocessor::normalize_curve(curves);

    std::vector<VectorXd> feats = BezierPreprocessor::extract_features(curves);
    return feats;
}

