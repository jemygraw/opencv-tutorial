//
// Created by jemy on 27/09/2017.
//

#include "examples.h"

void ex1_show_image() {
    IplImage *pInpImg = 0;

    // Load an image from file - change this based on your image name
    pInpImg = cvLoadImage("/Users/jemy/Documents/qiniu.png", CV_LOAD_IMAGE_GRAYSCALE);
    cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
    cvShowImage("Example1", pInpImg);
    cvWaitKey(0);
    if (!pInpImg) {
        fprintf(stderr, "failed to load input image\n");
        return;
    }

    // Write the image to a file with a different name,
    // using a different image format -- .png instead of .jpg
    if (!cvSaveImage("/Users/jemy/Temp/my_image_copy.png", pInpImg)) {
        fprintf(stderr, "failed to write image file\n");
    }

    // Remember to free image memory after using it!
    cvReleaseImage(&pInpImg);
    cvDestroyWindow("Example");
    return;
}
