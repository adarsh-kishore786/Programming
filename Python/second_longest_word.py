sentence = input("Enter a sentence: ")
words = sentence.split()

l_word = words[0]
sl_word = words[-1]

for w in words:
	if len(w) > len(l_word):
		sl_word = l_word
		l_word = w 
	elif len(w) > len(sl_word): 
		sl_word = w

print("Longest word is: {}".format(l_word))		 
print("Second longest word is: {}".format(sl_word))