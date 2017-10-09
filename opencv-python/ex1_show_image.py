import cv2

fname = '/Users/jemy/Documents/qiniu.png'
img = cv2.imread(fname, cv2.IMREAD_GRAYSCALE)
cv2.namedWindow('Example1', cv2.WINDOW_AUTOSIZE)
cv2.imshow('Example1', img)
cv2.waitKey(10000)
cv2.destroyWindow('Example1')
