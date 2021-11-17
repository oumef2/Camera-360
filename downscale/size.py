import cv2 
import numpy as np

def size(path):
    img = cv2.imread(path)
    img = cv2.resize(img,(1024,1024))
    cv2.imwrite(path,img)

size("1.jpg")
size("2.jpg")