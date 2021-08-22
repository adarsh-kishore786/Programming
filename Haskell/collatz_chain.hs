chain :: (Integral a) => a -> [a]
chain 1 = [1]
chain n
    | n <= 0 = []
    | n `mod` 2 == 0 = [n] ++ chain (n `div` 2)
    | otherwise = [n] ++ chain next
    where next = (3 * n + 1)

chain_length :: (Integral a) => a -> a
chain_length 1 = 1
chain_length n
    | n <= 0 = 0
    | n `mod` 2 == 0 = 1 + chain_length (n `div` 2)
    | otherwise = 1 + chain_length (3 * n + 1)

chain_length' :: (Integral a) => a -> a
chain_length' n = fromIntegral (length (chain n))

long_chain :: (Integral a) => [a] -> [a]
long_chain [] = []
long_chain (x:xs)
    | (chain_length' x) > 100 = [x] ++ long_chain xs
    | otherwise = long_chain xs

num_long_chain :: (Integral a) => [a] -> a
num_long_chain xs = fromIntegral (length (filter isLong (map chain xs)))
    where isLong xs = length xs > 15
