import cv2
import numpy as np
import matplotlib as plt
import matplotlib.pyplot as pl
import math


def histogramme2(img1,img2):
    dst = [[0]*255]*255
    p = 0
    q = 0
    for  i  in range (80) :
        for j in range (80):
            p = img1[i][j]
            q = img2[i][j]
            dst[p][q] +=1
    return dst


if __name__ == "__main__":
    image1 = cv2.imread("data1/1_left.pgm",0)
    image2 = cv2.imread("data1/2_right.pgm",0)
    hist = histogramme2(image1, image2)
    #calcule de l'entropy
    entropy = [[0]*80]*80
    entropy = np.array(entropy)
    for i in range(80) :
        for j in range(80):
            p = image1[i][j]
            q = image2[i][j]
            #print ( math.log2(hist[pixel]/6400) )
            entropy[i][j]= int(-math.log2(hist[p][q]/6400) *15)
    entropy = entropy.astype(np.uint8)
    cv2.imshow('entropy',entropy)
    cv2.waitKey(0) 
    

