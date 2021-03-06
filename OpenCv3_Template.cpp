#include "Main.h"
#include "Processing.h"
#include <list>
#include "Blob.h"
#include <iostream>
#include "OpenCv3_Template.h"
#include <cstdio>
#include <ctime>
#include <string>

const int B = 0;
const int G = 1;
const int R = 2;
const int A = 3;
static const double PI = 3.14159265358979323846;

Mat original;
Mat outGray;
Mat output;
Mat output2;
cv::Mat outputArray;
std::list<Rect> l = std::list<Rect>();
int i = 0;
char* name[] = {"Blobs 1", "Blobs 2", "Blobs 3", "Blobs 4", "Blobs 5", "Blobs 6", "Blobs 7", "Blobs 8",
"Blobs 9", "Blobs 10", "Blobs 11", "Blobs 12", "Blobs 13", "Blobs 14", "Blobs 15", "Blobs 16",
"Blobs 17", "Blobs 18", "Blobs 19", "Blobs 20", "Blobs 21", "Blobs 22", "Blobs 23"};

int votes = 100;

void on_trackbar(int, void*) {
	std::clock_t start;
	double duration;
	start = std::clock();

	//threshold(original, original, 0xFF / 4, 0xFF, THRESH_BINARY);

	//l = detectBlobs(l, original);

	getBlobs(original, l, output);

	//cv::Canny(original, outGray, 50, 100);

	//for (std::list<Rect>::iterator it = l.begin(); it != l.end(); ++it) {
	//	//if ((*it).greaterThan(20, 20)) {
	//		Mat a = outGray(*it);
	//		//khtTransform((*it).getArea(original).clone(), a);
	//		HoughLines(a, outputArray, 1, PI / 180, votes);

	//		std::cout << outputArray.rows << ", " << outputArray.cols << std::endl;
	//		std::cout << outputArray.at<Vec2f>(0, 0) << std::endl << std::endl;

	//		
	//	//}
	//}
	duration = (std::clock() - start);

	std::cout << "Time in milliseconds: " << duration << '\n';

	i = 0;
	for (std::list<Rect>::iterator it = l.begin(); it != l.end(); ++it) {
		//if ((*it).greaterThan(20, 20)) {
			rectangle(output2, *it, Scalar(0, 0, 0xFF));
			i++;
		//}
	}

	//imshow("Blobs", output2);
	imshow("lines", output);
	//imshow("Original", original);
	//imshow("edges", outGray);
}

int main(int argv, char** argc) {
	//Mat test = imread("C:/Users/mattew/Pictures/test2.png", CV_LOAD_IMAGE_GRAYSCALE);
	//Mat test2 = imread("C:/Users/mattew/Pictures/test2.png", CV_LOAD_IMAGE_COLOR);

	//std::clock_t start = std::clock();
	//double duration;

	//std::list<Rect> rects = getBlobs(test, std::list<Rect>());

	//duration = (std::clock() - start);
	//std::cout << "Time in milliseconds: " << duration << '\n';
	//
	//for (std::list<Rect>::iterator it = rects.begin(); it != rects.end(); ++it) {
	//	rectangle(test2, *it, Scalar(0, 0xFF, 0));
	//}

	//imshow("Testing", test2);
	//waitKey();
	//return 0;

	original = imread("C:/Users/mattew/Pictures/test2.png", CV_LOAD_IMAGE_GRAYSCALE);
	outGray = imread("C:/Users/mattew/Pictures/test2.png", CV_LOAD_IMAGE_GRAYSCALE);
	output = imread("C:/Users/mattew/Pictures/test2.png", CV_LOAD_IMAGE_COLOR);
	output2 = imread("C:/Users/mattew/Pictures/test2.png", CV_LOAD_IMAGE_COLOR);

	namedWindow("lines", CV_GUI_NORMAL);
	//namedWindow("Original", CV_GUI_NORMAL);

	//imshow("Blobs", original);
	//imshow("Blobs", original);

	//cv::createTrackbar("Votes", "lines", &votes, 300, on_trackbar);

	on_trackbar(0, (void*)0);

	waitKey();

	return 0;
}

