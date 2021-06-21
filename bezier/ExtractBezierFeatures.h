//
// Created by phuc on 06/06/2021.
//

#ifndef FEATURE_EXTRACTION_EXTRACTBEZIERFEATURES_H
#define FEATURE_EXTRACTION_EXTRACTBEZIERFEATURES_H
#include "BezierFeatures.h"
#include "BezierPreprocessor.h"
#include "vector"
class ExtractBezierFeatures {
private:
    BezierPreprocessor preprocessor;
public:
    ExtractBezierFeatures();

    std::vector<VectorXd> extract(std::vector<Matrix3Xd> stk_list);
};


#endif //FEATURE_EXTRACTION_EXTRACTBEZIERFEATURES_H
