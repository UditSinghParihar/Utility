class Cluster:
	index = 1

	def __init__(self, value):
		self.value = value
		self.no = Cluster.index
		Cluster.index += 1

def main():
	first = Cluster(2)
	second = Cluster(10)
	third = Cluster(100)

	print(third.value, third.index, second.index, first.index)
	print(first.no, second.no, third.no)

if __name__ == '__main__':
	main()
		