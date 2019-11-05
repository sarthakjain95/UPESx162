# -*- coding: utf-8 -*-


"""Question4"""
 
a="Welcome to UPES "

print(a[::-2])
print(a.split())
print(len(a.split()))


"""Question6 a"""

str1=input("Enter string:")
count1=0
count2=0
for i in str1:
      if(i.islower()):
            count1=count1+1
      elif(i.isupper()):
            count2=count2+1

print("The number of lowercase characters is:")
print(count1)
print("The number of uppercase characters is:")
print(count2)


"""Example """

count = 0
for letter in 'Hello World':
      if(letter == 'l'):
            count += 1

print(count,'letters found')


"""Question6 b"""

string = "hey hi how are you "
strsplit = string.split()
for word in strsplit:
      if len(word)==3:
            print (word)

                
"""Question 5 a"""

employee_list = [{
      'name': 'John',
      'exp_months': '50',
      'salary': '50000'
}, {
      'name': 'Alice',
      'exp_months': '10',
      'salary': '15000'
}, {
      'name': 'David',
      'exp_months': '20',
      'salary': '20000'
}]    

   
for employee in employee_list:
      print ("employee['name']: ", employee['name'])
      print ("employee['salary']: ", employee['salary'])

 
'''seq = [employee['salary'] for employee in employee_list]

max(seq)'''

max_salary_employee = max(employee_list, key=lambda employee:employee['salary'])
"""minPricedItem = min(employee_list, key=lambda employee:employee['salary'])"""
print(max_salary_employee)
