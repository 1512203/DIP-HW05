#ifndef DIP_HW05_COMMON_H
#define DIP_HW05_COMMON_H


/* Include libraries */

// C Library
#include <cmath>
#include <cstring>

// C++ Standard Libraries
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// OpenCV Libraries
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


/* Include elements in namespace std */

// Std input / output
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

// Std data structures
using std::map;
using std::string;
using std::vector;

// Std utility functions
using std::max;
using std::min;
using std::stof;
using std::stoi;


/* Include elements in namespace cv */

// OpenCV constants
using cv::IMREAD_COLOR;
using cv::IMREAD_GRAYSCALE;
using cv::WINDOW_AUTOSIZE;

// OpenCV data structures
using cv::Mat;
using cv::Point;
using cv::Scalar;
using cv::Vec3b;

// OpenCV utility functions
using cv::cvtColor;
using cv::imshow;
using cv::imread;
using cv::imwrite;
using cv::namedWindow;
using cv::saturate_cast;
using cv::waitKey;


/* Define type for key-value arguments */

typedef map<string, string> argv_t;


/* Define constants */

// Define error messages
#define ERROR_MESS_INVALID_ARGUMENTS                "Invalid arguments!"
#define ERROR_MESS_INVALID_COMMANDS                 "Invalid command!"

// Define commands
#define COMMAND_GRAD_SOBEL                          "--gra-sobel"
#define COMMAND_GRAD_PREWITT                        "--gra-prewitt"
#define COMMAND_GRAD_SCHARR                         "--gra-scharr"
#define COMMAND_GRAD_ROBERTS                        "--gra-roberts"
#define COMMAND_LAPLACIAN                           "--laplacian"
#define COMMAND_LOG                                 "--log"
#define COMMAND_CANNY                               "--canny"

// Define other necessary constants
const double EPSILON = 1E-9;
const double PI = acos(-1.0);


/* Declare some utility functions (used commonly) */
Mat readImage(string pathToImage);
void displayImage(string windowName, Mat img);
bool isGrayscale(Mat img);
bool isEqualDouble(double a, double b);
bool isLessDouble(double a, double b);
vector<vector<double>> convolution(Mat img, vector< vector<double> > filter);

#endif //DIP_HW05_COMMON_H
