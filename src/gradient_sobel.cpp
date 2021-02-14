#include <iostream>
#include <numeric>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

void gradientSobel()
{
    // TODO: Based on the image gradients in both x and y, compute an image 
    // which contains the gradient magnitude according to the equation at the 
    // beginning of this section for every pixel position. Also, apply different 
    // levels of Gaussian blurring before applying the Sobel operator and compare the results.

    // load image from file
    cv::Mat img;
    //img = cv::imread("./images/img2gray.png");
    img = cv::imread("../images/img1.png");

    // convert image to grayscale
    cv::Mat imgGray;
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

    // apply smoothing using the GaussianBlur() function from the OpenCV
    cv::Mat blurred = imgGray.clone();
    int filterSize = 5;
    int stdDev = 2.0;
    cv::GaussianBlur(imgGray, blurred, cv::Size(filterSize, filterSize), stdDev);

    // create filter kernels using the cv::Mat datatype both for x and y
    float sobel_x[9] = {-1, 0, +1, -2, 0, +2, -1, 0, +1};
    cv::Mat kernel_x = cv::Mat(3, 3, CV_32F, sobel_x);

    float sobel_y[9] = {-1, -2, -1, 0, 0, 0, +1, +2, +1};
    cv::Mat kernel_y = cv::Mat(3, 3, CV_32F, sobel_y);

    // apply filter using the OpenCv function filter2D()
    cv::Mat result_x, result_y;
    cv::filter2D(blurred, result_x, -1, kernel_x, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);
    cv::filter2D(blurred, result_y, -1, kernel_y, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);

      // show result
    string windowNamex = "Sobel operator (x-direction)";
    cv::namedWindow(windowNamex, 1); // create window
    cv::imshow(windowNamex, result_x);
    cv::waitKey(0); // wait for keyboard input before continuing
      string windowNamey = "Sobel operator (y-direction)";
    cv::namedWindow(windowNamey, 1); // create window
    cv::imshow(windowNamey, result_y);
    cv::waitKey(0); // wait for keyboard input before continuing
    
}

int main()
{
    gradientSobel();
}