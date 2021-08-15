-- A tuple is a list of fixed size
a = (8, 11)

-- get first/second element
f = fst a
s = snd a

-- zip two lists into a tuple
p = [1, 2, 3, 4, 5, 6]
q = ["One", "Two", "Three", "Four", "Five", "Six"]
r = zip p q
