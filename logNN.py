import torch
import torch.nn as nn
import torch.nn.functional as F
from torch import optim


import numpy as np
import math


def genData():
	Y = np.arange(-10, 10, 0.0001)
	E = 2.71

	np.random.shuffle(Y)

	X = E**Y

	return X, Y


class logNN(nn.Module):
	def __init__(self):
		super(logNN, self).__init__()
		
		self.W1 = nn.Linear(1, 1000)
		self.W2 = nn.Linear(1000, 100)
		self.W3 = nn.Linear(100, 1)

		self.relu = nn.ReLU()

	def forward(self, x):
		z1 = self.W1(x)
		a1 = self.relu(z1)
		z2 = self.W2(a1)
		a2 = self.relu(z2)
		z3 = self.W3(a2)

		return z3		


if __name__ == '__main__':
	X, Y = genData()

	device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

	numbOfEpocs = 500
	miniBatch = 200

	XTorch = torch.tensor(X).float().view(-1, 1).to(device)
	YTorch = torch.tensor(Y).float().view(-1, 1).to(device)

	print(XTorch.shape)

	model = logNN().to(device)

	criterion = nn.MSELoss()
	optimizer = optim.Adam(filter(lambda p: p.requires_grad, model.parameters()), lr=0.003)


	for i in range(numbOfEpocs):
		runningLoss = 0
		for j in range(0, X.shape[0]-miniBatch, miniBatch):
			optimizer.zero_grad()

			XBatch = XTorch[j: j+miniBatch, 0].view(-1, 1)
			YBatch = YTorch[j: j+miniBatch, 0].view(-1, 1)

			out = model(XBatch)

			loss = criterion(out, YBatch)
			

			loss.backward()
			optimizer.step()

			runningLoss += loss.item()
		
		print("{} Loss: {}".format(i, runningLoss))