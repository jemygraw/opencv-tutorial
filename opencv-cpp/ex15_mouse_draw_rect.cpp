//
// Created by jemy on 10/10/2017.
//

#include "examples.h"

//mouse callback template
void my_mouse_callback(int event, int x, int y, int flags, void *param);

CvRect box;
bool drawing_box = false;

void draw_box(IplImage *image, CvRect rect) {
    cvRectangle(image, cvPoint(box.x, box.y), cvPoint(box.x + box.width, box.y + box.height),
                cvScalar(0xff, 0x00, 0x00));
}

void ex15_mouse_draw_rect() {
    box = cvRect(-1, -1, 0, 0);

    IplImage *image = cvCreateImage(cvSize(2000, 200), IPL_DEPTH_8U, 3);
    cvSetZero(image);

    IplImage *temp = cvCloneImage(image);

    cvNamedWindow("Example15");
    cvSetMouseCallback("Example15", my_mouse_callback, (void *) image);

    while (1) {
        cvCopy(image, temp);
        if (drawing_box) {
            draw_box(temp, box);
        }

        cvShowImage("Example15", temp);
        if (cvWaitKey(15) == 27)break;
        printf("continue...");
    }

    cvReleaseImage(&image);
    cvReleaseImage(&temp);
    cvDestroyWindow("Example15");
}

void my_mouse_callback(int event, int x, int y, int flags, void *param) {
    IplImage *image = (IplImage *) param;
    switch (event) {
        case CV_EVENT_MOUSEMOVE:
            if (drawing_box) {
                box.width = x - box.x;
                box.height = y - box.y;
            }
            break;
        case CV_EVENT_LBUTTONDOWN:
            drawing_box = true;
            box = cvRect(x, y, 0, 0);
            break;
        case CV_EVENT_LBUTTONUP:
            drawing_box = false;
            if (box.width < 0) {
                box.x += box.width;
                box.width *= -1;
            }
            if (box.height < 0) {
                box.y += box.height;
                box.height *= -1;
            }
            printf("box: x: %d, y: %d, width: %d, height: %d\n", box.x, box.y, box.width, box.height);
            draw_box(image, box);
            break;
    }
}
