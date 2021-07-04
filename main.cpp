#include "ExtractBezierFeatures.h"
#include "iostream"
#include "fstream"
#include "string"
#include "map"
#define LOG(x) std::cout<<x<<std::endl

int main(){
    std::fstream inFile;
    std::string num1,num2;
    std::vector<Eigen::Vector3d> points;
    std::vector<int> point_size;
    std::vector<Matrix3Xd> stk_list;
    int count = 0;
    inFile.open("/home/phuc/CLionProjects/feature_extraction/bezier-data/points/eq4.txt");
    if (!inFile) {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (inFile >> num1 >> num2){
        if (num1 == "break"){
            point_size.push_back(count);
            count = 0;
        }
        else{
            count++;
            Eigen::Vector3d point;
            point << std::stod(num1) , std::stod(num2),0;
            points.push_back(point);
        }
    }
    point_size.push_back(count);


    int index=0;
    for (int i = 0; i < point_size.size(); i++){
        int num_point = point_size[i];
        Eigen::Matrix3Xd h_points(3,num_point);
        for (int j=0;j < num_point;j++){
            h_points.col(j) = (points)[index];
            index++;
        }
        stk_list.push_back(h_points);
    }

    BezierPreprocessor preprocessor = BezierPreprocessor();
    ExtractBezierFeatures extractor = ExtractBezierFeatures();
    extractor.extract(stk_list);
    return 1;
}


