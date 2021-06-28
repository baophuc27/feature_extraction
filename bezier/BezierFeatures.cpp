
#include "BezierFeatures.h"

VectorXd BezierFeatures::extract_features(BezierCurve curve)
/*
 *  Extract all features of a given bezier curve, follow this order
 *  1. Distance feature (2d)
 *  2. Control endpoint distance feature (2d)
 *  3. Angle feature (2d)
 *  4. Time coefficient feature (3d)
 *  5. Pen up feature (1d)
 */
{
    Matrix<double,2,4> nodes = curve.getNodes();
    Vector2d start_point = nodes.col(0);
    Vector2d c1 = nodes.col(1);
    Vector2d c2 = nodes.col(2);
    Vector2d end_point = nodes.col(3);

    VectorXd features(feature_dimension);

    Vector2d distance_feature = get_endpoint_distance_vector(start_point,end_point);
    if (!this->endpoint_distance_vector){
        distance_feature = Vector2d::Zero();
    }

    Vector2d control_endpoint_distance_feature = get_control_endpoint_distance(start_point,c1,c2,end_point);
    if (!this->control_endpoint_distance){
        control_endpoint_distance_feature = Vector2d::Zero();
    }

    Vector2d angle_feature = get_angle_between_control_endpoint(start_point,c1,c2,end_point);
    if (!this->angle_between_control_endpoint){
        angle_feature = Vector2d::Zero();
    }

    Vector3d time_feature = get_time_coefficient(curve);
    if (!this->time_coefficient){
        time_feature = Vector3d::Zero();
    }

    double pen_up = (curve.getPenUp() ? 1.0 : 0.0);

    features << distance_feature,control_endpoint_distance_feature,angle_feature,time_feature,pen_up;
    return features;
}

Vector2d BezierFeatures::get_endpoint_distance_vector(Vector2d start_point, Vector2d end_point) {
    return end_point - start_point;
}

Vector2d BezierFeatures::get_angle_between_control_endpoint(Vector2d start_point, Vector2d c1, Vector2d c2,
                                                            Vector2d end_point) {
    Vector2d unit_v1 = BezierFeatures::unit_vector(c1-start_point);
    Vector2d unit_v2 = BezierFeatures::unit_vector(end_point-c2);

    Vector2d unit_end_point_vector = BezierFeatures::unit_vector(end_point - start_point);

    // Dot product and clip for valid value of acos.
    double v1_angle = fmax(-1, fmin(1,unit_v1.dot(unit_end_point_vector)));
    double v2_angle = fmax(-1, fmin(1,unit_v2.dot(unit_end_point_vector)));

    Vector2d angle_endpoint;
    angle_endpoint(0) = acos(v1_angle);
    angle_endpoint(1) = acos(v2_angle);

    return angle_endpoint;
}

Vector2d BezierFeatures::get_control_endpoint_distance(Vector2d start_point, Vector2d c1, Vector2d c2,
                                                       Vector2d end_point) {
    double c1_dist = (c1 - start_point).norm();
    double c2_dist = (end_point - c2).norm();
    double c1c2_dist = fmax((c1-c2).norm(),0.05);
    Vector2d distance;
    distance(0) = c1_dist/c1c2_dist;
    distance(1) = c2_dist/c1c2_dist;
    return distance;
}

Vector3d BezierFeatures::get_time_coefficient(BezierCurve curve) {
    Vector4d dt = curve.getDt();
    double p1t = dt(0);
    double t1 = dt(0);
    double t2 = dt(0);
    double p3t = dt(0);

    double t3 = p3t - p1t;
    double t0 = 0.0;

    Vector3d time_coefficient_feature;
    time_coefficient_feature(0) = 3*t1 - t0;
    time_coefficient_feature(1) = 3*t2 - 6*t1 + t0;
    time_coefficient_feature(2) = t3 - 3*t2 + 3*t1 - t0;

    return time_coefficient_feature;
}


