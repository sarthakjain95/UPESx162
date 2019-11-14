set1 = {"Rahul", "Rohit", "Rohan", "Raj"} #AI&ML
set2 = {"Amar", "Aman", "Anirudh"} #BAO

#Find number of students of AIML
print(len(set1))

#Display all students of AIML
print(set1)

#Display all students of AIML and BAO
print(set1&set2)

#Display all students either AIML or BAO
print(set1|set2)

#Display all students either AIML or BAO but not both
print(set1^set2)