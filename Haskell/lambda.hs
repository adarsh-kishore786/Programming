chain :: (Integral a) => a -> [a]
chain 1 = [1]
chain n
    | n <= 0 = []
    | n `mod` 2 == 0 = [n] ++ chain (n `div` 2)
    | otherwise = [n] ++ chain next
    where next = (3 * n + 1)

num_long_chain :: (Integral a) => [a] -> a
num_long_chain xs = fromIntegral (length (filter (\xs -> length xs > 15)
                    (map chain xs)))

-- multiple arguments in lambda supported
list1 = zipWith (\a b -> (a * 30 + 3) / b) [5, 4..1] [1..5]

map1 = map (\(a, b) -> a + b) [(1,2), (3, 5), (6, 3), (2, 6), (2, 5)]
