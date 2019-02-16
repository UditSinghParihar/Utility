import numpy as np
import cv2
import sys
import pptk

def main():
	depth = cv2.imread(sys.argv[1], cv2.CV_16UC1)
	
	K = np.array([ [210, 0, 128],
					[0, 278.25, 127.2],
					[0, 0, 1]])

	# K = np.array([ [570.3, 0, 320.0],
	# 				[0, 570.3, 240.0],
	# 				[0, 0, 1]])

	depth = np.float32(depth)
	depth_matrix = cv2.rgbd.depthTo3d(depth, K)

	print("shape of depth_matrix: ", depth_matrix.shape)
	print("some value: ", depth_matrix[34, 112])

	pptk.viewer(depth_matrix)

if __name__ == '__main__':
	main()