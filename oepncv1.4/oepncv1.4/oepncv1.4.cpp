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
    return 0;
}

