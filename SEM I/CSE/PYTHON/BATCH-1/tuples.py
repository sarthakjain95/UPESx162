tup = (10, 20, 30, 40, 50)
min_num = tup[-1]
for i in tup:
    if i < min_num:
        min_num = i

print(min_num)