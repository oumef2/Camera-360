import cv2 
import numpy as np
#since the code is not tested on images that are actualy taken by a raspberry pi camera 
#we need to resize our input images and grayscale them to the right input goven by the fpga 

def size(path):
    img = cv2.imread(path)
    img = cv2.resize(img,(320,240))
    cv2.imwrite(path,img)

size("../data/left.jpg")
size("../data/right.jpg")