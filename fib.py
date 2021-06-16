


if __name__ == '__main__':
	fib = []

	pFib = 1
	ppFib = 1

	n = 100
	cFib = -1

	for i in range(2, n):
		cFib = pFib + ppFib
		
		ppFib = pFib
		pFib = cFib

	print("Fibonacci: {} is {}".format(n, cFib))