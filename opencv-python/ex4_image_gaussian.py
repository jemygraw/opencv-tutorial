import cv2

fname = '/Users/jemy/Documents/qiniu.png'
img = cv2.imread(fname, cv2.IMREAD_GRAYSCALE)
imgOut = cv2.GaussianBlur(img, (11, 11), 12)
cv2.namedWindow('Example4', cv2.WINDOW_AUTOSIZE)
cv2.imshow('Example4', imgOut)
cv2.waitKey(0)

cv2.destroyWindow('Example4')
