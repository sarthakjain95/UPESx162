## Question 1

file_obj = open("Python Lab\Practical 9\\name.txt", "w")
for i in range(2):
    file_obj.write(input("Enter name: ")+"\n")
file_obj.close()

count_names = 0
count_name_vowels = 0
name_list = []

file_obj = open("Python Lab\Practical 9\\name.txt", "r")
for x in file_obj:
    name_list.append(x)
    count_names += 1
    
    if x[0] in "AEIOUaeiou":
        count_name_vowels += 1

max_str = name_list[0]
for i in name_list:
    if len(i) > len(max_str):
        max_str = i
        
print("Total names are:", count_names)
print("Names starting with vowels:", count_name_vowels)
print("Longest name is:", max_str)
file_obj.close()


## Question 2

file_obj = open("Python Lab\Practical 9\\integers.txt", "w")
for i in range(2):
    file_obj.write(input("Enter integer: ")+"\n")
file_obj.close()

num_list = []
count = 0
file_obj = open("Python Lab\Practical 9\\integers.txt", "r")
for x in file_obj:
    num_list.append(int(x))
    if int(x) > 100:
        count += 1

max_num = num_list[0]
for i in num_list:
    if i > max_num:
        max_num = i

total = 0
for i in num_list:
    total += i
avg = total / len(num_list)

print("Max number is:", max_num)
print("Average of all numbers: ", avg)
print("Count of numbers greater than 100:", count)
file_obj.close()

## Question 3

file_obj = open("Python Lab\Practical 9\\student.txt", "w")
name_list = []
avg_list = []
for i in range(2):

    name = input("Enter name: ")
    roll_no = input("Enter roll number: ")
    phy_marks = input("Enter physics marks: ")
    chem_marks = input("Enter chemistry marks: ")
    maths_marks = input("Enter maths marks: ")
    name_list.append(name)
    details = name + " " + roll_no + " " +phy_marks + " " + chem_marks + " " + maths_marks

    file_obj.write(details)
    file_obj.write("\n")
file_obj.close()

detail_list = []
count = 0
file_obj = open("Python Lab\Practical 9\\student.txt", "r")
for x in file_obj:
    print(x)
    detail_list.append(x.split(" "))
    
phy_total = 0
chem_total = 0
maths_total = 0

for i in range(len(detail_list)):
    phy_total += int(detail_list[i][2])
    chem_total += int(detail_list[i][3])
    maths_total += int(detail_list[i][4])
    stu_avg = int(detail_list[i][2]) + int(detail_list[i][3]) + int(detail_list[i][4])
    print("Average of", detail_list[i][0], "is", stu_avg/3)
    avg_list.append(stu_avg/3)

print("Average marks in Physics:" , phy_total/len(detail_list))
print("Average marks in Chemistry:" ,chem_total/len(detail_list))
print("Average marks in Mathematics:" ,maths_total/len(detail_list))
print("Topper is:", name_list[avg_list.index(max(avg_list))])
file_obj.close()