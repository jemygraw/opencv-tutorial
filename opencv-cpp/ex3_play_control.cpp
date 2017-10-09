#include "examples.h"

int g_slider_position = 0;
CvCapture *g_capture = NULL;

void onTrackbarSlide(int pos) {
    printf("slide position: %d\n", pos);
    cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
}

void ex3_play_control() {
    const char *video_file = "/Users/jemy/Documents/qiniu.mp4";
    cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);
    g_capture = cvCreateFileCapture(video_file);
    int frames = (int) cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);
    printf("total frames: %d\n", frames);
    if (frames != 0) {
        cvCreateTrackbar(
                "Position",
                "Example3",
                &g_slider_position,
                frames,
                onTrackbarSlide
        );
    }

    //这段逻辑在Mac上面很慢
    IplImage *frame;
    while (1) {
        frame = cvQueryFrame(g_capture);
        if (!frame) {
            break;
        }

        g_slider_position = (int) cvGetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES);
        printf("playing frame: %d\n", g_slider_position);

        //cvSetTrackbarPos("Position", "Example3", g_slider_position);
        cvShowImage("Example3", frame);

        int c = cvWaitKey(1);
        if (c == 27) {
            break;
        }
    }

    cvReleaseCapture(&g_capture);
    cvDestroyWindow("Example3");
}