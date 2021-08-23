maximuml :: (Ord a) => [a] -> a
maximuml = foldl1 (\acc x -> if acc > x then acc else x)

maximumr :: (Ord a) => [a] -> a
maximumr = foldr1 (\x acc -> if x > acc then x else acc)

reversel :: [a] -> [a]
reversel = foldl (\acc x -> x : acc) []

reversel' :: [a] -> [a]
reversel' = foldl (flip (:)) []

-- Note that (x:xs) is preferred over [x] ++ xs as it is less expensive
reverser :: [a] -> [a]
reverser = foldr (\x acc -> acc ++ [x]) []

productl :: (Num a) => [a] -> a
productl = foldl1 (*)

productr :: (Num a) => [a] -> a
productr = foldr1 (*)

filterl :: (a -> Bool) -> [a] -> [a]
filterl p = foldl (\acc x -> if p x then acc ++ [x] else acc) []

filterr :: (a -> Bool) -> [a] -> [a]
filterr p = foldr (\x acc -> if p x then x : acc else acc) []

headl :: [a] -> a
headl = foldl1 (\acc _ -> acc)

headr :: [a] -> a
headr = foldr1 (\x _ -> x)

lastl :: [a] -> a
lastl = foldl1 (\_ x -> x)

lastr :: [a] -> a
lastr = foldr1 (\_ acc -> acc)
