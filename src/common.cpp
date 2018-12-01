//
// Created by lawrence on 01/12/2018.
//

#include "common.h"

Mat readImage(string pathToImage) {
    return imread(pathToImage, IMREAD_COLOR);
}

void displayImage(string windowName, Mat img) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, img);
}

bool isGrayscale(Mat img) {
    return false;
}

bool isEqualDouble(double a, double b) {
    return false;
}

bool isLessDouble(double a, double b) {
    return false;
}

