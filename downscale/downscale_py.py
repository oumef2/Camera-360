import cv2 
import numpy as np

def downscale(img, optimal_size):
	downscaled_image = cv2.resize(img,(optimal_size,optimal_size))
	return downscaled_image


if __name__ == "__main__":
	#read image 
	image = cv2.imread("data/2.jpg",0)
	#image = downscale(image,1024)

	print(image.shape)

	#creat ppm image 
	width = image.shape[1]
	height = image.shape[0]
	maxval = 255

	# PPM header
	ppm_header = f'P2 {width} {height} {maxval}\n'

    # Save the PPM image as a binary file
	f= open('data/2_.pgm','wb')
	f.write(bytearray(ppm_header, 'ascii'))
	for i in range(image.shape[0]):
		for j in range(image.shape[1]):
			f.write(bytearray(f'{str(image[i][j])}\n','ascii'))	
	f.close()

	#downscaled image with openCV
	cv2.imshow('downscaled',downscale(image, 80))
	cv2.imshow('original',image)
	cv2.waitKey(0) 
