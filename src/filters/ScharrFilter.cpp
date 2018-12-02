#include "ScharrFilter.h"

vector<vector<double> > ScharrFilter::calculateFx(Mat img) {
    vector<vector<double>> filter {
            {  -3.0/16.0, 0,  3.0/16.0 },
            { -10.0/16.0, 0, 10.0/16.0 },
            {  -3.0/16.0, 0,  3.0/16.0 }
    };
    return convolution(img, filter);
}

vector<vector<double> > ScharrFilter::calculateFy(Mat img) {
    vector<vector<double>> filter {
            { -3.0/16.0, -10.0/16.0, -3.0/16.0 },
            {         0,          0,         0 },
            {  3.0/16.0,  10.0/16.0,  3.0/16.0 }
    };
    return convolution(img, filter);
}
