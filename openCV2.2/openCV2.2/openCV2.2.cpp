// openCV2.2.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"

#include<iostream>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include <random>

void salt(cv::Mat image, int n)
{
	//locate in random
	std::default_random_engine generator;
	std::uniform_int_distribution<int>
		randomRow(0, image.rows - 1),
		randomCol(0, image.cols - 1);

	int i, j;
	for (int k = 0; k < n; k++)
	{
		//random generator local of image
		i = randomCol(generator);
		j = randomRow(generator);
		if (image.type() == CV_8UC1)	//gray image
			image.at<uchar>(j, i) = 255;	//8bit image
		else if (image.type() == CV_8UC3)
		{
			//color image
			//3 
			image.at<cv::Vec3b>(j, i)[0] = 255;
			image.at<cv::Vec3b>(j, i)[1] = 255;
			image.at<cv::Vec3b>(j, i)[2] = 255;
		}
	}
}
int main()
{
	//open image
	cv::Mat image = cv::imread("boldt.jpg", 1);
	//add salt above image by call function 
	salt(image, 3000);

	//display
	cv::namedWindow("Image");
	cv::imshow("Image", image);
	cv::waitKey(0);
	return 0;
}

