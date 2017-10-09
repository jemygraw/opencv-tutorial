//
// Created by jemy on 30/09/2017.
//

#include "examples.h"

void ex8_saturate_sv() {
    IplImage *img = 0;

    img = cvLoadImage("/Users/jemy/Temp/opencv/face.png");
    cvNamedWindow("Example8", CV_WINDOW_AUTOSIZE);

    for (int y = 0; y < img->height; y++) {
        uchar *ptr = (uchar *) img->imageData + y * img->widthStep;
        for (int x = 0; x < img->width; x++) {
            printf("%d,%d,%d\n", ptr[3 * x], ptr[3 * x + 1], ptr[3 * x + 2]);
            ptr[3 * x + 1] = 255;
            ptr[3 * x + 2] = 255;
        }
    }

    cvShowImage("Example8", img);
    cvWaitKey(0);
    cvReleaseImage(&img);
    cvDestroyWindow("Example8");
    return;
}
