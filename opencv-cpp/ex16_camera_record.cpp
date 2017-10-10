//
// Created by jemy on 10/10/2017.
//

#include "examples.h"

void ex16_camera_record() {
    //open the default camera
    CvCapture *capture = cvCreateCameraCapture(0);
    if (!capture) {
        printf("open camera failed");
        return;
    }

    cvNamedWindow("Example16", CV_WINDOW_AUTOSIZE);

    char outputFname[100];
    sprintf(outputFname,"/Users/jemy/Temp/output-%ld.m4v",time(NULL));
    int fourcc = CV_FOURCC('I', 'Y', 'U', 'V');
    double fps = 24;

    CvVideoWriter *writer = cvCreateVideoWriter(outputFname, fourcc, fps, cvSize(960, 640), 1);
    if (!writer) {
        printf("open writer failed");
        cvReleaseCapture(&capture);
        return;
    }
    while (1) {
        IplImage *frame = cvQueryFrame(capture);
        if (!frame) {
            continue;
        }

        cvShowImage("Example16", frame);

        IplImage *outFrame = cvCreateImage(cvSize(960, 640), IPL_DEPTH_8U, 3);
        cvResize(frame, outFrame);
        cvWriteFrame(writer, outFrame);
        cvReleaseImage(&outFrame);
        int key = cvWaitKey(1);
        if (key == 27) {
            break;
        }
    }

    cvReleaseVideoWriter(&writer);
    cvReleaseCapture(&capture);
    cvDestroyWindow("Example16");
}
