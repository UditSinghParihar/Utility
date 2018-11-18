class BankAccount(object):
	def __init__(self, amount = 0):
		self.amount = amount
 
	def is_negative_balance(self): 
		return self.amount < 0
 
my_account = BankAccount(100)
 
if my_account.is_negative_balance:
	print "Oh no, I owe %s!" % my_account.amount
else:
	print "Good, my finances are in tact."