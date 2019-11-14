#### Dictionary basics ####

# d = {1:'one', 2:'two'}
# d2 = {2: "a", "foo":"b"}

# print(d[1])
# d[1] = 'New one'
# print(d[1])


# print(len(d2))
# d2.update(d)
# print(d2)


# print(d2.items())
# print(d2.values()) 
# print(d2.pop("foo")) #Pops element with key
# print(d2) #Element is removed from the dictionary
# del(d2) #Del function is used for deleting the object completely from the run-time


# d4 = {"roll": [1, 4, 5, 9]}
# for i in d4["roll"]:
#     print(i)
# d4["roll"].append(11)
# print(d4)

# d5 = {"a": {"b": 1}}
# print(d5)


####                      ####
#######   Questions   ########


# Q1. Student dictionary

stu_dict = {}
for i in range(int(input())):
    name = input("Enter name: ")
    roll_no = int(input("Enter roll number: "))
    cgpa = int(input("Enter CGPA: "))

    stu_dict.update({i:[name, roll_no, cgpa]})

print(stu_dict)


# Q2. Sum of all values

# sum_dict = {}
# sum_vals = 0
# for i in range(int(input())):
#     value = int(input("Enter values: "))
#     sum_dict.update({i+1: value})
#     sum_vals += sum_dict[i+1]
    
# print(sum_vals)

# print(sum(sum_dict.values())) 

