
from pprint import pprint

# Making a basic sentence segmentation classifier
# This is a very basic classifier, capable of predicting if 
# the sentence boundaries are correct or not.

class Classifier:
    numbers = "1234567890"
    def predict(self, i, corpus):
        # Check if fullstop at index 'i' ends a sentence
        # Gather the last word seen
        j = i
        while j >= 0 and corpus[j] != ' ':
            j -= 1
        before = corpus[j:i].strip()
        # If word starts with a captital letter, it is very likely an abbreviation
        if before[0] in "QWERTYUIOPASDFGHJKLZXCVBNM":
            # If all the letters are capitalizes, it is an acronym
            # In which case, this is very likely the end of sentence
            if before.upper() == before and len(before) > 1:
                return True
            else:
                # Else it is an abbreviation not sentence end
                return False
        # Floating point numbers
        if before[0] in self.numbers:
            # Check if the letter next to '.' is also a number
            if (i+1) <= len(corpus) and corpus[i+1] in self.numbers:
                # 'i' is the decimal of a floating point number
                return False
            else:
                # Else, it is an year or some other number
                return True
        # If the letter next to 'i' is a whitespace character, 
        # this might be a sentence end.
        if (i+1) == len(corpus) or (corpus[i+1] in " \n\t"): 
            return True
        else:
            # Else this is not the sentence end
            return False        

# Since the given text/data has all trivial examples, 
# I will be using some custom sentences to test this classifier

# A combination of random sentences, used to test this classifier
custom_data = """
This is Dr. Moody. Pi is 3.14159. Hello, world. Proposed by Fr. Vernon F. Gallagher in 1952.
This is NASA. Tennis, soccer, baseball, etc., are outdoor games. 
It was during the tenure of F. Henry J. McAnulty that Fr. Gallagher's ambitious plans were put to action.
"""

total_sentences = 7

classifier = Classifier()
predictions = []
last_sentence_end = -1

for i in range(len(custom_data)):
    if custom_data[i] != '.': continue 
    # We know that a sentence is most likely to end with '.'
    # So we check all full stops
    is_sentence_end = classifier.predict(i, custom_data)
    if is_sentence_end:
        # Add sentence to results 
        sentence = custom_data[(last_sentence_end+1):(i+1)]
        predictions.append(sentence.strip())
        last_sentence_end = i

print("Predicted sentences:")
pprint(predictions)

'''
As we can see from the results of the predictions, a classifier with pre-encoded trivial rules worked pretty well on the given data. 
It was not able to predict all the boundaries correctly, but this classifier can be made more complex by encoding even more complex rules and pattern checking methods.
'''
