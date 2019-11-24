
# Practical 9

# Q1. Create a class of student with suitable details. 
# Create 3 objects and display details of all students.

class Student:

	def __init__(self, rno, name, cgpa):
		self.rno= rno
		self.name= name
		self.cgpa= cgpa

	def display(self):
		print(self.rno , "is", self.name, "and has", self.cgpa, "CGPA.\n")

students_list= []
n= int( input("Number of Students: ") )

for i in range(n):

	input_rno= int( input("Enter Roll Number: ") )
	input_name= input("Enter name: ")
	input_cgpa= float( input("Enter CGPA: ") )

	student_obj= Student(input_rno, input_name, input_cgpa)
	students_list.append(student_obj)

	print()

for student in students_list: student.display()


# Q2. Add constructor in the above class and implement following functions:
# 	a) To add new student
# 	b) To remove existing student
# 	c) Change marks of a student 
# 	d) Find percentage of a student

class Student_Q2:

	def __init__(self, rno, name, phy_marks, chem_marks, maths_marks):
		self.rno= rno
		self.name= name
		self.phy_marks= phy_marks
		self.chem_marks= chem_marks
		self.maths_marks= maths_marks

	def display(self):
		print(self.rno, self.name, self.phy_marks, self.chem_marks, self.maths_marks)

	def changeMarks(self):
		subject= input("Enter subject: ").lower()
		if subject == "physics":
			new_marks= float( input("Enter new Physics marks: ") )
			self.phy_marks= new_marks
		elif subject == "chemistry":
			new_marks= float( input("Enter new Chemistry marks: ") )
			self.chem_marks= new_marks
		elif subject == "maths":
			new_marks= float( input("Enter new Maths marks: ") )
			self.maths_marks= new_marks

students_list= []

def addStudent():
	global students_list
	input_rno= int( input("Enter roll number: ") )
	input_name= input("Enter name: ")
	input_phy_marks= float( input("Enter Physics marks: ") )
	input_chem_marks= float( input("Enter Chemistry marks: ") )
	input_maths_marks= float( input("Enter Maths marks: ") )
	student_obj= Student_Q2(input_rno, input_name, input_phy_marks, input_chem_marks, input_maths_marks)
	students_list.append(student_obj)
	print("\n")

n= int(input("Number of students: "))

for i in range(n): addStudent()

check_rno= int( input("Enter Roll Number of Student whose marks you want to change: ") )
for student in students_list:
	if student.rno == check_rno:
		student.changeMarks()

check_name= input("Enter name of student to get his percentage: ")
for student in students_list:
	if student.name == check_name:
		perc=  (student.phy_marks + student.chem_marks + student.maths_marks)/3
		print("Percentage of", student.name, "is", "%.2f" %perc ,"\n")

delete_rno= int(input("Enter roll number of student to be deleted: "))
for i in range( len(students_list) ):
	if students_list[i].rno == delete_rno:
		print(students_list[i].name, "was deleted from the list.")
		del students_list[i]

print("List after deleting elements: ")
for student in students_list: student.display()   
