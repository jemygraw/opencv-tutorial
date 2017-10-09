import cv2

fname = '/Users/jemy/Documents/qiniu.mp4'
cv2.namedWindow('Example2', cv2.WINDOW_AUTOSIZE)
capture = cv2.VideoCapture(fname)
index = 0
while True:
    if capture.grab():
        ret, frame = capture.retrieve()
        if ret:
            frameOut = cv2.GaussianBlur(frame, (131, 131), 3)
            cv2.imshow('Example2', frameOut)
            ch = cv2.waitKey(25)
            if ch == 27:
                break
        else:
            break
    else:
        break

cv2.destroyWindow('Example2')
