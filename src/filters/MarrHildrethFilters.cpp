#include "MarrHildrethFilters.h"

Mat MarrHildrethFilters::applyFilter(Mat img, argv_t kwargs) {
    double threshold = stof(kwargs["threshold"]);
    Mat result = Mat::zeros(img.size(), img.type());
    vector<vector<double>> deltaSquare = this->LaplacianOperator(img, kwargs);
    int neighbors[4] = { -1, 0, 1, -1 };

    double maxDist = 0.0;
    double maxV = -1.0, minV = 1E9;
    for (int y = 1; y < img.rows-1; ++y) {
        for (int x = 1; x < img.cols-1; ++x) {
            maxV = max(maxV, deltaSquare[y][x]);
            minV = min(minV, deltaSquare[y][x]);
        }
    }
    maxDist = maxV - minV;

    for (int y = 1; y < img.rows-1; ++y) {
        for (int x = 1; x < img.cols-1; ++x) {
            result.at<uchar>(y, x) = 0;
            for (int i = 0; i < 4; ++i) {
                int u = neighbors[i];
                int v = neighbors[(i + 1) % 4];
                double p = deltaSquare[y - u][x - v] * deltaSquare[y + u][x + v];
                double s = fabs(deltaSquare[y - u][x - v] - deltaSquare[y + u][x + v]);
                if (isLessDouble(p, 0.0) && isLessDouble(threshold * maxDist, s)) {
                    if (isEqualDouble(threshold, -1)) {
                        double val = 255.0 * (fabs(deltaSquare[y][x]) + 1) / max(fabs(maxV), fabs(minV));
                        result.at<uchar>(y, x) = saturate_cast<uchar>(val);
                    } else {
                        result.at<uchar>(y, x) = 255;
                    }
                    break;
                }
            }
        }
    }
    return result;
}
