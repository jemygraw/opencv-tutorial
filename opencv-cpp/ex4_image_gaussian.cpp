//
// Created by jemy on 30/09/2017.
//

#include "examples.h"

void ex4_image_gaussian() {
    const char *fname = "/Users/jemy/Documents/qiniu.png";
    IplImage *image = cvLoadImage(fname);

    cvNamedWindow("Example4-in");
    cvNamedWindow("Example4-out");

    cvShowImage("Example4-in", image);

    //gaussian
    IplImage *outImage = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 3);
    cvSmooth(image, outImage, CV_GAUSSIAN, 27, 27);
    cvShowImage("Example4-out", outImage);

    cvReleaseImage(&outImage);
    cvReleaseImage(&image);

    cvWaitKey(0);
    cvDestroyWindow("Example4-in");
    cvDestroyWindow("Example4-out");
}