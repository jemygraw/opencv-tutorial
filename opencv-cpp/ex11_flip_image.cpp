//
// Created by jemy on 07/10/2017.
//

#include "examples.h"

void ex11_flip_image(){
    const char *fname="/Users/jemy/Documents/golang_100x100.png";
    IplImage *image=cvLoadImage(fname);
    if(!image){
        return;
    }

    cvFlip(image,image,1);
    cvNamedWindow("Example11",CV_WINDOW_AUTOSIZE);
    cvShowImage("Example11",image);
    cvWaitKey(0);
}