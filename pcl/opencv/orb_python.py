import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt

img = cv.imread("/home/udit/Pictures/warning.png", 0)
orb = cv.ORB_create()
kp = orb.detect(img, None)
kp, des = orb.compute(img, kp)

img2 = cv.drawKeypoints(img, kp, None, color=(0, 255, 0), flags=0)
