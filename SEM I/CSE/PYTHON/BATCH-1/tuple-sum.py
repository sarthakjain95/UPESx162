tup = ()
for i in range(5):
    num = int(input("Enter a number: "))
    tup = tup+(num,)
    
sum_ = 0
for j in range(5):
    sum_ += tup[j]

print(sum_)
