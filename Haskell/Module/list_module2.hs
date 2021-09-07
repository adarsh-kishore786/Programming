import Data.List

-- elemIndex is like elem, except it returns the Maybe index of find first index
elemIndex' :: (Eq a) => a -> [a] -> Maybe Int
elemIndex' x list = elemIndex x list

-- elemIndices returns a list of all elemIndex locations

-- zip and zipWith support variants of zip3, zip4,..., zip7 and
-- similar for zipWith for joining that many lists
result = zipWith3 (\x y z -> x + y + z) [1, 2, 3] [4, 5, 2, 2] [2, 2, 3]
result' = zip4 [2, 3, 3] [2, 2, 2] [5, 5, 3] [2, 2, 2]

-- lines takes in a string and breaks it at every new line
r = lines "first line\nsecond line\nthird line"

-- unlines is its reverse, inserts "\n" to join lines

-- ig words and unwords would be pretty clear by definition
-- delete takes an element and a list and deletes the first occurence
-- of that element in the list
delete' :: (Eq a) => a -> [a] -> [a]
delete' _ [] = []
delete' z (x:xs)
    | x == z = xs
    | otherwise = x : delete' z xs

-- \\ is the list difference function. It is actually the same as set difference
-- If A and B are two sets, A - B = { x | x in A and x not in B }
-- Similarly, if l1 and l2 are two lists, l1 // l2 = { x | x <- l1 and x not <- l2}
diff' :: (Eq a) => [a] -> [a] -> [a]
diff' [] _ = []
diff' l1@(x:xs) l2@(y:ys)
    | x `elem` l2 = diff' xs l2
    | otherwise = x : diff' xs l2

-- union and intersect are pretty self explanatory I believe

-- insert takes an element and a list which can be sorted and inserts into
-- its last position where it is less than or equal to the next element
insert' :: (Ord a) => a -> [a] -> [a]
insert' z [] = z:[]
insert' z (x:y:xs)
    | x <= z && z <= y = x:z:y:xs
    | otherwise = x : insert' z (y:xs)
