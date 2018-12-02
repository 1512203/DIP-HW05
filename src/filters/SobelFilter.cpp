#include "SobelFilter.h"

vector<vector<double>> SobelFilter::calculateFx(Mat img) {
    vector<vector<double>> filter {
            { 0.25, 0, -0.25 },
            { 0.50, 0, -0.50 },
            { 0.25, 0, -0.25 }
    };
    return convolution(img, filter);
}

vector<vector<double> > SobelFilter::calculateFy(Mat img) {
    vector<vector<double>> filter {
            { -0.25, -0.50, -0.25 },
            {  0.00,  0.00,  0.00 },
            {  0.25,  0.50,  0.25 }
    };
    return convolution(img, filter);
}
