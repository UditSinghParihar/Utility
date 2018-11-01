import numpy as np
import math
import matplotlib.pyplot as plt
import time
import sys

from misc_tools import *

def find_dist(Px, Py, Xx, Xy):
  return math.sqrt((math.pow(Px - Xx, 2) + math.pow(Py - Xy, 2)))

def closest_point_matching(X, P):
  """
  Performs closest point matching of two point sets.
  
  Arguments:
  X -- reference point set
  P -- point set to be matched with the reference
  
  Output:
  P_matched -- reordered P, so that the elements in P match the elements in X
  """
  P_matched = np.copy(P)
  unmatched = [1 for i in xrange(16)]
  vector = [0, 15, 1, 14, 2, 13, 3, 12, 4, 11, 5, 10, 6, 9, 7, 8]
  for i in vector:
    min_value = 100000
    min_index = 0
    for j in xrange(0, 16):
      dist = find_dist(P[0][j], P[1][j], X[0][i], X[1][i])
      if dist < min_value and unmatched[j]:
        min_value = dist
        min_index = j
    unmatched[min_index] = 0
    P_matched[0][i] = P[0][min_index]
    P_matched[1][i] = P[1][min_index] 
  # TODO: implement

  return P_matched
  
def icp(X, P, do_matching):
  
  P0 = P  
  for i in range(250):  
    # calculate RMSE
    rmse = 0
    for j in range(P.shape[1]):
      rmse += math.pow(P[0,j] - X[0,j], 2) + math.pow(P[1,j] - X[1,j], 2)
    rmse = math.sqrt(rmse / P.shape[1])

    # print and plot
    print("Iteration:", i, " RMSE:", rmse)
    plot_icp(X, P, P0, i, rmse)
    if rmse < 0.1:
      return

    # data association
    if do_matching:
      P = closest_point_matching(X, P)
    if (i%15 == 0 and i != 0):
      P = np.random.permutation(P.T).T

    # substract center of mass
    mx = np.transpose([np.mean(X, 1)])
    mp = np.transpose([np.mean(P, 1)])
    X_prime = X - mx
    P_prime = P - mp
    
    # singular value decomposition
    W = np.dot(X_prime, P_prime.T)
    U, s, V = np.linalg.svd(W)
    
    # calculate rotation and translation
    R = np.dot(U, V.T)
    t = mx - np.dot(R, mp)
    
    # apply transformation
    P = np.dot(R, P) + t

  return
    
def main():
  
  X, P1, P2, P3, P4 = generate_data()
  
  #icp(X, P1, False)
  #icp(X, P2, False)
  icp(X, P3, True)
  # icp(X, P4, True)

  plt.waitforbuttonpress()
    
if __name__ == "__main__":
  main()
