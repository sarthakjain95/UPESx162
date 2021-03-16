
#! /usr/bin/env python

from pprint import pprint
from copy import deepcopy

entity_code_map = {
	1: "Goat",
	2: "Cabbage",
	3: "Wolf"
}

def map_scenario(scenario):

	mapped_scenario = []

	for state in scenario:
		mapped_scenario.append({
			"left_bank": tuple([entity_code_map[x] for x in state[0]]), 
			"right_bank": tuple([entity_code_map[x] for x in state[1]]), 
			"boat": state[2]
		})

	return mapped_scenario


def calculate_scenarios():

	def check_loss(bank, has_farmer):
		if has_farmer == False:
			if 1 in bank and 2 in bank:
				return True # Goat eats the cabbage
			if 1 in bank and 3 in bank:
				return True # Goat gets eaten by Lion/Wolf
		else:
			return False 

	seen_states = []
	scenarios = []

	def recursive_iteration(banks, pointer, states):

		state = (tuple(banks[0]), tuple(banks[1]), pointer)
		
		hsh = hash( state )
		# if we've been at this state before
		if hsh in seen_states: return
		seen_states.append(hsh)

		states.append(state) 

		if check_loss(banks[0], pointer==0) or check_loss(banks[1], pointer==1):
			scenarios.append(deepcopy(states))
			del states[-1]
			return 

		if len(set((1, 2, 3)) - set(banks[1])) == 0 and pointer == 1:
			scenarios.append(deepcopy(states))
			del states[-1]
			return # All the entities are on the other bank

		# If at bank 1, we can choose not to take anything to the other bank
		if pointer != 0: 
			recursive_iteration(banks, 1-pointer, states)
	
		# Choose any element iteratively
		for i in range(len(banks[pointer])):
			entity = banks[pointer][i]
			new_banks = [banks[0].copy(), banks[1].copy()]
			new_banks[pointer-1].append(entity)
			new_banks[pointer].remove(entity)
			recursive_iteration(new_banks, 1-pointer, states)

		del states[-1]
		return 

	# Banks of the river
	left, right = [1, 2, 3], []
	# Farmer is a pointer '0' or '1'
	pointer = 0

	recursive_iteration([left, right], pointer, [])
	return scenarios


if __name__ == "__main__":

	scenarios = calculate_scenarios()

	print(f"Total scenarios: {len(scenarios)}")

	winning_scenarios = []
	for possibility in scenarios:
		if len(possibility[-1][0]) == 0:
			winning_scenarios.append(possibility)

	print(f"Total winning scenarios: {len(winning_scenarios)}")

	sorted(winning_scenarios, key=lambda x: len(x))
	print(f"Minimum moves winning scenario:")
	pprint(map_scenario(winning_scenarios[0]))
