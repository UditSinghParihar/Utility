def printStars(num):
	for i in range(num):
		print("*", end='')


def spaceStars(row, rows):
	spaces = rows - row - 1

	for i in range(spaces):
		print(" ", end='')
	print("*", end='')


def	main(rows):
	for i in range(rows):
		if(i == 0 or i == rows-1):
			printStars(rows)
			print()
		else:
			spaceStars(i, rows)
			print()


if __name__ == '__main__':
	rows = int(input())

	main(rows)