#include <utility>

#include "common.h"
#include "EdgeDetector.h"
#include "filters/SobelFilter.h"
#include "filters/PrewittFilter.h"
#include "filters/RobertsFilter.h"
#include "filters/ScharrFilter.h"
#include "filters/LaplaceFilter.h"
#include "filters/LoGFilter.h"


Mat EdgeDetector::processImage(argv_t kwargs) {
    Mat gray_image;
    cvtColor(this->image, gray_image, CV_BGR2GRAY);

    string filter_type = kwargs["filter"];
    if (filter_type == COMMAND_GRAD_SOBEL) {
        return SobelFilter().applyFilter(gray_image, kwargs);
    }
    else if (filter_type == COMMAND_GRAD_PREWITT) {
        return PrewittFilter().applyFilter(gray_image, kwargs);
    }
    else if (filter_type == COMMAND_GRAD_ROBERTS) {
        return RobertsFilter().applyFilter(gray_image, kwargs);
    }
    else if (filter_type == COMMAND_GRAD_SCHARR) {
        return ScharrFilter().applyFilter(gray_image, kwargs);
    }
    else if (filter_type == COMMAND_LAPLACIAN) {
        return LaplaceFilter().applyFilter(gray_image, kwargs);
    }
    else if (filter_type == COMMAND_LOG) {
        return LoGFilter().applyFilter(gray_image, kwargs);
    }
    return Mat();
}

EdgeDetector::EdgeDetector(string pathToImage) : BaseProcessor(std::move(pathToImage)) {
    //
}
