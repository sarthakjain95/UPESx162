# Practical 8

# Q1. Write a Python function to find the maximum and minimum numbers from a sequence of numbers.
# Note: Do not use built-in functions.
lst = [int(input("Enter a number: ")) for i in range(int(input("Enter total elements: ")))]
def max_num(lst):
    max_val = lst[0]
    for val in lst:
        if val  > max_val:
            max_val = val
    return max_val

def min_num(lst):
    min_val = lst[0]
    for val in lst:
        if val  < min_val:
            min_val = val
    return min_val

print(f"Maximum value is: {max_num(lst)} and minimum value is: {min_num(lst)}")

# Q2. Write a Python function that takes a positive integer and returns the sum of the cube of all the positive integers smaller than the specified number.
def less_cube(num):
    if num <= 0:
        print("Invalid Input.")
    else:
        sum_cubes = 0
        for i in range(1, num):
            sum_cubes += i**3
        return sum_cubes

num = int(input("Enter number: "))
print(f"Sum of cubes of numbers lesser than the number is: {less_cube(num)}")

# Q3. Write a Python function to find a distinct pair of numbers whose product is odd from a sequence of integer values.
lst = [int(input("Enter a number: ")) for i in range(int(input("Enter total elements: ")))]
def distinct_pairs(lst):
    pair_list = []
    for i in range(len(lst)):
        for j in range(len(lst)):
            if  i != j:
                if lst[i]*lst[j] % 2 != 0:
                    pair_list.append((lst[i],lst[j]))
    return pair_list

print(f"Distinct pairs are: {distinct_pairs(lst)}")