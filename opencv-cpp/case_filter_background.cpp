//
// Created by jemy on 09/10/2017.
//

#include "examples.h"

void case_filter_background() {
    const char *fname = "/Users/jemy/Database/captcha-gongan/input/1507540969.jpg";
    IplImage *image = cvLoadImage(fname, CV_LOAD_IMAGE_GRAYSCALE);
    cvNamedWindow("Case1", CV_WINDOW_AUTOSIZE);
    cvShowImage("Case1", image);

    printf("src depth: %d\n", image->depth);
    printf("src color mode: %s\n", image->colorModel);
    printf("src channels: %d\n", image->nChannels);

    IplImage *hsvImage = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 3);
    cvCvtColor(image, hsvImage, CV_GRAY2BGR);

    cvShowImage("Case1", hsvImage);
    for (int i = 0; i < hsvImage->height; i++) {
        for (int j = 0; j < hsvImage->width; j++) {
            CvScalar ps = cvGet2D(hsvImage, i, j);
            //BGR
            printf("[%d %d] = %f, %f, %f\n", i, j, ps.val[0], ps.val[1], ps.val[2]);

            int blue = (int) ps.val[0];
            int green = (int) ps.val[1];
            int red = (int) ps.val[2];
            int limit = 145;
            if (blue > limit && green > limit & red > limit) {
                ps.val[0] = 255;
                ps.val[1] = 255;
                ps.val[2] = 255;
                cvSet2D(hsvImage, i, j, ps);
            }
        }
    }

    cvSaveImage("/Users/jemy/Temp/test.jpg", hsvImage);
    int step = (int) image->width / 4;
    int height = (int) image->height;

    for (int i = 0; i < 4; i++) {
        cvSetImageROI(hsvImage, cvRect(i * step, 0, step, height));
        char ouputFname[20];
        sprintf(ouputFname, "/Users/jemy/Temp/test%d.jpg", i);
        cvSaveImage(ouputFname, hsvImage);
    }
    cvShowImage("Case1", hsvImage);


    cvWaitKey(0);

    cvReleaseImage(&image);
    cvReleaseImage(&hsvImage);
}