
#ifndef FEATURE_EXTRACTION_BEZIERCURVE_H
#define FEATURE_EXTRACTION_BEZIERCURVE_H
#ifndef UNITTEST_BEZIERCURVE_H_

#include "../eigen/Eigen/Core"

class BezierCurve {
private:
    bool pen_up;
    int degree;
    Eigen::Vector4d dt;
    // start_point,c1,c2,end_point. Each point is a 2-d vector.
    Eigen::Matrix<double,4,2> nodes;
    void evaluate_barycentric(Eigen::Matrix<double,4,2> nodes, double lambda1, double lambda2, Eigen::VectorXd& result);
public:
    BezierCurve(bool pen_up,
                Eigen::Vector4d dt,
                int degree,
                Eigen::Matrix<double,4,2>  nodes){
        this->pen_up = pen_up;
        this->dt = dt;
        this->degree = degree;
        this->nodes = nodes;
    };
    bool getPenUp(){
        return pen_up;
    };

    int getDegree(){
        return degree;
    }

    Eigen::Vector4d getDt(){
        return dt;
    };

    Eigen::Matrix<double,4,2> getNodes(){
        return nodes;
    };

    Eigen::VectorXd evaluate(double s);

};
#endif //UNITTEST_BEZIERCURVE_H_
#endif //FEATURE_EXTRACTION_BEZIERCURVE_H
