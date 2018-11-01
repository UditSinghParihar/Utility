import numpy as np

def main():
	a = np.arange(15).reshape(3, 5)
	print a.size, a.shape, a.dtype
	b = np.array([(1,2,3),(4,5,6)])
	print b, b.shape
	c = np.ones((2,3,4))
	print c, c.shape
	print b.max()


if __name__ == '__main__':
	main()
