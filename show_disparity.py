import cv2 

disp = cv2.imread('data/disparity_map.pgm')
disp = cv2.normalize(disp, disp, alpha=255,
                              beta=0, norm_type=cv2.NORM_MINMAX)
                              
cv2.imwrite("data/disparity.png",disp)
cv2.imshow('disparity',disp)
cv2.waitKey(0) 