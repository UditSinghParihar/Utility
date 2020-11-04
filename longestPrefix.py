def longestCommonPrefix(strs):
	numStrings = len(strs)

	if(numStrings == 0):
		return ""
	if(numStrings == 1):
		return strs[0]

	# for i in range(1, numStrings):
	numChar = 0
	for i in range(1, len(strs[0])+1):
		numWords = 0
		for j in range(1, numStrings):  
			# print("{} in {}: {}".format(strs[0][0:i], strs[j], strs[0][0:i] in strs[j][0:i]))
			if(strs[0][0:i] in strs[j][0:i]):
				numWords += 1
		if(numWords == numStrings-1):
			# print("True")
			numChar += 1

	if(numChar == 0):
		return ""
	else:
		return strs[0][0:numChar]
	# print("{}".format(strs[0][0:numChar]))



print(longestCommonPrefix(["flower","flow","flight"]))
print(longestCommonPrefix(["dog","racecar","car"]))
print(longestCommonPrefix(["a"]))
print(longestCommonPrefix(["flower","flower","flower","flower"]))
print(longestCommonPrefix(["c","acc","ccc"]))