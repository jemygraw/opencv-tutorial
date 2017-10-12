import cv2

fname = '/Users/jemy/Documents/qiniu.png'
img = cv2.imread(fname)
cv2.namedWindow('Example5', cv2.WINDOW_AUTOSIZE)
cv2.imshow('Example5', img)
cv2.waitKey(0)
# shrink
imgOut = cv2.pyrDown(img)
cv2.imshow('Example5',imgOut)
cv2.waitKey(0)
# enlarge
imgOut = cv2.pyrUp(img)

cv2.imshow('Example5', imgOut)

cv2.waitKey(0)

cv2.resize(imgOut,(900,900))
cv2.imshow('Example5',imgOut)

cv2.waitKey(0)
cv2.destroyWindow('Example5')
