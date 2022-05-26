//Import libraries
#include <iostream>
#include <opencv2/opencv.hpp>
//Namespace to nullify use of cv::function() ; syntax

using namespace std;
using namespace cv;
int main() {
	//reading image
	Mat image = imread("file.jpg");

	//Get height and width
	cout << "Original Height and Width : " << image.rows << "x" << image.cols << endl;
	//Set rows and columns
	//lets downsize the image using new width and height
	int down_height = 200;
	int down_width = 300;
	auto down_points = Size(down_width, down_height);
	Mat resize_down;
	resize(image, resize_down, down_points, INTER_LINEAR);
	imshow("Resize down", resize_down);
	//Set rows and columns
	int up_width = 600;
	int up_height = 400;
	auto upsizes = Size(up_width, up_height);
	Mat resized_up;
	//resize up
	resize(image, resized_up, upsizes, INTER_LINEAR);
	imshow("Resize up", resized_up);
	double scale_up_x = 1.2;
	double scale_up_y = 1.2;
	//Scaling Down the image 0.6 times specifying a single scale factor
	double scale_down = 0.6;
	Mat scaled_f_up, scaled_f_down;
	//resize
	resize(image, scaled_f_up, Size(), scale_up_x, scale_up_y, INTER_LINEAR);
	resize(image, scaled_f_down, Size(), scale_down, scale_down, INTER_LINEAR);
	//imshow the images
	imshow("Scaled up image", scaled_f_up);
	imshow("Scaled down image", scaled_f_down);
	waitKey();
	destroyAllWindows();
	return 0;
}

