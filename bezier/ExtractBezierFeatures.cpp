#include "ExtractBezierFeatures.h"
#include "iostream"
ExtractBezierFeatures::ExtractBezierFeatures() {
    this->preprocessor = BezierPreprocessor();
}



std::vector<VectorXd> ExtractBezierFeatures::extract(std::vector<Matrix3Xd> stk_list) {
    std::vector<BezierCurve> curves;

    std::cout<<"hello"<<std::endl<<stk_list[0]<<std::endl;
    for (Matrix3Xd points: stk_list){

        points(points.rows()-1,2) = 0;

        if (points.cols() == 1){
            Vector3d q;
            q<<points(0,0),points(0,1)+1,0;
            Matrix3d new_points;
            new_points << points,q;
            points = new_points;
        }

        curves = this->preprocessor.to_bezier_curves(points);
    }
}