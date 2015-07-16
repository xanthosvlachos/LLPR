#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	VideoCapture cap(0);
	if (!cap.isOpened()) { // if not success, exit program
		    cout << "Cannot open any video cam" << endl;
	}

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Frame size : " << dWidth << " x " << dHeight << endl;

	namedWindow("CameraStream",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	//cout << "Press 'c' for one frame capture" << endl;
	while (1) {
		//Get the frame
		Mat frame;

		bool bSuccess = cap.read(frame); // read a new frame from video

	 	if (!bSuccess) //if not success, break loop
		{
	    		cout << "Cannot read a frame from video stream" << endl;
	    		break;
		}

		imshow("CameraStream", frame); //show the frame in "MyVideo" window

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
	    		cout << "esc key is pressed by user" << endl;
	    		break; 
		}
		/*if ((waitKey(0) == 67) || (waitKey(0) == 99)) {
			imwrite("captured_frame.jpg", frame);	
			cout << "Frame Captured" << endl;
		}*/
	}
	
	return 0;
}
