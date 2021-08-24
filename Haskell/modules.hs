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
