str_ = input("Enter a string:")
vowels = 0
for i in str_:
    if i in('a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'):
        vowels+=1
print("Number of vowels in the string:", vowels)