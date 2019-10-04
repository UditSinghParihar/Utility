import sys


class Person(object):
	def __init__(self, age):
		self.age = age


	def getAge(self):
		print("Age is %d" % (self.age))


class Employee(Person):
	def __init__(self, name, age):
		super(Employee, self).__init__(age)
		self.name = name


	def getName(self):
		print("Name is %s" % (self.name))


	def getAge(self):
		print("Maah age is : %d" % (self.age))


	def __add__(self, other):
		return Employee(self.name + " " + other.name, self.age + other.age)


if __name__ == '__main__':
	e1 = Employee("Manas", 15)
	p1 = Person(25)

	e1.getName(); e1.getAge()
	p1.getAge()

	e2 = Employee("Ujjwal", 19)
	e3 = e1 + e2
	e3.getName(); e3.getAge()
