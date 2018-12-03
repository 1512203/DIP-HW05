#include "LoGFilter.h"

vector<vector<double>> LoGFilter::LaplacianOperator(Mat img, argv_t kwargs) {
    cout << "Reach here" << endl;
    double sigma = stof(kwargs["sigma"]);
    int kernel_size = stoi(kwargs["kernel_size"]);
    assert(kernel_size % 2 == 1);

    vector<vector<double>> filter((unsigned int)kernel_size, vector<double>((unsigned int)kernel_size, 0.0));
    double cCoef = 1.0 / (PI * pow(sigma, 4));

    int k = kernel_size >> 1;
    for (int y = -k; y <= k; ++y) {
        for (int x = -k; x <= k; ++x) {
            double z = (x*x + y*y) / (2.0 * sigma * sigma);
            filter[y + k][x + k] = cCoef * (z - 1) * exp(-z);
        }
    }
    return convolution(img, filter);
}
