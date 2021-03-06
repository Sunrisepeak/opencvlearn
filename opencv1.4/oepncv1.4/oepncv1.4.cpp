// oepncv1.4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
//测试函数,它创建一副图像
cv::Mat function()
{
	//创建图像
	cv::Mat ima(500, 500, CV_8U, 50);
	return ima;
}
int main()
{
	//创建一个240行x320列的图像
	cv::Mat image1(240, 320, CV_8U, 100);
	cv::imshow("Image", image1);	//显示图像
	cv::waitKey(0);			//等待按键

	//重新分配一个新图像
	image1.create(200, 200, CV_8U);
	image1 = 200;

	cv::imshow("Image", image1);	//显示图像
	cv::waitKey(0);			//等待按键

	//创建一个红色的图像
	//通道次序为BGR
	cv::Mat image2(240, 320, CV_8UC3, cv::Scalar(0, 0, 255));

	//或者
//	cv::Mat image2(cv::Size(320,240), CV_8UC3);
//	image2 = cv::Scalar(0, 0, 255);
	cv::imshow("Image", image2);	//显示图像
	cv::waitKey(0);			//等待按键

	cv::Mat image3 = cv::imread("sunrise.jpg");

	//所有这些图像都指向同一个数据块
	cv::Mat image4(image3);
	image1 = image3;

	//这些图像是原图像的副本图像
	image3.copyTo(image2);
	cv::Mat image5 = image3.clone();

	//转换图像进行测试
	cv::flip(image3, image3, 1);

	//检查哪些图像在处理过程中受到了影响
	cv::imshow("Image3", image3);
	cv::imshow("Image1", image1);
	cv::imshow("Image2", image2);
	cv::imshow("Image4", image4);
	cv::imshow("Image5", image5);

	cv::waitKey(0);

	//从函数中获取一个灰度图像
	cv::Mat gray = function();

	cv::imshow("Image", gray);	//显示图像
	cv::waitKey(0);

	//作为灰色图像读入
	image1 = cv::imread("sunrise.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	image1.convertTo(image2, CV_32F, 1/255.0, 0.0);

	cv::imshow("Image", image2);	//显示图像
	cv::waitKey(0);
    return 0;
}

