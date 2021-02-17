
#! /usr/bin/env python

import numpy as np

# Prints all valid boards using backtracking
def print_valid_boards(n= 4):

	total_valid_boards = 0

	def recursive_selection(y, board, selected_cols):
		if y >= n:
			nonlocal total_valid_boards
			print(board.astype(np.uint8), end="\n\n")
			total_valid_boards += 1
		else:
			# Iterate over all the available columns
			for x in range(n):
				if x not in selected_cols:
					# Check digonals
					if sum([ board[y+i,x+i] for i in range(-min(y, x), 0, 1) ]): 
						continue 
					if sum([ board[y+i,x-i] for i in range(-min(y, n-x-1), 0, 1) ]): 
						continue
					# Add queen at this place
					selected_cols.append(x)
					board[y,x] = True
				# Process board
				if board[y, x]:
					recursive_selection(y+1, board, selected_cols)
					del selected_cols[selected_cols.index(x)] # Remove column from shared array
					board[y, x] = False # Remove queen from shared board

	board = np.zeros((n, n)).astype(bool)
	recursive_selection(0, board, [])
	print(f"Total valid board: {total_valid_boards}")
	return 


if __name__ == "__main__":

	n = int(input("Enter size of chessboard: "))
	# n = 5
	if 3 < n < 12:
		print_valid_boards(n)
