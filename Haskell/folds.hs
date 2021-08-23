-- folds act as accumulators, folding a list from the left or the right

--fold from left
sum' :: (Num a) => [a] -> a
sum' xs = foldl (\acc x -> acc + x) 0 xs

sum'' :: (Num a) => [a] -> a
sum'' = foldl (+) 0

elem' :: (Eq a) => a -> [a] -> Bool
elem' y = foldl (\acc x -> if x == y then True else acc) False

--fold from right
map' :: (a -> b) -> [a] -> [b]
map' f xs = foldr (\x acc -> f x : acc) [] xs

-- the foldl1 and folr1 are foldl and foldr which take the 1st and last element
-- of the list respectively as their initial value
