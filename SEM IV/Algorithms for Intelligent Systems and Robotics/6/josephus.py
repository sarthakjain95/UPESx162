
#! /usr/bin/env python


def josephus_reduce(people, start, k):
	
	print(people, start, k)
	
	if len(people) == 1:
		return people[0]
	else:
		start = (start + k - 1) % len(people)
		del people[start]
		return josephus_reduce(people, start, k) 


if __name__ == "__main__":

	n = int(input("Enter n: "))
	k = int(input("Enter k: "))

	people = [i for i in range(1, n+1)]
	safe_position = josephus_reduce(people, 0, k)
	print(f"Safe position is {safe_position}")

