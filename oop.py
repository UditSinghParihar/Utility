def namedTupleTest():
	from collections import namedtuple
	# Declaring namedtuple() 
	# Student = collections.namedtuple('Student',['name','age','DOB'])

	# Student.__annotations__ = {'name' : "Udit",'age': 23,'DOB': 18081996}
	# S = Student
	# # Adding values 
	# # S = Student('Nandini','19','2541997') 
	  
	# # Access using index 
	# print("The Student age using index is : ", end ="") 
	# print(S[1]) 

	# # Access using name  
	# print ("The Student name using keyname is : ", end ="") 
	# print (S.name) 

	# # Access using getattr() 
	# print ("The Student DOB using getattr() is : ", end ="") 
	# print (getattr(S,'DOB')) 

	n1 = namedtuple('person', ['name', 'age'])
	n1.__annotations__ = {'name' : 'Udit', 'age': 23}
	n2 = n1('Manas', 14)
	print(n2.name, n2.age)
	print(n1.__annotations__)

def shortners():
	def argFun():
		def myFun(*argv):
			for arg in argv:
				print(arg, type(arg))

		myFun('hello', 123, "udit", 12)

		def keyFun(arg1, **kwargs):
			print("Argument 1: ", arg1)

			for key, value in kwargs.items():
				print("%s => %s" % (key, value))

		keyFun('its', name='peter', age=23, dob=18081996)

	def twice(num):
		return 2*num

	tup1 = (1, 10, 11, -25, 14, 27)
	tup2 = (2, 2, 2, 2)

	print(list(map(twice, tup1)))
	print(list(map(lambda x : x**2, tup1)))
	print(list(map(lambda x, y : x+y, tup1, tup2)))
	print(list('abc'))


	def test(var):
		letters = ['a', 'e', 'i', 'o', 'u']
		if(var in letters):
			return True
		else:
			return False

	tup3 = ['g', 'e', 'x', 'a']
	filtered = filter(test, tup3)
	print(list(filtered))

	print(list(filter(lambda x : x%2 == 0, tup1)))


def fun3():
	from functools import reduce

	tup4 = [72, 3, 2]

	r"""
	Hello
	"""

	print(reduce(lambda x, y : x/y, tup4))

	classObj = list()
	print(type(classObj))

	class ClassName(object):
		"""docstring for ClassName"""
		def __init__(self, arg):
			super(ClassName, self).__init__()
			self.arg = arg

	obj = ClassName(2)
	print(type(obj), '\t', type(ClassName))


	print("Hello, {name} ! My age {age}".format(name="Udit", age=23))

	# name = "alex"; age = 18
	# print(f"{name}")


	class Vector(object):
		"""docstring for Vector"""
		def __init__(self, x, y):
			self.x = x
			self.y = y

		def __str__(self):
			return "{}i + {}j".format(self.x, self.y)

	v1 = Vector(3, 4)
	print(v1)

def fun4():
	class Duck(object):
		"""docstring for Duck"""
		def readline(self):
			return "quack"

	def readTen(obj):
		for i in range(10):
			x = obj.readline()
			print("{} = {}".format(i, x))

	readTen(Duck())

	print(type(readTen), type(int), type(Duck()))
	print(Duck.__doc__)

	class Dog(object):
		"""docstring for Dog"""
		
		species = "mammal"

		def __init__(self, arg):
			super(Dog, self).__init__()
			self.name = arg

	d1 = Dog("Tommy")
	print(d1.name, Dog.species)

	class Pub(Dog):
		"""docstring for Dog"""
		def __init__(self, arg):
			super().__init__("mangoDog")
			self.age = arg

	p1 = Pub(18)
	print(p1.name, p1.age)
		
	class Rectangle(object):
		"""docstring for Rectangle"""
		def __init__(self, leng, width):
			self.width = width
			self.leng = leng
			
		def area(self):
			return self.width * self.leng

	class Square(Rectangle):
		"""docstring for Square"""
		def __init__(self, leng):
			super().__init__(leng, leng)


	class Square2(Rectangle):
		"""docstring for Square2"""
		# def __init__(self, arg):
		# 	self.arg = arg
		def perimeter(self):
			return 2*(self.width+self.leng)
			

	sq1 = Square(6)
	print(sq1.area())
	print("Area: {}".format(sq1.area()))
		
	sq2 = Square2(5, 10)
	print("Area: {} and Perimeter: {}".format(sq2.area(), sq2.perimeter()))


class Car(object):
	"""docstring for Car"""
	def __init__(self, name, model):
		self._name = name
		self._model = model

	@property
	def name(self):
		return self._name
	
	@name.setter
	def name(self, name):
		self._name = name

	@property
	def model(self):
		return self._model

	@model.setter
	def model(self, model):
		self._model = model

c1 = Car("Swift", 2019)

print(c1.name, c1.model)
c1.name = "Swift VXI"
c1.model = 2020
print(c1.name, c1.model)

def sayHello(name):
	print("Hello {}".format(name))

def greet(greeterFun):
	greeterFun("Bob")

greet(sayHello)


def myDecorator(func):
	def wrapper():
		print("Someting before func.")
		func()
		print("Someting after func.")

	return wrapper

@myDecorator
def sayWhee():
	print("Wheee!")

sayWhee()


import functools
import time

def timer(func):
	@functools.wraps(func)
	def wrapperTimer(*args, **kwargs):
		start = time.perf_counter()
		value = func(*args, **kwargs)
		end = time.perf_counter()
		print("Finished {} in {} seconds.".format(func.__name__, end-start))
		return value

	return wrapperTimer

@timer
def squares(numTimes):
	res = 0
	for _ in range(numTimes):
		res = sum([i**2 for i in range(10000)])

	return res

value = squares(1)
print(value)


from collections import OrderedDict

od = OrderedDict()
od['a'] = -3
od['b'] = 5
od['c'] = 1

od2 = dict(od)

for key, value in od.items():
	print(key, value)

for key, value in od2.items():
	print(key, value)

def printSeq(*args):
	for e in args:
		print(e)

printSeq(*[2, 3, -3, 4])

print(*[-10, 11 ,100, 1])

def getSeq(**kwargs):
	for key, value in kwargs.items():
		print(key, value)

dict2 = {}
dict2['a'] = -3
dict2['b'] = 5
dict2['c'] = 1
getSeq(**dict2, hello=100)

class Rectangle:
	"""docstring for Rectangle"""
	def __init__(self, length, width):
		self.length = length
		self.width = width

	def area(self):
		return self.length * self.width

	def perimeter(self):
		return 2*(self.length + self.width)

	def __getitem__(self, key):
		# return getattr(self, key)

r1 = Rectangle(2, 3)
print(r1.area(), r1.length, r1["width"])