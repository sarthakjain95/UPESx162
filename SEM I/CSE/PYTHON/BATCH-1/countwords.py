s = input("Enter a sentence: ")
spaces_num = 0
for i in s:
    if i in (" ", "," ,"."):
        spaces_num +=1
print("Number of words in the sentence:", spaces_num)