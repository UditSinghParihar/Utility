import numpy as np
import math


if __name__ == '__main__':
	# thetaX = math.radians()
	thetaY = math.radians(90)
	thetaZ = math.radians(-90)

	# Rx = np.array([[1, 0, 0], [0, math.cos(thetaX), -math.sin(thetaX)], [0, math.sin(thetaX), math.cos(thetaX)]])
	Ry = np.array([[math.cos(thetaY), 0, math.sin(thetaY)], [0, 1, 0], [-math.sin(thetaY), 0, math.cos(thetaY)]])
	Rz = np.array([[math.cos(thetaZ), -math.sin(thetaZ), 0], [math.sin(thetaZ), math.cos(thetaZ), 0], [0, 0, 1]])

	Tc_w = np.identity(4)
	Tc_w[0:3, 0:3] = Rz @ Ry
	Tc_w[0, 3] = 0
	Tc_w[1, 3] = 2
	Tc_w[2, 3] = -10

	pw = np.array([20, -3, 5, 1]).reshape(4, 1)

	print(Tc_w)
	print(Tc_w @ pw)