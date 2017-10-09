//
// Created by jemy on 07/10/2017.
//

#include "examples.h"

void ex12_draw_image() {
    IplImage *image = cvCreateImage(cvSize(400, 400), IPL_DEPTH_8U, 4);
    cvLine(image, cvPoint(10, 10), cvPoint(100, 100), CV_RGB(100, 200, 131), 1, 1, 0);
    cvRectangle(image, cvPoint(100, 100), cvPoint(200, 200), CV_RGB(100, 200, 200), 1, 1, 0);
    cvNamedWindow("Example12", CV_WINDOW_AUTOSIZE);
    cvShowImage("Example12", image);
    cvReleaseImage(&image);
    cvWaitKey();
}