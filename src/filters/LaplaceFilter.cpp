#include "LaplaceFilter.h"

vector<vector<double>> LaplaceFilter::LaplacianOperator(Mat img, argv_t kwargs) {
    vector<vector<double>> filter {
            { 1,  1, 1 },
            { 1, -8, 1 },
            { 1,  1, 1 }
    };
    return convolution(img, filter);
}
