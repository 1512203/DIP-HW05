#include "common.h"


Mat readImage(string pathToImage) {
    return imread(pathToImage, IMREAD_COLOR);
}

void displayImage(string windowName, Mat img) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, img);
}

bool isGrayscale(Mat img) {
    for (int y = 0; y < img.rows; ++y)
        for (int x = 0; x < img.cols; ++x)
            for (int c = 0; c < 2; ++c)
                if (img.at<Vec3b>(y, x)[c] != img.at<Vec3b>(y, x)[c + 1])
                    return false;
    return true;
}

bool isEqualDouble(double a, double b) {
    double delta = a - b;
    return delta <= EPSILON && delta >= -EPSILON;
}

bool isLessDouble(double a, double b) {
    double delta = a - b;
    return delta + EPSILON < 0;
}

vector<vector<double>> convolution(Mat img, vector< vector<double> > filter) {
    int n = (int)filter.size();
    int m = (int)filter[0].size();
    assert(n % 2 == 1 && m % 2 == 1);

    vector<vector<double>> result((unsigned int)img.rows, vector<double>((unsigned int)img.cols, 0));
    int k = n >> 1;         // y axis
    int h = m >> 1;         // x axis

    for (int y = 0; y < img.rows; ++y) {
        for (int x = 0; x < img.cols; ++x) {
            double value = 0.0;
            for (int j = -k; j <= k; ++j) {             // y axis
                for (int i = -h; i <= h; ++i) {         // x axis
                    if (y - j >= 0 && y - j < img.rows && x - i >= 0 && x - i < img.cols) {
                        value += double(img.at<uchar>(y - j, x - i)) * filter[j + k][i + h];
                    }
                }
            }
            result[y][x] = value;
        }
    }
    return result;
}
