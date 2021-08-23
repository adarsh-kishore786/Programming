-- function application is done by $ operator. It is defined as
-- ($) :: (a -> b) -> a -> b
-- f $ x = f x

-- Although it looks technically the same, the use it that it has the lowest
-- precedence, thus helping to omit brackets

s = sqrt 3 + 4 + 9
-- This prints 3^(0.5) + 4 + 9

s' = sqrt $ 3 + 4 + 9
-- This prints 4

result = sum (filter (>10) (map (*2) [2..10]))
result' = sum $ filter (>10) $ map (*2) [2..10]

-- a thing that actually could not be done without $
-- an argument applied to a list of functions!
res = map ($ 3) [(4+), (10*), (^2), sqrt]
