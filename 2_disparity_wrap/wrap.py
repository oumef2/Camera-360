import cv2 
import numpy as np


def wrap(img,disp):
    dst = img
    for i in range(80):
        for j in range(80):
            d = disp[i][j]
            if ( j + d < 80)  :
                dst[i][j] = img[i][j+d]
            else :  dst[i][j] = 255
    return dst


if __name__ == "__main__":
    image = cv2.imread("data1/1_right.pgm")
    disparity = cv2.imread("data1/0_disparity_map.pgm",0)
    cv2.imshow('image',image)
    wrapped =wrap(image,disparity)
    cv2.waitKey(0)
    
