//
// Created by jemy on 09/10/2017.
//

#include "examples.h"

void ex14_image_read(){
    const char *fname="/Users/jemy/Pictures/blueskye.jpg";
    IplImage *image=cvLoadImage(fname,CV_LOAD_IMAGE_UNCHANGED|CV_LOAD_IMAGE_ANYDEPTH);
    printf("src depth: %d\n", image->depth);
    printf("src color mode: %s\n", image->colorModel);
    printf("src channels: %d\n", image->nChannels);
    cvNamedWindow("Example14",CV_WINDOW_FREERATIO);
    cvShowImage("Example14",image);
    cvReleaseImage(&image);
    cvDestroyWindow("Example14");
    cvWaitKey(0);
}