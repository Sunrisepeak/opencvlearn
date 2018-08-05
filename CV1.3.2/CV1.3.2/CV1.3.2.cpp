// CV1.3.2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
//using namespace cv;
int main()
{
	cv::Mat image;
	std::cout << "This image is " << image.rows << "x"
		<< image.cols << std::endl;
//	image = cv::imread("D:\\project\\opencv\\OpenCV3_cvapc\\CV1.3.2/speak.jpg", cv::IMREAD_GRAYSCALE);
	image = cv::imread("speak.jpg", cv::IMREAD_COLOR);
	std::cout << "This image has "
		<< image.channels() << " channals(s)";
	if (image.empty())
	{
		std::cout << "read error!" << std::endl;
		return 0;
	}
	cv::namedWindow("Sunrise");
	cv::imshow("Sunrise",image);
//	cv::Mat result;
	cv::flip(image, image, 1);
	cv::namedWindow("Output Image");
	cv::imshow("Output Image", image);
	cv::imwrite("output.bmp", image);
	cv::waitKey(0);
    return 0;
}

