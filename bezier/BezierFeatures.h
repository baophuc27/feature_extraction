
#ifndef FEATURE_EXTRACTION_BEZIERFEATURES_H
#define FEATURE_EXTRACTION_BEZIERFEATURES_H
#include "../eigen/Eigen/Core"
#include "BezierCurve.h"

using namespace Eigen;



class BezierFeatures{
public:
    BezierFeatures(bool endpoint_distance_vector,
                   bool control_endpoint_distance,
                   bool angle_between_control_endpoint,
                   bool time_coefficient){
        // Plus 1 for pen_up feature
        feature_dimension = endpoint_distance_vector*2 + control_endpoint_distance*2 + angle_between_control_endpoint*2 + time_coefficient*3 + 1;
    };

    BezierFeatures(){
        this->endpoint_distance_vector = true;
        this->control_endpoint_distance = true;
        this->angle_between_control_endpoint = true;
        this->time_coefficient = true;

        // Plus 1 for pen_up feature
        feature_dimension = endpoint_distance_vector*2 + control_endpoint_distance*2 + angle_between_control_endpoint*2 + time_coefficient*3 + 1;
    }

    virtual ~BezierFeatures() {

    }

    int getFeatureDimension() const {
        return feature_dimension;
    }

    void setFeatureDimension(int featureDimension) {
        feature_dimension = featureDimension;
    }

    Vector2d get_endpoint_distance_vector(Vector2d start_point,Vector2d end_point);
    Vector2d get_control_endpoint_distance(Vector2d start_point, Vector2d c1, Vector2d c2, Vector2d end_point);
    Vector2d get_angle_between_control_endpoint(Vector2d start_point, Vector2d c1, Vector2d c2, Vector2d end_point);
    Vector3d get_time_coefficient(BezierCurve curve);
    VectorXd extract_features(BezierCurve curve);
    static Eigen::Vector2d unit_vector(Eigen::Vector2d vector)
    {
        double length = vector.norm();
        return (length == 0.0) ? vector : (vector / length);
    }

private:
    bool endpoint_distance_vector;
    bool control_endpoint_distance;
    bool angle_between_control_endpoint;
    bool time_coefficient;
    int feature_dimension;
};


#endif //FEATURE_EXTRACTION_BEZIERFEATURES_H
