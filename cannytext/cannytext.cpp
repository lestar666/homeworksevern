
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
		Mat dst, ege, gray,ega;
		dst = frame;
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		blur(gray, ege, Size(3, 3));
		Canny(ege, ege, 20, 60, 3);
		
		imshow("frame", frame);
		imshow("ege", ege);

		Mat grad_x, grad_y;
		Sobel(frame, grad_x, CV_16SC1, 1, 0, 3);
		Sobel(frame, grad_y, CV_16SC1, 0, 1, 3);
		Canny(grad_x, grad_y ,ega, 20, 60);
		imshow("ega", ega);
		waitKey(0);
		return 0;
	}
}
