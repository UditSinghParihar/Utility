def pascal(k):
	prev, cur = [], []
	
	if(k == 0):
		return [1]
	if(k == 1):
		return [1, 1]

	prev = [1, 1]

	for j in range(2, k+1):
		cur = [1]

		for i in range(1, j):
			res = prev[i-1] + prev[i]
			cur.append(res)

		cur.append(1)

		prev = cur


	return cur
	
res = pascal(4)
print(res)