import cv2
import threading
import queue

capture = None
updateQueue = queue.Queue()
curPos = 0


def onChange(pos):
    global curPos
    # add this check to avoid event-loopback
    if curPos != pos:
        print("onChange: frame " + str(pos))
        capture.set(cv2.CAP_PROP_POS_FRAMES, pos)
    pass


def updateTrackbar():
    while True:
        pos = updateQueue.get(block=True)
        global curPos
        curPos = pos
        cv2.setTrackbarPos('Trackbar1', 'Example3', pos)
        print("updateTracker: frame " + str(pos))
    pass


fname = '/Users/jemy/Documents/qiniu.mp4'
cv2.namedWindow('Example3', cv2.WINDOW_AUTOSIZE)
capture = cv2.VideoCapture(fname)
frameCount = int(capture.get(cv2.CAP_PROP_FRAME_COUNT))
print("frameCount: {0}".format(frameCount))
cv2.createTrackbar('Trackbar1', 'Example3', 0, frameCount, onChange)

t = threading.Thread(target=updateTrackbar)
t.start()

while True:
    if capture.grab():
        ret, frame = capture.retrieve()
        if ret:
            cv2.imshow('Example3', frame)
            pos = int(capture.get(cv2.CAP_PROP_POS_FRAMES))
            updateQueue.put(pos)
            ch = cv2.waitKey(20)
            if ch == 27:
                break
        else:
            break
    else:
        break

cv2.destroyWindow('Example2')
