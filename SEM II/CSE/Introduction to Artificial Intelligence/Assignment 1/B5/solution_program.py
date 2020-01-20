
#! /usr/bin/env python3

# Made for Python3

# Made By: 	Sarthak Jain, UPES, Second Sem
# Course/Batch: B.tech CSE AI&ML, BATCH 5
# Roll No: 	R177219162

import string

logical_connectives= [ "not", "if", "else", "then", "every", "for every", "and", "or" ]

expanded_terms= set()
focused_terms= set()
unnecessary_words= set()

direct_relationships= {}
singular_plural_map= {}


def clean_data(data):

	"""
		This function basically makes the data more consistent, because consistent
		data is easier to work with.
	"""

	global singular_plural_map

	remove_punctuation = str.maketrans('', '', string.punctuation)
	less_than_three= lambda x : len(x) > 2

	data= "\n".join(data).lower()

	# Removing signs and punctuation symbols
	data= data.translate(remove_punctuation)

	# Remove all words less than 3 characters because we are interested in extracting logical
	# relationships between these words. And words less than 3 characters e.g.('a','i','to',etc)
	# generally do not effect the main core logic of sentences.
	line_wise= data.split('\n')
	updated_data= []
	for line in line_wise:
		new_line= line.split(' ')
		new_line= list( filter(less_than_three, new_line) )
		updated_data.append( " ".join(new_line).lower() )
	data= updated_data

	# Searches whole data for plural words and replaces them with singular words
	# since we want to extract major terms out of the given data and sentences,
	# and words having plural forms will affect our process of extracting
	# relationships among and terms.
	
	words_list= " ".join(data).split(' ')
	# Checks if plural of words also exists in the data set
	for word in words_list:
		if word+'s' in words_list:
			singular_plural_map[word+'s']= word 
	# Replaces all plurals found with singular forms
	for plural in singular_plural_map:
		singular= singular_plural_map[plural]
		data= ( "\n".join(data).replace(plural, singular) ).split('\n')

	return data


def extract_terms(data):

	"""
		This function basically extracts Focused terms from the data
	"""

	global expanded_terms, focused_terms, logical_connectives, unnecessary_words

	# 'expanded_terms' basically saves the state of data at this point before it is
	# further manipulated.
	expanded_terms= set([*data])

	# Getting word count for every word in the data set to get a better focused data set.
	words_stats= {}
	words= (" ".join(data)).split(' ')
	for word in words:
		if word not in words_stats:
			words_stats[word]= {}
			words_stats[word]["count"]= 0
		words_stats[word]["count"]+=1

	data= "\n".join(data)
	# Replacing every word that appears less than 2 times and is also not among the logical
	# connective words.
	for word in words_stats:
		if words_stats[word]["count"] < 2 and word not in logical_connectives:
			data= data.replace(word, '').replace('  ',' ').strip()
			# Adding the word in a seperate list so, that the questions asked can
			# also be filtered on the basis of this list.
			unnecessary_words.add( word )

	trim= lambda s: s.strip().replace('  ', ' ')
	data= list(map( trim, data.split('\n') ))
	
	# Further more, we will extract all the main "Focused terms" from the given data.
	# At this point in the program, the data is mostly clean of unecessary terms.
	# All it contains are focused terms or a combination of focused terms
	sub_focused_data= [*data]
	# This while loop iterates through the sub_focused_data to extract all the focused
	# terms that it can.
	last_length= -1

	def add_focused_term(terms):
		global focused_terms
		for term in terms:
			if term not in focused_terms and term.strip() != '':
				focused_terms.add(term)

	# Ther iteration stops when no more focused terms are found  within the data.
	while last_length != len(focused_terms):
		
		terms_to_add= []
		last_length= len(focused_terms)
		for x in sub_focused_data:
			for y in sub_focused_data:
				if x == y: continue
				if x in y:
					a,b= y.split(x)
					terms_to_add.extend([x, a.strip(), b.strip()])
		
		add_focused_term(terms_to_add)
		# focused_terms= focused_terms.union({*terms_to_add})
		sub_focused_data= list(focused_terms)
		# print(sub_focused_data)

	# At this point, we have collected all the focused terms from the data, so we
	# further narrow down the data by removing all the lines that contain only a
	# single focused term.
	# Because these line are no longer of use to us, because we now need the lines
	# that have multiple focused terms within them.
	data= list(filter( lambda x: x not in focused_terms, data ))
	
	print("\nExpanded terms\t",expanded_terms)
	print("Final data\t",data)
	print("Focused terms\t",focused_terms)

	return data


def derive_relations(raw_data):

	"""
		Extracts all the relationships between the Focused terms
	"""
	
	global focused_terms, expanded_terms, direct_relationships

	# Cross combines the terms and makes relationships among them
	for line in raw_data:	
		# Checks every line in raw_data to see if any line contains a focused term,
		# If it does, than that would mean that every other term in the sequence/line
		# is related with that focused term.
		for term in focused_terms:
			if term in line:
				related_term= line.replace(term,'').strip().replace('  ',' ')
				if term not in direct_relationships: 
					direct_relationships[term]= []

				if related_term not in direct_relationships[term]: 
					direct_relationships[term].append(related_term)
				# if lx not in direct_relationships: direct_relationships[lx]= []
				# if term not in direct_relationships[lx]: direct_relationships[lx].append(term)
	
	"""
		Logs out all the related terms.
	"""	
	print("\nRelationships with Focused terms:\n")

	for rel in direct_relationships:
		print(rel, end=": ")
		print(direct_relationships[rel])


def prove_logical_equivalence(p,q):

	"""
		This function basically tries to find any relationship between p and q
		It searches all the relationships of 'q' in the 'direct_relationships'
		map, that we created while processing the data itself.
	"""

	global direct_relationships

	print( "\nTrying to prove logical equivalence in '{}' and '{}'".format(p, q) )
	print("Searching relationships with '{}'\n".format(q))

	# Search for relations with 'Q'
	related_terms= []
	for x in direct_relationships:
		if x == q: 
			related_terms.extend([*direct_relationships[q]])
		else:
			for n in direct_relationships[x]:
				if n == q:
					related_terms.append(x)

	# Compares all the related_terms found with P, so if one is found, it returns True
	for r in related_terms:
		if r == p:
			# Direct relationship is found.
			print( "'{}' = '{}'".format(r, p) ) 
			return True
		else: 
			# Logs the relationship that didn't match up.
			print( "'{}' != '{}'".format(r, p) )

	# If nothing is found in the end, returns False as final result.
	return False


def evaluate_question(question, data):

	"""
		Cleans the question down to only the focused terms to make comparison easier.
		Then check if the combination of focused terms matches any line of the clean data.
		If no match is found, then it returns the result of the function that tries to
		prove logical equivalence in the given focused terms based on previously establised
		relationships.
	"""

	global focused_terms, unnecessary_words, singular_plural_map

	print("\nQuestion:", question)

	# Making question more consistent.
	# Cleans the question to include only a combination of focused terms.

	# Changes every plural to singular using the previously made map.
	for plural in singular_plural_map:
		if plural in question:
			question.replace( plural, singular_plural_map[plural] )

	# Remove all the punctuation symbols
	remove_punctuation = str.maketrans('', '', string.punctuation)
	question= question.translate(remove_punctuation).lower()

	# Changing singular to plural
	words= question.split(' ')
	for word in words:
		if word[:-1] in focused_terms:
			question= question.replace( word, word[:-1] )
		elif word+'s' in focused_terms:
			question= question.replace( word, word+'s' )

	# Remove words that are not in focused terms or, are too small
	clean= lambda x: len(x)>2 and x in focused_terms
	clear_question= " ".join( list(filter(clean, question.split(' '))) )
	
	print("Question (clean): ",clear_question, " ?\nEvaluating ...\n")


	# Checks the cleaned form of the question to see if it matches any line 
	# in the "Focused-terms" only part of our data 

	# Simultaneously also comparing the question with all the lines in the data
	# to get the line that matches the most with the question, so if no direct
	# match is found, we can further process this line to see if any relation
	# causes the line to change into the question itself. 
	
	print("Checking to see if the question matches any line in the given data.")
	max_matches= ["", 0]

	for line in data:
		if line == clear_question: return True
		else:
			# Gets a count of all the focused terms in the line in data
			words= line.split(' ')
			count= 0

			# Keeps adding words to the terms until the terms in found in the
			# focused_terms data set
			term= ""
			for word in words:
				term+= word
				if term in focused_terms:
					term= ""
					count+=1

			if count > max_matches[1]:
				max_matches[0], max_matches[1]= line, count
			# line_stats[line]= count

	print("No match found for question.")

	# Find the line that matches with the question the most
	print("\nFinding the line that matches the most with the given question to see if")
	print("swapping the related words can create the logical equivalent of question.")

	print("\nClosest match to the given question is : {}".format(max_matches[0]))
	
	print("\nGathering all focused terms that don't match up.")

	similarWordsList= max_matches[0].split(' ')
	questionWordsList= clear_question.split(' ')
	
	# Gather a list of all the terms that are similar in the two sets.
	similars= []
	for w in questionWordsList:
		if w in similarWordsList: similars.append(w)

	# Removes all the similar words from both the sets.
	for sim in similars:
		similarWordsList.remove(sim)
		questionWordsList.remove(sim)

	return prove_logical_equivalence( " ".join(similarWordsList), " ".join(questionWordsList) )



raw_data= """I am a human being
I am good
Good graders study well
Humans love graders
Every human does not study well""".lower().split('\n')

if __name__ == "__main__":

	cleaned_data= clean_data(raw_data)

	# Now that we have the pure data, we can start extracting the main terms from the data that
	# we have
	focused_data= extract_terms(cleaned_data)

	# Once we have all the focused(main) terms, we can now compare these with our cleaned data 
	# to create relationships between these main terms (if any).
	derive_relations(focused_data)

	question="Is every human good grader?"
	# question="Is every human not a good grader?"    # Extra Test
	ans= evaluate_question(question, focused_data)
	
	if ans: print("\nThe evaluated answer is YES.\n")
	else: print("\nThe evaluated answer is NO.\n")


# Made By:       Sarthak Jain, UPES, IInd Sem
# Course/Batch:  B.tech CSE AI&ML, BATCH 5
# Roll No:       R177219162
