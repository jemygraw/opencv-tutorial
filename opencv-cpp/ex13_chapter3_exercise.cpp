//
// Created by jemy on 07/10/2017.
//

#include "examples.h"

void ex13_chapter3_exercise() {
    double n1 = -34.12;
    double n1x = fabs(n1);
    int n1xi = cvFloor(n1x);
    int n1xj = cvCeil(n1x);
    printf("%f\n", n1x);
    printf("%d\n", n1xi);
    printf("%d\n", n1xj);

    //create rand
    CvRNG rng = cvRNG(time(NULL));
    int randInt = cvRandInt(&rng);
    printf("%d\n", randInt);

    //covert point
    CvPoint2D32f p1 = cvPoint2D32f(32.11, 15.34);
    CvPoint p2 = cvPointFrom32f(p1);
    printf("%d, %d\n", p2.x, p2.y);

    //create matrix
    CvArr *img = cvCreateMat(100, 100, CV_8UC3);
    cvCircle(img, cvPoint(50, 50), 20, CV_RGB(125, 125, 125), 10, 1, 0);
    cvNamedWindow("Example13", CV_WINDOW_FREERATIO);
    cvShowImage("Example13", img);
    cvWaitKey(0);

    CvArr *img1 = cvCreateMat(100, 100, CV_8UC3);
    cvSetZero(img1);
    cvPtr2D(img1, 1, 1, 0);
    cvRectangle(img1, cvPoint(20, 5), cvPoint(40, 20), CV_RGB(0, 255, 0), 1, 1, 0);
    cvNamedWindow("Example13", CV_WINDOW_FREERATIO);
    cvShowImage("Example13", img1);
    cvWaitKey(0);
}