import numpy as np

class Class1(object):
	"""docstring for Class1"""
	def __init__(self):
		super(Class1, self).__init__()
		# arg = 'hello'
		self.arg = 5
		
	def printArg(self):
		print('arg:', self.arg)

if __name__ == '__main__':
	obj = Class1()
	obj.printArg()

	preds = np.array([0.4, 0.9, 0.3, 0.1, 0.85, 0.67])
	print(np.where(preds >= 0.5, 1, 0))