maximum' :: (Ord a) => [a] -> a
maximum' [] = error "Maximum of empty list"
maximum' [x] = x
maximum' (x:xs)
    | x > tailMax = x
    | otherwise = tailMax
    where tailMax = maximum' xs

max' :: (Ord a) => [a] -> a
max' [] = error "Maximum of empty list"
max' [x] = x
max' (x:xs) = max x (max' xs)

replicate' :: (Num i, Ord i) => i -> a -> [a]
replicate' n x
    | n <= 0 = []
    | otherwise = x : replicate' (n-1) x

take' :: (Num i, Ord i) => i -> [a] -> [a]
take' _ [] = []
take' n xs
    | n <= 0 = []
    | n >= fromIntegral (length xs) = xs
    | otherwise = head xs : take' (n-1) (tail xs)
