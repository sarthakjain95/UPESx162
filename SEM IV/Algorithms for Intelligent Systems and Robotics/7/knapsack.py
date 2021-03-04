
#! /usr/bin/env python

import random

def recursive_knapsack(weights, profits, quantities, max_capacity):

	N = len(profits)
	best_bag = []
	max_profit = -1

	def check_profit(profit, bag):

		nonlocal max_profit, best_bag
		if profit > max_profit:
			max_profit = profit
			best_bag = [*bag]
			# print("New best bag: ", bag, " Profit: ", max_profit)

	def check_bag(weight, profit, bag, n, q):

		nonlocal N
		if weight > max_capacity or n >= N:
			return

		print(f"Checking bag: {bag}")
		# Update profit for current bag	
		check_profit(profit, bag)
		# Keeping the quantity for the 'n' same, check other items
		check_bag(weight, profit, bag, n+1, 0)

		if (weight + weights[n]) <= max_capacity and (q+1) <= quantities[n]:
			# Add one more of this item and then check profit
			check_bag(weight+weights[n], profit+profits[n], bag+[n], n, q+1)

	check_bag(0, 0, [], 0, 0)
	return best_bag, max_profit


if __name__ == "__main__":

	# Generate n objects (random quantities)
	N = 2
	MAX_CAPACITY = 20
	print("Max Capacity: ", MAX_CAPACITY)
	weights, profits, quantities = [], [], []

	# Generate a random set of elements
	print("Items:")
	for i in range(N):
		weights.append(random.randint(2, 10))
		profits.append(random.randint(2, 10))
		quantities.append(random.randint(1, 5))
		# Print the bag
		print(f"Bag:{i} \t Weight:{weights[-1]} \t Profit:{profits[-1]} \t Quantity:{quantities[-1]}")

	# Make a recursive solution for the knapsack problem
	best_bag, max_profit = recursive_knapsack(weights, profits, quantities, MAX_CAPACITY)

	print(f"\nBest Bag: {best_bag}\nMax Profit: {max_profit}")

