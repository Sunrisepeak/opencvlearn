// opencv1.5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<ctime>
#include <Windows.h>
using namespace cv;
using std::cin; using std::cout;
void delay(clock_t s)
{
	clock_t begin, end;
	begin = clock();
	while (1)
	{
		end = clock();
		cout << "正在测试delay--" << (end - begin)*1.0 / CLOCKS_PER_SEC << std::endl;
		if ((end - begin)*1.0 / CLOCKS_PER_SEC == s)
			break;
		cout << "正在测试delay。。。" << std::endl;
	}
}
Mat generator_mask(Mat image)
{

	for (int i = 0; i < 55; i++)
	{
		circle(		//绘制图形方法（圆）
			image,					//目标图像
			cv::Point(155, 110),	//中心点坐标
			i,						//半径
			0,						//颜色（0为黑）
			3						//厚度
		);
	}
	imshow("mask", image);
	Mat mask(image);
	return mask;
}
void test_ROI_Mask_text(Mat image, Mat mask)
{
	namedWindow("Test_ROI_Mask_text");
	while (1)
	{
		for (int i = image.cols; i >= -140; i--)
		{
			Mat text;
			image.copyTo(text);
			cv::putText(	//写入文本方法
				text,					//目标图像
				"This is a dog.",		//文本
				cv::Point(i, 110),	//文本位置
				cv::FONT_HERSHEY_PLAIN, //字体类型
				2.0,					//字体大小
				255,					//字体颜色（255为白）
				2						//文本厚度
			);
			Mat image_show;
			image.copyTo(image_show);
			text.copyTo(image_show, mask);
			cout << "正在测试。。。" << std::endl;
			imshow("text", text);
			imshow("Test_ROI_Mask_text", image_show);
			waitKey(10);
//			Sleep(200);
			cout << "正在测试222。。。" << std::endl;
		}
	}
}
int main()
{
	// define an image window
//	namedWindow("Image");
	Mat image = imread("D:\\project\\opencv\\opencvlearn\\images/puppy.bmp");
	Mat logo = imread("D:\\project\\opencv\\opencvlearn\\images/smalllogo.png");
	auto x = image.cols - logo.cols;
	auto y = image.rows - logo.rows;
	Mat imageROI(
		image,
		Rect(
			x,	//ROI coordinate
			y,
			//ROI size
			logo.cols,
			logo.rows
		)
	);
	cout << "image" << image.cols << "X" << image.rows << std::endl;
	cout << "logo" << logo.cols << "X" << logo.rows << std::endl;
	logo.copyTo(imageROI);
	//this is ROI, not is eventually image to logo and image
//	imshow("Test to Region Of Interest",imageROI);
//	imshow("ROI_rect",image);
/*----------------------------------ROI by range method--------------------------------*/
	//ROI method2, by Range()
	Mat imageROI_Range = image(
	Range(0, logo.rows),
	Range(0, logo.cols)
	);
	logo.copyTo(imageROI_Range);
//	imshow("ROI_range", image);
/*----------------------------------ROI and mask of copyTo()--------------------------------*/
	Mat imageROI_mask = image(Rect(x - logo.cols, y - logo.rows, logo.cols, logo.rows));
	Mat mask(logo);
	logo.copyTo(imageROI_mask, mask);
//	imshow("ROI and mask", image);


	Mat image_r = imread("D:\\project\\opencv\\opencvlearn\\images/puppy.bmp");
	Mat mask_r = imread("D:\\project\\opencv\\opencvlearn\\images/puppy.bmp",CV_LOAD_IMAGE_GRAYSCALE);
	
	test_ROI_Mask_text(image_r, generator_mask(mask_r));
    return 0;
}

