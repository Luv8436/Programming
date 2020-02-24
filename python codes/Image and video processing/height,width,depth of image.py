import cv2
img=cv2.imread(r'C:\Users\luvku\CS 2019\e yantra\SB#423_Task0\Task0.2\Image Processing\Images\bird.jpg',1)
shape = img.shape
print("height = ",shape[0])
print("width = ",shape[1])
print("depth = ",shape[2])
