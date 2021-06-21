#include "BezierCurve.h"

Eigen::VectorXd BezierCurve::evaluate(double s)
/*
 * Compute multiple points along curve
 * Using a modified Horner's method for each value in @param double s.
 */
{
    const int DIMENSION = this->getNodes().cols();
    double one_less = 1-s;
    Eigen::VectorXd result(DIMENSION);

    evaluate_barycentric(this->getNodes(),s,one_less,result);
    return result;
}

void BezierCurve::evaluate_barycentric(Eigen::Matrix<double,4,2> nodes,double lambda1,double lambda2,Eigen::VectorXd& results)
    /*
     * Evaluate a bezier curve by multiple points along that curve
     * @param nodes: Matrix<double,4,2> The nodes defining a curve
     * @param lambda1, lambda2: Parameter along the curve. In this case, I assume they are both double value,
     *                          and lambda1 + lambda2 = 1
     * @param results: Reference for Eigen 2-dimensional array. The evaluated points
     */
{
    const int NUM_NODES = nodes.rows();
    const int DEGREE = NUM_NODES -1;
    results += lambda1 * nodes.row(0);
    double binom_val = 1.0;
    double lambda2_pow = 1.0;

    for (int i = 1;i < DEGREE;i++){
        lambda2_pow *= lambda2;
        binom_val = (binom_val * (DEGREE - i +1 )) / i;
        results += binom_val * lambda2_pow * nodes.row(i);
        results *= lambda1;
    }
    results += lambda2_pow*lambda2 * nodes.row(DEGREE);
}