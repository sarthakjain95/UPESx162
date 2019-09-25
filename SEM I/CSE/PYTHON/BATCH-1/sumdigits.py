n = int(input("Enter a number: "))
sum_ = 0
while n!=0:
    rem = n%10
    sum_ = sum_+rem
    n = n//10

print(sum_)