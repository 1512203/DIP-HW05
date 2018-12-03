#include "GradientFilters.h"


Mat GradientFilters::applyFilter(Mat img, argv_t kwargs) {
    double threshold = stof(kwargs["threshold"]);

    Mat result = Mat::zeros(img.size(), img.type());

    vector< vector<double> > fx = this->calculateFx(img);
    vector< vector<double> > fy = this->calculateFy(img);
    vector< vector<double> > g((unsigned int)img.rows, vector<double>((unsigned int)img.cols, 0));
    double maxVal = -1, minVal = 1E9;

    for (int y = 0; y < img.rows; ++y) {
        for (int x = 0; x < img.cols; ++x) {
            g[y][x] = fabs(fx[y][x]) + fabs(fy[y][x]);
            maxVal = max(maxVal, g[y][x]);
            minVal = min(minVal, g[y][x]);
        }
    }

    for (int y = 0; y < img.rows; ++y) {
        for (int x = 0; x < img.cols; ++x) {
            double v = 255.0 * (g[y][x] - minVal + 1) / (maxVal - minVal + 1);
            if (isEqualDouble(threshold, -1)) {
                result.at<uchar>(y, x) = saturate_cast<uchar>(v);
            } else {
                if (v > threshold * 255) {
                    result.at<uchar>(y, x) = 255;
                } else {
                    result.at<uchar>(y, x) = 0;
                }
            }
        }
    }

    return result;
}
