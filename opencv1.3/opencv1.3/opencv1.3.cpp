// opencv1.3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

int main()
{
	cv::Mat image;
	image = cv::imread("sunrise.jpg",cv::IMREAD_GRAYSCALE);		//读入灰色图像
//	image = cv::imread("sunrise.jpg", cv::IMREAD_COLOR);		//转换为三通道色彩图像
	std::cout << "This image has "
		<< image.channels() << "channel（s）" << std::endl;
	std::cout << "This image is " << image.rows << " x"
		<< image.cols << std::endl;
	if (image.empty())		//错误处理
	{
		std::cout << "This image is empty!" << std::endl;
		return 0;
	}
	cv::namedWindow("Original Image");		//定义窗口
	cv::imshow("Original Image", image);	//显示图像

	cv::flip(image, image, 1);				//翻转图像，就地处理
	cv::imshow("Output Image", image);
	cv::imwrite("test1.jpg", image);		//存储图像
	cv::waitKey(0);							//等待按键
    return 0;
}

