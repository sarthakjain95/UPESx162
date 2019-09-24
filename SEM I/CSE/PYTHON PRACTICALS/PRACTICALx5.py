# -*- coding: utf-8 -*-

# Q1) Write a program to count and display the number of capital letters in a given string.
string= input("Enter a string:")
counter= 0
for i in list(string):
	if i.isupper():
		counter+=1
print("Number of capital letters counted:",counter)

# Q2) Count total number of vowels in a given string.
vowels= ['a','e','i','o','u']
string= input("Enter a string:")
counter= 0
for i in list(string):
	if i in vowels:
		counter+=1
print("Number of counted vowels: ", counter)

# Q3) Input a sentence and print words in separate lines.
string= input("Enter a string:")
string= string.split()
string= '\n'.join(string)
print(string)

# Q4) Program to count number of unique words in a given sentence.
unique_words= []
string= input("Enter a string to count unique numbers:")
string= string.split(' ')
for word in string:
	if word not in unique_words:
		unique_words.append(word)
print("Number of unique words in the given string:",len(unique_words))

# Q5) A program to scan n values and print square of each number.
nums= []
n= int(input("Enter number of values to input:"))
for i in range(n):
	temp= int(input("Enter {0} value: ".format(i+1) ))
	nums.append(temp)

# Q6) Take two sets and apply set operators on them :
# S1 = {Red ,yellow, orange , blue }
# S2 = {violet, blue , purple}

