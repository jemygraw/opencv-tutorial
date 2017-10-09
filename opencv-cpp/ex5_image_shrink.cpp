//
// Created by jemy on 30/09/2017.
//

#include "examples.h"

void ex5_shrink_image() {
    IplImage *pInpImg = NULL;
    pInpImg = cvLoadImage("/Users/jemy/Documents/qiniu.png",
                          CV_LOAD_IMAGE_GRAYSCALE);
    cvNamedWindow("Example5", CV_WINDOW_AUTOSIZE);

    //doPyrDown
    int width = pInpImg->width * 2;
    int height = pInpImg->height * 2;
    IplImage *out = cvCreateImage(cvSize(width, height), pInpImg->depth,
                                  pInpImg->nChannels);
    //shrink
    //cvPyrDown(pInpImg, out);

    //enlarge
    cvPyrUp(pInpImg, out);
    cvShowImage("Example5", out);

    cvWaitKey(0);
    cvReleaseImage(&out);
    cvReleaseImage(&pInpImg);
    cvDestroyWindow("Example");
    return;
}

void ex5_do_canny() {
    IplImage *pInpImg = NULL;
    pInpImg = cvLoadImage("/Users/jemy/Temp/opencv/face.png",
                          CV_LOAD_IMAGE_GRAYSCALE);
    //do canny
    printf("Channles: %d\n", pInpImg->nChannels);
    if (pInpImg->nChannels != 1) {
        printf("invalid channels");
        return;
    }

    IplImage *out = cvCreateImage(cvGetSize(pInpImg), IPL_DEPTH_8U, 1);
    cvCanny(pInpImg, out, 0, 10, 3);

    cvShowImage("Example5", out);
    cvWaitKey(0);
    cvReleaseImage(&pInpImg);
    cvDestroyWindow("Example5");
    return;
}