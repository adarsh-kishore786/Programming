multThree :: (Num a) => a -> (a -> (a -> a))
multThree x y z = x*y*z

-- These are functions resulting from partial function application
mult3 = multThree 3
mult15 = multThree 3 5

compare100 :: (Num a, Ord a) => a -> Ordering
compare100 = compare 100

divideBy10 :: (Floating a) => a -> a
divideBy10 = (/10)

isUpperAlphanum :: Char -> Bool
isUpperAlphanum = (`elem` ['A'..'Z'])
