//
// Created by jemy on 03/10/2017.
//

#include "examples.h"

void ex10_alpha_merge() {

    const char *srcFile1 = "/Users/jemy/Temp/opencv/face.png";
    const char *srcFile2 = "/Users/jemy/Temp/opencv/face21.png";

    IplImage *src1, *src2;
    src1 = cvLoadImage(srcFile1, CV_LOAD_IMAGE_COLOR);
    src2 = cvLoadImage(srcFile2, CV_LOAD_IMAGE_COLOR);

    int srcX = 691;
    int srcY = 69;
    int srcWidth = 390;
    int srcHeight = 491;
    double alpha = 0;
    double beta = 1;

    int srcWidth2 = 390;
    int srcHeight2 = 491;
    cvSetImageROI(src1, cvRect(srcX, srcY, srcWidth, srcHeight));
    cvSetImageROI(src2, cvRect(0, 0, srcWidth2, srcHeight2));
    cvAddWeighted(src1, alpha, src2, beta, 0.0, src1);
    cvResetImageROI(src1);
    cvNamedWindow("Example10", CV_WINDOW_AUTOSIZE);
    cvShowImage("Example10", src1);
    cvWaitKey();
    return;
}
