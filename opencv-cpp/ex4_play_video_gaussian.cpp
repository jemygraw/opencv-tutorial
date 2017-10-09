//
// Created by jemy on 30/09/2017.
//

#include "examples.h"

void ex4_play_video_gaussian() {
    const char *video_file = "/Users/jemy/Documents/qiniu.mp4";
    cvNamedWindow("Example4", CV_WINDOW_AUTOSIZE);
    CvCapture *capture = cvCreateFileCapture(video_file);
    IplImage *frame;
    while (1) {
        frame = cvQueryFrame(capture);
        if (!frame) {
            break;
        }

        IplImage *frameOut = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
        cvSmooth(frame, frameOut, CV_GAUSSIAN, 27, 27);
        cvShowImage("Example4", frameOut);
        cvReleaseImage(&frameOut);
        int c = cvWaitKey(25);
        if (c == 27) {
            break;
        }
    }

    cvReleaseCapture(&capture);
    cvDestroyWindow("Example5");
}