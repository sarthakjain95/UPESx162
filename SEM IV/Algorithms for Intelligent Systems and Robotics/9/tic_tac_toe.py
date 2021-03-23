
#! /usr/bin/env python 

# .:NOTE:.
# This generates all possible states for a TicTacToe Game, the original task was to 
# print all the states (with grids), but it's simply too big.

from pprint import pprint

def generate_possibilities():

	state_space_tree = {}

	wins = 0

	def recursive_selection(moves, move, branch):

		nonlocal wins

		if "children" not in branch:
			branch[0] = {}

		branch[0][move] = {}

		if len(moves.keys()) >= 3:
			# If someone won, return

			for i in range(3):
				row_check = sum([moves[(j, i)] for j in range(3) if (j, i) in moves])
				col_check = sum([moves[(i, j)] for j in range(3) if (i, j) in moves])
				if row_check in (3, 12) or col_check in (3, 12):
					wins += 1
					return 

			pos_slope_d = []
			neg_slope_d = []
			for i in range(3):
				neg_slope_d.append(moves[(i, i)] if (i, i) in moves else 0)
				pos_slope_d.append(moves[(i, abs(i-2))] if (i, abs(i-2)) in moves else 0)

			if pos_slope_d in (3, 12) or neg_slope_d in (3, 12):
				wins += 1
				return

		for i in range(3):
			for j in range(3):
				if (i, j) not in moves:
					k = 1 if move[-1] == 4 else 4
					moves[(i, j)] = k
					recursive_selection(moves, (i, j, k), branch[0][move])
					del moves[(i, j)]

	for i in range(3):
		for j in range(3):
			for k in (1, 4):
				wins = 0
				moves = {(i, j):k}
				recursive_selection(moves, (i, j, k), state_space_tree)
				# Win count will be same for all moves at this level
				print(f"Completed:{(i, j, k)} \t Wins:{wins}")

	return state_space_tree


if __name__ == "__main__":

	state_space_tree = generate_possibilities()
	# Don't print it is too big!
	# pprint(state_space_tree)
