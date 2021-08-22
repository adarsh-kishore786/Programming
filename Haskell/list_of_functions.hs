listOfFns :: (Num a, Enum a) => [a -> a]
listOfFns = map (*) [0..10]
