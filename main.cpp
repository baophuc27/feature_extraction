#include "iostream"
#include "bezier/BezierCurve.h"
#include "eigen/Eigen/Core"
int main(){
    Eigen::Vector4d v = Eigen::Vector4d::Ones();
    Eigen::Matrix<double,4,2> m = Eigen::Matrix<double,4,2>::Ones();
    BezierCurve curve = BezierCurve(true,v,3,m);
    std::cout << curve.getNodes();
    return 1;
}
