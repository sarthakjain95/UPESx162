def sum_list(lst):
    total = 0
    for i in lst:
        total += i
    return total

n = int(input("Enter total elements: "))
list_num = [int(input("Enter value: ")) for j in range(n)]
sum_total = sum_list(list_num)
print(sum_total)