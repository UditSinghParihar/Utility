import random
from sys import exit

# hang() takes two input
# word is the random selected word from random.choice()
# predict is the current predicted list
def hang(word, predict):

	# raw_input does not require input to be in ''. 
	ab = raw_input("Enter a letter in a word: ")
	
	result = False

	if ab in word:
		result = True

		# Store indexes of all occurences of letter ab
		list1=[]

		# Finding all the occureces of letter ab
		for i in range(len(word)):
			if(ab == word[i]):
				list1.append(i)
			
		for j in range(len(list1)):
			d=list1[j]
			predict[d] = ab
	
	return (result, predict)


def main(words):
	print("You have 3 lifes. \nOn correct prediction, you can continue.")
	print("On every wrong prediction, one life will go down. \nHahaha!!!\n\n")
	
	word=random.choice(words)
	print("Correct word is %s\n" % word)

	life = 3; win = False

	# Empty list equal to length of the original word 
	predict = [""]*len(word)

	# Continue looping, till all life got exhausted or player has correctly predicted the word
	while((life > 0) and (win==False)):
		(res, predict) = hang(word, predict)
		print(predict)

		if(res == False):
			life = life -1

		curWord = "".join(predict)
		if(curWord == word):
			win = True

	if(life == 0):
		print("\nGet Lost!!! \nYou Loser.")
	elif(win == True):
		print("\nCongrats!!! \nYou win")


if __name__ == '__main__':
	words=['rings' , 'obesity' , 'right' , 'whisper' , 'paper' , 'made' , 'unlock' ,\
	'creator' , 'excuse' , 'chess' , 'berry' , 'partner' ]

	main(words)