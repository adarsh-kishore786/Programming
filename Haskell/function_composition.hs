-- in maths function composition is defined as
-- If g: A -> B, g = g(x) for all x in A
--    f: B -> C, f = f(x) for all x in B
-- then
--f o g: A -> C, (f o g)(x) = f(g(x)) for all x in A

-- Similarly, in Haskell, the . operator is used for function
-- composition
-- if f :: b -> c and g :: a -> b then
-- (.) :: (b -> c) -> (a -> b) -> (a -> c)
-- f . g = f $ g x

-- first multiplies by 3, then negates
multiplyNegate :: (Num a) => a -> a
multiplyNegate = negate . (*3)

negateAbs :: (Num a) => [a] -> [a]
negateAbs = map (negate. abs)

result :: (Num a) => [[a]] -> [a]
result = map (negate . sum . tail)

result' = sum . replicate 5 . max 6.7 $ 8.9
