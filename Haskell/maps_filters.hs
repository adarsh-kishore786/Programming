map' :: (a -> b) -> [a] -> [b]
map' _ [] = []
map' f (x:xs) = [f x] ++ map' f xs

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' p (x:xs)
    | p x = [x] ++ filter' p xs
    | otherwise = filter' p xs

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
    let smallerSorted = quicksort (filter' (<=x) xs)
        biggerSorted = quicksort (filter' (>x) xs) in
    smallerSorted ++ [x] ++ biggerSorted

largestDivisible :: (Integral a) => a
largestDivisible = head (filter' p [100000, 99999..])
    where p x = x `mod` 3829 == 0

takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' _ [] = []
takeWhile' p (x:xs)
    | p x = [x] ++ takeWhile' p xs
    | otherwise = []

-- Assuming [a] is sorted in ascending order
squares :: (Num a, Ord a) => [a] -> [a]
squares [] = []
squares (x:xs)
    | x^2 < 10000 = [x] ++ squares xs
    | otherwise = []
