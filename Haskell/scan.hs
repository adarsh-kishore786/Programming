-- scanl and scanr are just like foldl and foldr, except they store
-- all the intermediate accumulators in a list, while fold gives just the
-- final value

sum' :: (Num a) => [a] -> [a]
sum' = scanl (+) 0

sum'' :: (Num a) => [a] -> [a]
sum'' = scanr1 (+)

reverse' :: [a] -> [[a]]
reverse' = scanl (flip (:)) []

-- we'll find the minimum number of natural numbers whose sum of square roots
-- exceeds 100

numSqrt :: Int
numSqrt =
    let sqrtList = (map sqrt [1..]) in
    length (takeWhile (<1000) (scanl1 (+) sqrtList)) + 1
