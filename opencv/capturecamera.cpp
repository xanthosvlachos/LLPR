#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	int i = 0;
	while(1) {
		VideoCapture cap(i); // open the video camera no. 0

		if (!cap.isOpened()) { // if not success, exit program
		    cout << "Cannot open the video cam no." << i << endl;
		    i++;
		}
		else if (i >= 5) {
		    cout << "Failed to open any of the video cams" << endl;
		    return -1;
		}
		else {
		    cout << "Successfully opened the video cam no." << i << endl;
		    break;
		}
	}
    
   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    cout << "Frame size : " << dWidth << " x " << dHeight << endl;

    namedWindow("CameraStream",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    while (1)
    {
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
    }
    return 0;

}