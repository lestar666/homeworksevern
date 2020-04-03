#include <iostream>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat dst;
	Mat src = imread("D:\\lena.jpg", 1);
	if (src.empty())  return -1;

	//变换前4
	cv::Point2f pts1[] = {
		cv::Point2f(150,150),
		cv::Point2f(150,300),
		cv::Point2f(350,300),
		cv::Point2f(350,150)
	};
	//变换后4
	cv::Point2f pts2[] = {
		cv::Point2f(200,150),
		cv::Point2f(200,300),
		cv::Point2f(340,270),
		cv::Point2f(340,180)
	};
	//行列计算
	cv::Mat perspective_matrix = cv::getPerspectiveTransform(pts1, pts2);
	//变换
	cv::warpPerspective(src, dst, perspective_matrix, src.size());

	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	return 0;
}

