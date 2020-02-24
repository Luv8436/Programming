import cv2
img=cv2.imread(r"C:\Users\luvku\CS 2019\e yantra\SB#423_Task0\Task0.2\Image Processing\Images\bird.jpg",1)
resized=cv2.resize(img,(720,720))
cv2.imshow("bird",resized)
cv2.waitKey(0)
cv2.destroyAllWindows()
