
'''

Do the following on the paragraph given:
    1) Tokenize
    2) Stemming
    3) Lemmatization 

Finally can you implement a sentence segmentation algorithm (classifier).  

'''

import nltk
from nltk.stem.snowball import SnowballStemmer
from nltk.stem import WordNetLemmatizer
from pprint import pprint

with open("data.txt", 'r') as f:
    raw_data = f.read()

# Tokenize

# clean data 
no_punctuation = ""
for ch in raw_data:
    if ch in "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM": 
        no_punctuation += ch
    else: 
        no_punctuation += ' '

tokens = set()
for group in no_punctuation.split(' '):
    word = group.lower().strip()
    if len(word) == 1 and word in "ai":
        tokens.add(word)
    elif len(word) > 1:
        tokens.add(word)

print(f"{len(tokens)} unique tokens found!")
# print(sorted(list(tokens)))

# Stemming

stemmer = SnowballStemmer("english")
stems = set()

for word in tokens:
    stem = stemmer.stem(word)
    stems.add(stem)

print(f"{len(stems)} unique stems found!")
print(sorted(list(stems)))

# Lemmatization

lemmatizer = WordNetLemmatizer()
word_stems = set()

for word in tokens:
    stem = lemmatizer.lemmatize(word)
    word_stems.add(stem)

print(f"{len(word_stems)} unique word-stems found!")
print(sorted(list(word_stems)))
