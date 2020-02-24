import cv2
face_cascade=cv2.cascadeClassifier("C:\\Users\\luvku\\CS 2019\\task0#sb (1)\\Task0.2\\Image Processing\\Images\\bird.jpg")
img=cv2.imread("C:\\Users\\luvku\\CS 2019\\task0#sb (1)\\Task0.2\\Image Processing\\Images\\bird.jpg",1)
gray_img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
faces=face_cascade.detectMultiScale(gray_img,scaleFactor_=_1,minNeighbors=5)
print(type(faces))
print(faces)
for x,y,w,h in faces:
img=cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),3)
cv2.imshow("bird",img)
cv2.waitKey(0)
cv2.destroyAllWindows()
