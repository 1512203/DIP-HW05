#include "PrewittFilter.h"

vector<vector<double> > PrewittFilter::calculateFx(Mat img) {
    vector<vector<double>> filter {
            { 1.0/3.0, 0, -1.0/3.0 },
            { 1.0/3.0, 0, -1.0/3.0 },
            { 1.0/3.0, 0, -1.0/3.0 },
    };
    return convolution(img, filter);
}

vector<vector<double> > PrewittFilter::calculateFy(Mat img) {
    vector<vector<double>> filter {
            { -1.0/3.0, -1.0/3.0, -1.0/3.0 },
            {        0,        0,        0 },
            {  1.0/3.0,  1.0/3.0,  1.0/3.0 }
    };
    return convolution(img, filter);
}
