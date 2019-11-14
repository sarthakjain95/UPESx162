def count_sequence(para):
    sentences = para.split(sep = ".")
    print(sentences)
    sentence_word = []
    for sentence in sentences:
        words = sentence.split(" ")
        sentence_word.append(words)
    print(sentence_word)
    return len(sentences)-1

print(count_sequence("They. Are. Here I am."))