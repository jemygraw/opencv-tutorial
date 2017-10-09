import cv2

fname = '/Users/jemy/Documents/qiniu.png'
img = cv2.imread(fname, cv2.CAP_MODE_GRAY)
cv2.namedWindow('Example5', cv2.WINDOW_AUTOSIZE)
cv2.imshow('Example5', img)
# shrink
imgOut = cv2.pyrDown(img)
# enlarge
imgOut = cv2.pyrUp(img)

cv2.imshow('Example5', imgOut)

cv2.waitKey(0)
cv2.destroyWindow('Example5')
