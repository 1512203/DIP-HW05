#include <utility>

#include "BaseProcessor.h"

BaseProcessor::BaseProcessor(string pathToImage) {
    this->image = readImage(std::move(pathToImage));
}

void BaseProcessor::execute(argv_t kwargs) {
    displayImage("Original Image", this->image);
    Mat resultImage = this->processImage(std::move(kwargs));
    displayImage("Result Image", resultImage);
    waitKey(0);
}
