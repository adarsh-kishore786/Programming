-- list comprehensions are like set comprehensions
a = [ x*2 | x <- [1..10] ]
a1 = [ x*x | x <- [1, 3..10], x*2 <= 12 ]

-- function
boomBang xs = [ if x < 10 then "BOOM!" else "BANG!" | x <- xs, odd x]
crossProduct xs ys = [ x*y | x <- xs, y <- ys ]

sentence nouns verbs = [ noun ++ " " ++ verb | noun <- nouns, verb <- verbs]

length_ list = sum [1 | _ <- list]

xxs = [[1, 3, 5, 2, 2, 4, 5, 6, 1], [1, 2, 3, 4, 5, 6, 7, 8, 9],
        take 10 (cycle [1, 2, 5, 6]) ]
l = [ [ x | x <- xs, even x] | xs <- xxs ]
