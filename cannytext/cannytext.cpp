
#include <iostream>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0);
	while (1) {
		Mat frame;
		cap >> frame;
		Mat dst, ege, gray;
		dst = frame;
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		blur(gray, ege, Size(3, 3));
		Canny(ege, ege, 20, 60, 3);
		imshow("frame", frame);
		imshow("ege", ege);
		waitKey(0);
		return 0;
	}
}
