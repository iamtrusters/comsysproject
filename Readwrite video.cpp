//include libraries
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main() {
	//create a video capture object, in this case we are reading a video from a file
	VideoCapture video_capture("Knight.mp4");
	//VideoCapture class to create an object named video_capture with the video as an input

	//check if the video is opened successfully
	if (!video_capture.isOpened())
	{
		cout << "Error opening video stream or file" << endl;
	}
	else
	{
		//Obtain fps and frame count by get() method and print
		int fps = video_capture.get(5);   // number represents for a kind of metadata that is provided in the list
		//we can use the get() method to retrieve important metadata associated with the video stream
		/*Metadata is "data that provides information about other data", but not the content of the data,
		such as the text of a message or the image itself. There are many distinct types of metadata,
		including: Descriptive metadata – the descriptive information about a resource.
		It is used for discovery and identification.*/
		cout << "Frames per second : " << fps;
		int frame_cout = video_capture.get(7);
		cout << "Frame count :" << frame_cout;
		/*
		After retrieving the desired metadata associated with the video file, we are now ready to
		read each image frame from the file. This is accomplished by creating a loop and reading one frame
		at a time from the video stream using the vid_capture.read() method
		vid_capture.read() returns a tuple, first element is boolean, and the next element is the actual time frame
		When the first element is true, it indicates that the video stream contains a frame to read.

		If there is a frame to read, you can then use imshow() to display the current frame in a window, otherwise
		exit the loop. Notice that you also use the waitkey() function to pause for 20ms between video frames.
		Calling the waitkey() function lets you monitor the keyboard for user input. In this case, for example, if
		the user presses the 'q' key, you exit the loop.
		*/
	}

	while (video_capture.isOpened()) {
		//Initialize frame matrix
		Mat frame;
		//Initialize a boolean to check if frames are there or not
		bool isSuccess = video_capture.read(frame);
		//If frame are present, show it
		if (isSuccess == true) 
		{
			//display frames
			imshow("Frame", frame);
		}
		// If frames are not there, close it
		if (isSuccess == false) {
			cout << "Video camera is disconnected" << endl;
			break;
		}
		//wait 20ms between successive frames and break the loop if key q is pressed
		int key = waitKey(20);
		if (key == 'q') {
			cout << "q key is pressed by the user. Stopping the video" << endl;
			break;
		}
	}
	//Release video capture object
	video_capture.release();
	destroyAllWindows();
}
