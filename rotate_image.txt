//Rotation images and translating images
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main() {
	//Reading the image
	Mat image = imread("file.jpg");
	//Get the center coordinates of the image to create the 2D rotation matrix
	Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);

	//Create the rotation matrix using the image center
	Mat rotation_matrix = getRotationMatrix2D(center, 45, 1.0);
	//Save the image in new matrix
	Mat rotated_image;
	//apply affine transformation to the original image using the 2D rotation matrix
	warpAffine(image, rotated_image, rotation_matrix, image.size());
	imshow("Rotated image", rotated_image);
	waitKey(0);
	// save the rotated image to disk
	imwrite("rotated_im.jpg", rotated_image);

}
