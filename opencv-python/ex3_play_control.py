import cv2
import threading

capture = None


def onChange(pos):
    print("frame:" + str(pos))
    capture.set(cv2.CAP_PROP_POS_FRAMES, pos)


fname = '/Users/jemy/Documents/qiniu.mp4'
cv2.namedWindow('Example3', cv2.WINDOW_AUTOSIZE)
capture = cv2.VideoCapture(fname)
frameCount = int(capture.get(cv2.CAP_PROP_FRAME_COUNT))
print("frameCount: {0}".format(frameCount))
cv2.createTrackbar('Trackbar1', 'Example3', 0, frameCount, onChange)
while True:
    if capture.grab():
        ret, frame = capture.retrieve()
        if ret:
            pos = int(capture.get(cv2.CAP_PROP_POS_FRAMES))
            cv2.imshow('Example3', frame)
            cv2.setTrackbarPos('Trackbar1', 'Example3', pos)
            ch = cv2.waitKey(25)
            if ch == 27:
                break
        else:
            break
    else:
        break

cv2.destroyWindow('Example2')
