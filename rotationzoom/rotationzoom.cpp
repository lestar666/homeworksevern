
#include <iostream>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat dst;
	cv::Mat src = cv::imread("D:\\1.jpg", 1);
	if (src.empty())
		return -1;
	//旋转-40°
	float angle = -10.0, scale = 1;
	//旋转中心
	cv::Point2f center(src.cols*0.5, src.rows*0.5);
	//变换矩阵
	const cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);

	cv::warpAffine(src, dst, affine_matrix, src.size());

	cv::imshow("src", src);
	cv::imshow("dst", dst);
	waitKey(0);
	return 0;


}

