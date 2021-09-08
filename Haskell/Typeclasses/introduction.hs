-- Algebraic data types are stored kinda like this
-- data Bool = False | True
-- The values associated with a typeclass is written

-- defining our Shape class
-- data Shape = Circle Float Float Float | Rectangle Float Float Float Float deriving (Show)
-- -- for a circle it is (center_x, center_y, radius)
-- -- for a rectangle, it is (top_left_x, top_left_y, bottom_right_x, bottom_right_y)
-- -- value constructors are functions like anything else
--
-- surface :: Shape -> Float
-- surface (Circle _ _ r) =  pi * r * r
-- surface (Rectangle x1 y1 x2 y2) = (abs $ x2 - x1) * (abs $ y2 - y1)

-- A better definition
data Point = Point Float Float deriving (Show)
data Shape = Circle Point Float | Rectangle Point Point deriving (Show)

surface :: Shape -> Float
surface (Circle _ r) = pi * r^2
surface (Rectangle (Point x1 y1) (Point x2 y2)) = (abs $ x2 - x1) * (abs $ y2 - y1)

nudge :: Shape -> Float -> Float -> Shape
nudge (Circle (Point x y) r) a b = Circle (Point (x+a) (y+b)) r
nudge (Rectangle (Point x1 y1) (Point x2 y2)) a b = Rectangle (Point (x1+a) (y1+b)) (Point (x2+a) (y2+b))

baseCircle :: Float -> Shape
baseCircle r = (Circle origin) r
    where origin = Point 0 0

baseRect :: Float -> Float -> Shape
baseRect width height = (Rectangle origin p) where
    origin = Point 0 0
    p = Point width height
