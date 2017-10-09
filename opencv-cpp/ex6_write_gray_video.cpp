//
// Created by jemy on 30/09/2017.
//

#include "examples.h"

void ex6_write_gray_video() {
    const char *fname = "/Users/jemy/Documents/qiniu.mp4";
    const char *fnameOut = "/Users/jemy/Temp/opencv/qiniu_gray.mp4";
    CvCapture *capture = NULL;
    capture = cvCreateFileCapture(fname);
    if (!capture) {
        return;
    }

    IplImage *bgrFrame = cvQueryFrame(capture);
    double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
    int width = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
    int height = (int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
    CvSize size = cvSize(width, height);

    CvVideoWriter *writer = cvCreateVideoWriter(fnameOut,
                                                CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
    IplImage *logPolarFrame = cvCreateImage(size, IPL_DEPTH_8U, 3);
    while ((bgrFrame = cvQueryFrame(capture)) != NULL) {
        cvLogPolar(bgrFrame, logPolarFrame,
                   cvPoint2D32f(bgrFrame->width / 2, bgrFrame->height / 2), 90,
                   CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
        cvWriteFrame(writer, logPolarFrame);
    }

    cvReleaseVideoWriter(&writer);
    cvReleaseImage(&logPolarFrame);
    cvReleaseCapture(&capture);
    return;
}