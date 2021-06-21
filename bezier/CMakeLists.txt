project(Bezier)

set(HEADER_FILES
        BezierCurve.h
        BezierFeatures.h
        BezierPreprocessor.h
        ExtractBezierFeatures.h)

set(SOURCE_FILES
        BezierCurve.cpp
        BezierFeatures.cpp
        BezierPreprocessor.cpp
        ExtractBezierFeatures.cpp)

add_library(bezier STATIC ${SOURCE_FILES} ${HEADER_FILES})