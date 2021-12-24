import cv2
import numpy as np
import matplotlib.pyplot as plt


block_size = 9
min_disp = 0
max_disp = 16
num_disp = max_disp - min_disp
uniquenessRatio = 5

speckleWindowSize = 200

speckleRange = 2
disp12MaxDiff = 0
imgL = cv2.imread('data/downscale_left.pgm') # downscale images for faster processing
imgR = cv2.imread('data/downscale_right.pgm')
cv2.imshow("Disparity", imgL)
cv2.waitKey(0) 

stereo = cv2.StereoSGBM_create(
    minDisparity=min_disp,
    numDisparities=num_disp,
    blockSize=block_size,
    uniquenessRatio=uniquenessRatio,
    speckleWindowSize=speckleWindowSize,
    speckleRange=speckleRange,
    disp12MaxDiff=disp12MaxDiff,
    P1=8 * 1 * block_size * block_size,
    P2=32 * 1 * block_size * block_size,
)
disparity = stereo.compute(imgL, imgR)

# Normalize the values to a range from 0..255 for a grayscale image
disparity_SGBM = cv2.normalize(disparity, disparity, alpha=255,
                              beta=0, norm_type=cv2.NORM_MINMAX)
disparity_SGBM = np.uint8(disparity_SGBM)
cv2.imshow("Disparity", disparity_SGBM)
cv2.waitKey(0) 
cv2.imwrite("disparity_img.pgm", disparity)
plt.colorbar()
plt.show()