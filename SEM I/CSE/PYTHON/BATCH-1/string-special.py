s1 = input("Enter sentence 1: ")
s2 = input("Enter sentence 2: ")
mod_str = ""
size = 0
if len(s1) > len(s2):
    size = len(s2)

for i in range(size-1):
    mod_str = mod_str+s1[i]+s2[i]

print(mod_str)