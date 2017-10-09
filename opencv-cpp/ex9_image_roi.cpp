//
// Created by jemy on 01/10/2017.
//

#include "examples.h"

void ex9_image_roi() {
    IplImage *img = 0;
    img = cvLoadImage("/Users/jemy/Temp/opencv/face.png");
    cvNamedWindow("Example9", CV_WINDOW_AUTOSIZE);

    printf("width: %d, height: %d\n", img->width, img->height);

    int roiX = 600;
    int roiY = 200;
    int width = 400;
    int height = 400;
    int blue = 150;
    int green = 150;
    int red = 150;
    cvSetImageROI(img, cvRect(roiX, roiY, width, height));
    cvAddS(img, cvScalar(blue, green, red), img);

    cvResetImageROI(img);
    cvShowImage("Example9", img);
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvDestroyWindow("Example9");


    return;
}