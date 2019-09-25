sub = ("Physics", "Chemistry", "Maths", "Computer", "PhyEdu")

# Find total number of subjects
print("Total number of subjects:",len(sub))

# Display all the subjects
print(sub)

# Change the subject of Physical Education to English
lst = list(sub)
lst[-1] = "English"
print(tuple(lst))

#Remove the specific element from the tuple
i = sub.index("Chemistry")
sub= sub[0: i] + sub[i+1 :]
print(sub)