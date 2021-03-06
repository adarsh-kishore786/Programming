import Data.List

-- the nub function weeds out the du[plicate elements in a list
numUniques :: (Eq a) => [a] -> Int
numUniques = length . nub

placeInBetween :: a -> [a] -> [a]
placeInBetween r = intersperse r

placeListInBetweenList :: [a] -> [[a]] -> [a]
placeListInBetweenList r = intercalate r

transpose2Dmatrix :: [[a]] -> [[a]]
transpose2Dmatrix = transpose

-- foldl' and foldr' are stricter non-lazy version of foldl and foldr

-- concat removes one level of nesting for higher order list use
-- concat that many times
flattenList :: [[a]] -> [a]
flattenList = concat

-- concatMap first applies the map function to each element, then flattens
concatMap' :: (a -> [a]) -> [a] -> [a]
concatMap' f = concatMap f

returnAllTrue :: [Bool] -> Bool
returnAllTrue = and

returnOneTrue :: [Bool] -> Bool
returnOneTrue = or

-- any and all are just like and or except they don't use map, the map function
-- is inbuilt

any' :: (a -> Bool) -> [a] -> Bool
any' f = or . map (f)

all' :: (a -> Bool) -> [a] -> Bool
all' f = and . map (f)

-- iterate takes a function and a starting value and keeps applying the function
-- again and again in infinite composition

iterate' :: (a -> a) -> a -> [a]
iterate' f x = x : Main.iterate' f (f x)

-- splitAt splits at the index
(a, b) = splitAt 3 "foobar"

-- dropWhile is just the opposite of takeWhile. it drops the elements from
-- a list as long as the predicate is false

-- span is basically takeWhile ++ dropWhile
span' :: (a -> Bool) -> [a] -> ([a], [a])
span' f xs = (takeWhile f xs, dropWhile f xs)

-- break p = span . (not p)
break' :: (a -> Bool) -> [a] -> ([a], [a])
break' p xs = span (not . p) xs

-- sort is self explanatory, however elements of list must be a subclass
-- of Ord

-- group takes a list and puts adjacent duplicates into sublists
group' :: (Eq a) => [a] -> [[a]]
group' = group

numOccurence :: (Ord a) => [a] -> [(a, Int)]
numOccurence l = map (\l@(x:xs) -> (x, length l)) . group . sort $ l

-- inits and tails are like init and tail only, except they apply
-- those functions recursively until they exhaust the array
l = inits "woot"
l' = tails "woot"

-- a substring searcher implementing isInfixOf
search :: (Eq a) => [a] -> [a] -> Bool
search substr str =
    let l = length substr
    in foldl (\acc x -> if take l x == substr then True else acc) False (tails str)

-- isPrefixOf and isSuffixOf search for a sublist at the beginning or end of
-- list
isPrefixOf' :: (Eq a) => [a] -> [a] -> Bool
isPrefixOf' substr str =
    let l = length substr
    in foldl (\acc x -> if take l x == substr then True else acc) False (inits str)

isSuffixOf' :: (Eq a) => [a] -> [a] -> Bool
isSuffixOf' substr str =
    let l = length substr
    in isPrefixOf' (reverse substr) (reverse str)

-- elem and notElem check if an elements is or isn't inside a list

-- partition retruns a 2-tuple, the first one is basically those for which some
-- boolean function returns true, second for those which return false
partition' :: (Eq a) => (a -> Bool) -> [a] -> ([a], [a])
partition' p list = ( [ x | x <- list, p x == True], [x | x <- list, p x == False])

-- find function returns the first instance of occurence of a value in a
-- list which satisfies a given predicate, its return type is Maybe
