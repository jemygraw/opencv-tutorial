import cv2

fname = '/Users/jemy/Documents/github-avatar.png'
img = cv2.imread(fname, cv2.CAP_MODE_GRAY)
cv2.namedWindow('Example6', cv2.WINDOW_AUTOSIZE)
cv2.imshow('Example6', img)
# canny

imgOut = cv2.Canny(img, 0, 100)

cv2.imshow('Example6', imgOut)

cv2.waitKey(0)
cv2.destroyWindow('Example6')
