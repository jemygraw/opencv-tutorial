import cv2
import time

cv2.namedWindow("Example7")
cameraIndex = 0
fname = '/Users/jemy/Temp/opencv-camera-{0}.m4v'.format(int(time.time()))
capture = cv2.VideoCapture(cameraIndex)
fps = 25
frameSize = (960, 720)
fourcc = cv2.VideoWriter_fourcc('M', 'J', 'P', 'G')
writer = cv2.VideoWriter(fname, fourcc, fps, frameSize, True)
while True:
    if capture.grab():
        ret, frame = capture.retrieve()
        if ret:
            outFrame = cv2.resize(frame, frameSize)
            cv2.imshow("Example7", outFrame)
            writer.write(outFrame)
    key = cv2.waitKey(40)
    if key == 27:
        break
cv2.destroyWindow("Example7")
