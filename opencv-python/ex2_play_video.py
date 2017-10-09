import cv2

fname = '/Users/jemy/Documents/qiniu.mp4'
cv2.namedWindow('Example2', cv2.WINDOW_AUTOSIZE)
capture = cv2.VideoCapture(fname)
index = 0
while True:
    if capture.grab():
        ret, frame = capture.retrieve()
        if ret:
            cv2.imshow('Example2', frame)
            #snap_fname = '/Users/jemy/Temp/snapshots/snap_{0}.jpg'.format(index)
            #cv2.imwrite(snap_fname, frame)
            #index += 1
            ch = cv2.waitKey(25)
            if ch == 27:
                break
        else:
            break
    else:
        break

cv2.destroyWindow('Example2')
