lucky :: (Integral a) => a -> String
lucky 7 = "LUCKY NUMBER 7"
lucky x =  "Sorry, out of luck pal!"

sayMe :: (Integral a) => a -> String
sayMe 1 = "One"
sayMe 2 = "Two"
sayMe 3 = "Three"
sayMe 4 = "Four"
sayMe 5 = "Five"
sayMe x = "Not between 1 and 5"

factorial :: (Integral a) => a -> a
factorial 0 = 1
factorial n = n * factorial(n - 1)

-- example of an incomplete pattern match

charName :: Char -> String
charName 'a' = "Alpher"
charName 'b' = "Beta"
charName 'c' = "Gamow"

addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)
addVectors (a, b) (c, d) = (a + c, b + d)

-- get components for tuples
first_ :: (a, b, c) -> a
first_ (a, _, _) = a

second_ :: (a, b, c) -> b
second_ (_, b, _) = b

third_ :: (a, b, c) -> c
third_ (_, _, c) = c

xs = [(1,3), (4,3), (2,4), (5,3), (5,6), (3,1)]
s = [a+b | (a, b) <- xs]

head' :: [a] -> a
head' [] = error "Empty list has no head"
head' (x:_) = x

tell :: (Show a) => [a] -> String
tell [] = "The list is empty"
tell (x:[]) = "The list has one element: " ++ show x
tell (x:y:[]) = "The list has two elements: " ++ show x ++ ", " ++ show y
tell (x:y:_) = "This list is long. The first two elements are: " ++ show x ++ ", " ++ show y

length' :: (Num b) => [a] -> b
length' [] = 0
length' (_:xs) = 1 + length' xs

sum' :: (Num a) => [a] -> a
sum' [] = 0
sum' (x:xs) = x + sum xs
