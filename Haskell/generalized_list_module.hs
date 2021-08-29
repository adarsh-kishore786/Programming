-- length, take, drop, splitAt, !!, replicate all take or return an Int.
-- Although sufficient for many reasons, it has problems of type as we
-- cannot divide by an int, that is why we have their generic versions
-- genericLength, genericTake, genericDrop, genericSplitAt, genericIndex,
-- genericReplicate. There the Int is replaced by Num

import Data.List
import Data.Function

s = let xs = [1..6] in sum xs / genericLength xs

-- the nub, delete, union, intersect, group functions have a default way of
-- checking if two elements are equal, the == operator. They have their more
-- general counterparts as nubBy, deleteBy, unionBy, intersectBy, groupBy
-- These functions also take in a boolean function which they use to test
-- 'equality'. <func>By (==) = <func>

values = [-4.3, -2.4, -1.2, 0.4, 2.3, 5.9, 10.5, 29.1, 5.3, -2.4, -14.5,
            2.9, 2.3]
res = groupBy (\x y -> (x > 0) == (y > 0)) values

-- the 'on' function in Data.Function is very useful for these kind of things

on' :: (b -> b -> c) -> (a -> b) -> a -> a -> c
f `on'` g = \x y -> f (g x) (g y)

res' = groupBy ((==) `on` (>0)) values

-- similarly, the sort, insert, maximum and minimum also have their more
-- general equivalents called sortBy, insertBy, maximumBy, minimumBy
-- they take a function, which is then used to determine the order LT, EQ,
-- GT

xs = [[5, 4, 5, 4, 4], [1, 2, 3], [3, 5, 4, 3], [], [2], [2, 2]]
res'' = sortBy (compare `on` length) xs
