#include "RobertsFilter.h"

vector<vector<double> > RobertsFilter::calculateFx(Mat img) {
    vector<vector<double>> filter {
            { 0, 0, -1 },
            { 0, 1,  0 },
            { 0, 0,  0 }
    };
    return convolution(img, filter);
}

vector<vector<double> > RobertsFilter::calculateFy(Mat img) {
    vector<vector<double>> filter {
            { -1, 0, 0 },
            {  0, 1, 0 },
            {  0, 0, 0 }
    };
    return convolution(img, filter);
}
