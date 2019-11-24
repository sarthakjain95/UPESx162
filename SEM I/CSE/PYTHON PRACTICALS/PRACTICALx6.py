# -*- coding: utf-8 -*-

# Practical 6

# Q1) 
# Scan n values in range 0-3 and print the number of times 
# each value has occurred.
n_values=[]
n=3
for i in range(n):
	entered_value=0
	while True:
		try:
			entered_value= input("Enter a value between (0-3):")
			entered_value= int(entered_value)
			if 0 <= entered_value <= 3:
				n_values.append(entered_value)
				break
			else:
				raise Exception("Invalid Input")
		except:
			print("Invalid input. Retry")
values_dict={}
for val in n_values:
	if val in values_dict: 
		values_dict[val]+= 1
	else:
		values_dict[val]= 1

for v in values_dict:
	print( "{0} Occured {1} times.".format( v, values_dict[v] ) )
		

# Q2)  
# Take 3 numbers as input and store their tables 
# in a list whose elements are table of the number user has entered.
nums_tables= []
print("Enter three Numbers:")
for i in range(3):
	while True:
		try:
			n= int( input("Enter Number {}: ".format(i+1)) )
			n_table=[]
			for m in range(1,11):
				n_table.append( n*m )
			nums_tables.append( n_table )
			break
		except:
			print("Error occured. Try Again.")

for table in nums_tables:
	print("\nTable for {}".format(table[0]))
	for m in range(1,11):
		print("{} * {} = {}".format( table[0], m, table[m-1]  ))

# Q3) 
# Store details of movies in any dictionary you want. 
# each movie Must store details like name,  year, director name, 
# production cost, collection made (earning).
# & Perform the following :-
# A) print all movie details
# B) Display name of movies released before 2015
# C) print movies that made a profit.
# D) print movies that made a loss.
# E) print movies directed by a particular director.
		
movies_db= {}

def getMovie():
	n= input("Enter Movie Name: ")
	y= int( input("Enter Release Year of movie: ") )
	director_name= input("Enter the name of the Director: ")
	cost= int( input("Enter the Production Cost of the Movie:(in Rupees): ") )
	earning= int( input("Enter earnings of the movie:(in Rupees): ") )
	return [ n, { "Year":y, "Director":director_name, "Earning":earning, "Cost":cost } ]

n= 1
for i in range(n):
	print("Enter Details for movie {}".format(i+1))
	mov= getMovie()
	movies_db[ mov[0] ] = mov[1]

# A) print all movie details
print("\nPrinting All movie Details:")
for m in movies_db:
	print( "\nThe Movie {} was Released in {}. It was Directed by {}.".format(m,movies_db[m]["Year"],movies_db[m]["Director"]) )
	print( "It Costed about {} Rupees. And Earned bout {} Rupees.\n\n".format(movies_db[m]["Cost"],movies_db[m]["Earning"]) )

# B) Display name of movies released before 2015
print("\nPrinting movies released before 2015:")
for m in movies_db:
	if movies_db[m]["Year"] < 2015: print(m)
	
# C) print movies that made a profit.
print("\nPrinting movies that made a profit:")
for m in movies_db:
	if movies_db[m]["Cost"] <= movies_db[m]["Earning"]: print(m)

# D) print movies that made a loss.
print("\nPrinting movies that made a loss:")
for m in movies_db:
	if movies_db[m]["Cost"] > movies_db[m]["Earning"]: print(m)

# E) print movies directed by a particular director.
d= input("\nEnter Director name:")
print("Printing Movies from Director {}".format(d))
for m in movies_db:
	if movies_db[m]["Director"] == d: print(m)


# Q4) 
# Take a paragraph as input from user and randomly jumble all the 
# letters in each word except for first and last letter. Keep the 
# special symbols at its actual position.
import random
para= input("Enter the paragraph:")

def jumbleWord(word):
	if len(word) > 3:
		w_middle=list(word[1:-1])
		random.shuffle(w_middle)
		word= word[0] + ''.join(w_middle) + word[-1]
	return word

words_list= para.split(' ')
words_list= map( jumbleWord, words_list )
print("\n\nParagraph with jumbled words is:\n\n\n", " ".join(words_list) )
