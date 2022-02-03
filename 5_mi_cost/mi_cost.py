import cv2
import numpy as np
import matplotlib as plt
import matplotlib.pyplot as pl
import math


def histogramme(image):
  
    Hist = np.full(255, 0).tolist()
    print(image[0][5])

    for i in range(80):
        for j in range (80):
            a = image[i][j]  
            Hist[int(a)] += 1 

    return Hist


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
    hist1 = histogramme(image1)
    hist2 = histogramme(image2)
    hist12 = histogramme2(image1, image2)
    #calcule de l'entropy
    mi_cost = [[0]*80]*80
    mi_cost = np.array(mi_cost)

    for i in range(80) :
        for j in range(80):
            p = image1[i][j]
            q = image2[i][j]
            #print ( math.log2(hist[pixel]/6400) )
            h1 = -math.log2(hist1[p]/6400)
            h2 = -math.log2(hist2[q]/6400) 
            h12 = -math.log2(hist12[p][q]/6400)
            mi_cost[i][j] = ( h1 +h2 - h12) / 6400 *75000
    mi_cost = mi_cost.astype(np.uint8)
    cv2.imshow('cost',mi_cost)
    cv2.waitKey(0) 

    
   