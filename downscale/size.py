import cv2 
import numpy as np

def size(path):
    img = cv2.imread(path)
    img = cv2.resize(img,(320,240))
    cv2.imwrite(path,img)

size("data/1.jpg")
size("data/2.jpg")