"""
   link_peach_zelda.py

   Princess Peach has been captured by Voldemort
   and Link is on a mission to save her. There are
   N towns labeled 1, 2, ..., N in which he suspects 
   the princess is hidden. He starts from a 
   village and the village people tell him the next
   village number. Link tries K times before 
   giving up.

   The villagers of village i always tell him to go to
   village Ai, where A is a permutation function.

   Find out the number of the village in which 
   Link gives up.

   Enter the number of villages: 4
   Enter number of tries: 5
   Enter permutation function: 3 2 4 1
   He gives up in village 4.

   Enter the number of villages: 6
   Enter number of tries: 727202214173249351
   Enter permutation function: 6 5 2 5 3 2
   He gives up in village 2.
"""

if __name__ == "__main__": # Run this part only if it is asked to be run
	N = int(input("Enter the number of villages: "))
	K = int(input("Enter number of tries: "))

	while True:
		s = input("Enter permutation function: ")
		A = [int(e) for e in s.split()]

		if len(A) == N:
			break
		else:
			print("This is not a valid permutation function.")

	cache = [] # Stores the movements of Link
	next_vil = 1

	for i in range(1, K+1):
		cache.append(next_vil)
		next_vil = A[cache[i - 1] - 1]

		if next_vil in cache:
			remain = K - len(cache)
			start = cache.index(next_vil)
			number_of_village = remain % (len(cache) - start)
			next_vil = cache[start + number_of_village]
			break
	
	print("\nHe will give up in village {0}.".format(next_vil))