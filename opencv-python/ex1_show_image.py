import cv2

fname = '/Users/jemy/Documents/qiniu.png'
img = cv2.imread(fname, cv2.IMREAD_GRAYSCALE)
cv2.namedWindow('Example1', cv2.WINDOW_AUTOSIZE)
cv2.imshow('Example1', img)
while True:
    val = cv2.waitKey(1000)
    if val == 27:
        break
cv2.destroyWindow('Example1')
