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

    pl.hist(Hist, range = (0, 255), bins = 255, color = 'black',
            edgecolor = 'red')
    pl.xlabel('pixel')
    pl.ylabel('fréquence des pixels')
    pl.title('Histogramme Left Image')
    pl.show()
    return Hist




if __name__ == "__main__":
    image = cv2.imread("data1/2_right.pgm",0)
    hist = histogramme(image)
    #calcule de l'entropy
    entropy = [[0]*80]*80
    entropy = np.array(entropy)
    for i in range(80) :
        for j in range(80):
            pixel = image[i][j]
            #print ( math.log2(hist[pixel]/6400) )
            entropy[i][j]= int(-math.log2(hist[pixel]/6400) *15)
    entropy = entropy.astype(np.uint8)
    cv2.imshow('entropy',entropy)
    cv2.waitKey(0) 
    
