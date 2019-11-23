''' Q1. Create a class of student with suitable details. 
Create 3 objects and display details of all students. '''

class Student:
    def __init__(self, rno, name, cgpa):
        self.rno = rno
        self.name = name
        self.cgpa = cgpa

    def display(self):
        print(self.rno , "is", self.name, "and has", self.cgpa, "CGPA.\n")

lst = []
n = int(input("Number of students: "))
for i in range(n):
    input_rno = int(input("Enter roll number: "))
    input_name = input("Enter name: ")
    input_cgpa = int(input("Enter CGPA: "))
    student_obj = Student(input_rno, input_name, input_cgpa)
    lst.append(student_obj)
    print("\n")

for i in lst:
    i.display()


'''
Q2. Add constructor in the above class and implement following functions:
    a) To add new student
    b) To remove existing student
    c) Change marks of a student 
    d) Find percentage of a student
'''

class Student_Q2:
    def __init__(self, rno, name, phy_marks, chem_marks, maths_marks):
        self.rno = rno
        self.name = name
        self.phy_marks = phy_marks
        self.chem_marks = chem_marks
        self.maths_marks = maths_marks

    def display(self):
        print(self.rno, self.name, self.phy_marks, self.chem_marks, self.maths_marks)

    def changeMarks(self):
        subject = input("Enter subject: ").lower()
        if subject == "physics":
            new_marks = int(input("Enter new Physics marks: "))
            self.phy_marks = new_marks
        if subject == "chemistry":
            new_marks = int(input("Enter new Chemistry marks: "))
            self.chem_marks = new_marks
        if subject == "maths":
            new_marks = int(input("Enter new Maths marks: "))
            self.maths_marks = new_marks


def addStudent():
    input_rno = int(input("Enter roll number: "))
    input_name = input("Enter name: ")
    input_phy_marks = int(input("Enter Physics marks: "))
    input_chem_marks = int(input("Enter Chemistry marks: "))
    input_maths_marks = int(input("Enter Maths marks: "))
    student_obj = Student_Q2(input_rno, input_name, input_phy_marks, input_chem_marks, input_maths_marks)
    lst.append(student_obj)
    print("\n")


lst = []
n = int(input("Number of students: "))

for i in range(n):
    addStudent()

check_rno = int(input("Enter roll number of student whose marks you want to change: "))
for i in range(len(lst)):
    if lst[i].rno == check_rno:
        lst[i].changeMarks()

check_name = input("Enter name of student to get his percentage: ")
for i in range(len(lst)):
    if lst[i].name == check_name:
        print("Percentage of", lst[i].name, "is", (lst[i].phy_marks + lst[i].chem_marks + lst[i].maths_marks)/3 ,"\n")

delete_rno = int(input("Enter roll number of student to be deleted: "))
for i in range(len(lst)):
    if lst[i].rno == delete_rno:
            print(lst[i].name, "was deleted from the list.")
            del lst[i]

print("List after deleting elements: ")
for i in lst:
    i.display()            