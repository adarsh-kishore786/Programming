class Student:
	def __init__(self, roll, name, section, marksList):
		self.rollNo = roll
		self.name = name
		self.classSection = section

		for m in marksList:
			assert 0 <= m <= 100, "Invalid marks."
		self.marksList = marksList

	def setMarks(self, marksList):
		for m in marksList:
			assert 0 <= m <= 100, "Invalid marks."
		self.marksList = marksList

	def computeTotal(self):
		sum = 0
		for m in self.marksList:
			sum += m
		return sum 

	def __str__(self):
		print("Name:", self.name)
		print("Roll:", self.rollNo)
		print()

		s = ""
		for i in range(len(self.marksList)):
			s += "Marks scored in subject {0}: {1}\n".format(i + 1, self.marksList[i])
		return s

if __name__ == "__main__":
	S1 = Student(19, "Rajesh", "IX C", [92, 96, 83, 97, 91])
	S1.setMarks([92, 96, 83, 97, -91])

	print(str(S1))