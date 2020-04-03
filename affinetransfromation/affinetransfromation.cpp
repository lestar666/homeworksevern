// affinetransfromation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat dst;
	Mat src = imread("D:\\1.jpg", 1);
	if (src.empty()) return -1;

	//变换前坐标
	const cv::Point2f src_pt[] = {
		cv::Point2f(200,200),
		cv::Point2f(250,200),
		cv::Point2f(200,100)
	};
	//变换后坐标
	const cv::Point2f dst_pt[] = {
		cv::Point2f(300,100),
		cv::Point2f(300,50),
		cv::Point2f(200,100)
	};
	//计算矩阵
	const cv::Mat affine_matrix = cv::getAffineTransform(src_pt, dst_pt);
	cv::warpAffine(src, dst, affine_matrix, src.size());

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	return 0;

}


