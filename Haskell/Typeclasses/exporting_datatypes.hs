-- We can export the data types which we create
module Complex
(
    Complex(..), -- signature of a data type
    add,
    mul,
    mod',
    arg,
) where

data Complex = Complex Float Float deriving (Show)

add :: Complex -> Complex -> Complex
add (Complex x1 y1) (Complex x2 y2) = Complex (x1+x2) (y1+y2)

mul :: Complex -> Complex -> Complex
mul (Complex x1 y1) (Complex x2 y2) =
    Complex (x1 * x2 - y1 * y2) (x1 * y2 + x2 * y1)

mod' :: Complex -> Float
mod' (Complex x y) = sqrt $ x^2 + y^2

arg :: Complex -> Float
arg (Complex x y)
    | x >= 0 && y >= 0 = theta
    | x <= 0 && y >= 0 = pi - theta
    | x <= 0 && y <= 0 = theta - pi
    | x >= 0 && y <= 0 = -theta
    where theta = atan $ abs y/x
