// opencv1.3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
void onMouse(int event, int x, int y, int flags, void* param)
{
	cv::Mat *im = reinterpret_cast<cv::Mat*>(param);
	switch (event)
	{
	case cv::EVENT_LBUTTONDOWN:			//鼠标左键按下事件
		//显示像素值（x，y）
		std::cout << "at (" << x << "," << y << ") value is: "
			<< static_cast<int>(im->at<uchar>(cv::Point(x, y))) << std::endl;
		break;
	}
}
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
/*-----------------------------opencv2/imgproc.hpp模块--------------------------------*/
	cv::circle(		//绘制图形方法（圆）
		image,					//目标图像
		cv::Point(320, 320),	//中心点坐标
		200,						//半径
		0,						//颜色（0为黑）
		3						//厚度
	);
	cv::putText(	//写入文本方法
		image,					//目标图像
		"This is a book.",		//文本
		cv::Point(200, 550),	//文本位置
		cv::FONT_HERSHEY_PLAIN, //字体类型
		2.0,					//字体大小
		255,					//字体颜色（255为白）
		2						//文本厚度
	);
	cv::namedWindow("Original Image");		//定义窗口
	cv::imshow("Original Image", image);	//显示图像
	//注册回调函数
	cv::setMouseCallback("Original Image", onMouse, reinterpret_cast<void*>(&image));
	cv::flip(image, image, 1);				//翻转图像，就地处理
	cv::imshow("Output Image", image);
	cv::imwrite("test1.jpg", image);		//存储图像
	cv::waitKey(0);							//等待按键
    return 0;
}

