-- Concatenating two lists
a = [1, 2, 3, 4]
b = [6, 7, 8]
c = a ++ b

a1 = ['w', 'o']
a2 = ['o', 't']
b1 = a1 ++ a2

c1 = 'A' : " Cat"
c2 = 2 : [5, 6]
c3 = 1:2:3:7:[]

-- Get element at an index
c4 = "Hello" !! 2

-- list functions
h = head a
t = tail c1
l = last b1
init_ = init b
r = reverse a

-- make new lists out of old ones
take_ = take 4 "Hello"
drop_ = drop 3 c1

-- list manipulations
max_ = maximum b
min_ = minimum c1
sum_ = sum a
pro = product [1, 3..100]

-- check membership
mem = 10 `elem` [1, 3..100]

-- make lists out of a few elements
cyc = take 100 (cycle [1, 2, 3])
