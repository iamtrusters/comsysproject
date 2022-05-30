#include <opencv2/opencv.hpp>

using namespace cv;
int main() {
	// read the image 
	Mat image = imread("file.jpg");
	// get the height and width of the image
	int height = image.cols;
	int width = image.rows;
	// get tx and ty values for translation
	float tx = -float(width) / 4;
	float ty = float(height) / 4;
	// create the translation matrix using tx and ty
	float warp_values[] = { 1.0, 0.0, tx, 0.0, 1.0, ty };
	Mat translation_matrix = Mat(2, 3, CV_32F, warp_values);
	// save the resulting image in translated_image matrix
	Mat translated_image;
	// apply affine transformation to the original image using the translation matrix
	warpAffine(image, translated_image, translation_matrix, image.size());
	//display the original and the Translated images
	imshow("Translated image", translated_image);
	imshow("Original image", image);
	waitKey(0);
	// save the translated image to disk
	imwrite("translated_image.jpg", translated_image);
	return 0;
}