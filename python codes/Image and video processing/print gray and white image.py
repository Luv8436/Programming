import cv2
img=cv2.imread("C:\\Users\\luvku\\CS 2019\\e yantra\\SB#423_Task0\\Task0.2\\Image Processing\\Images\\cat.jpg",1)
gray_img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
print('image diensions:',img.shape)
cv2.imshow("bird",gray_img)
cv2.imshow("bird",img)
cv2.waitKey(0)
cv2.destroyAllWindows()
