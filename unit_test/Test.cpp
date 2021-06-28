#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "BezierCurve.h"
#include "BezierFeatures.h"
#include "BezierPreprocessor.h"
#include "ExtractBezierFeatures.h"
#define EPSILON 0.001

TEST_CASE("Bezier curve initialization","[bezier curve]"){
    Eigen::Matrix<double,2,4> v = Eigen::Matrix<double,2,4>::Ones();
    Eigen::Vector4d dt = Eigen::Vector4d::Zero();
    BezierCurve curve = BezierCurve(true,dt,3,v);
    CHECK(curve.getNodes()(0,0) == 1);
    CHECK(curve.getPenUp() == true);
    CHECK(curve.getDegree() == 3);
    CHECK(curve.getDt()(1) == 0);
}

TEST_CASE("Single horizontal curve","[bezier preprocessor]"){
    /* Simple horizontal line
     * start_point = (0,0)
     * c1 = (2,0)
     * c2 = (4,0)
     * end_point = (6,0)
     */
    Eigen::Matrix<double,3,7> h_points ;
    Vector3d p1,p2,p3,p4,p5,p6,p7;
    p1 << 0,0,0;
    p2 << 1,0,0;
    p3 << 2,0,0;
    p4 << 3,0,0;
    p5 << 4,0,0;
    p6 << 5,0,0;
    p7 << 6,0,0;
    h_points << p1,p2,p3,p4,p5,p6,p7;
    BezierPreprocessor preprocessor = BezierPreprocessor();
    std::vector<BezierCurve> curves = preprocessor.to_bezier_curves(h_points);

//    CHECK(curves.size() ==1);
    Eigen::Matrix<double,2,4> nodes =  curves[0].getNodes();
    CHECK(nodes(0,0) == 0);
    CHECK(nodes(0,1) - 2.0 < EPSILON);
    CHECK(nodes(0,2) - 4.0 < EPSILON);
    CHECK(nodes(0,3) - 6.0 < EPSILON);
}

TEST_CASE("Single cubic line","[bezier preprocessor]"){
    Eigen::Matrix<double,3,5> h_points ;
    Vector3d p1,p2,p3,p4,p5,p6,p7;
    p1 << -1,-1,0;
    p2 << 0,0,0;
    p3 << 1,1,0;
    p4 << 2,8,0;
    p5 << -2,-8,0;
    h_points <<p5, p1,p2,p3,p4;
    BezierPreprocessor preprocessor = BezierPreprocessor();
    std::vector<BezierCurve> curves = preprocessor.to_bezier_curves(h_points);

    CHECK(curves.size() ==1);
    Eigen::Matrix<double,2,4> nodes =  curves[0].getNodes();
    CHECK(nodes(0,0) - (-2.0) < EPSILON);
    CHECK(nodes(0,1) - (-6.14867) < EPSILON);
    CHECK(nodes(0,2) - 6.14867 < EPSILON);
    CHECK(nodes(0,3) - 2 < EPSILON);
}

