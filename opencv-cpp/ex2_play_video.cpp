//
// Created by jemy on 27/09/2017.
//

#include "examples.h"

void ex2_play_video() {
    const char *video_file = "/Users/jemy/Documents/qiniu.mp4";
    cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
    CvCapture *capture = cvCreateFileCapture(video_file);
    IplImage *frame;
    while (1) {
        frame = cvQueryFrame(capture);
        if (!frame) {
            break;
        }

        cvShowImage("Example2", frame);
        int c = cvWaitKey(33);
        if (c == 27) {
            break;
        }
    }
    cvReleaseCapture(&capture);
    cvDestroyWindow("Example2");
}

void ex2_play_video_capture() {
    const char *video_file = "/Users/jemy/Documents/qiniu.mp4";
    CvCapture *capture = cvCreateFileCapture(video_file);
    IplImage *frame;
    char fname[20];
    int i = 1;
    while (1) {
        frame = cvQueryFrame(capture);
        if (!frame) {
            break;
        }

        sprintf(fname, "/Users/jemy/Temp/snapshots/snapshot_%d.jpg", i);
        cvSaveImage(fname, frame);
        i++;
    }
}