import qualified Data.Map as Map
-- the Functor class maps a function over a collection. It takes the
-- function from one type to another type.
-- for example, the "map" function is really a functor which maps
-- a function over a list to simply produce a list of another type

res = map (foldl1 (++) . \x -> map (\y -> y ++ " ") x) [["He", "is", "a", "boy"], ["She", "is", "a", "girl"]]

-- This basically produces ["He is a boy ","She is a girl "].
-- So the list type changed from [[String]] to [String]. Here map is acting
-- as a functor which takes a function and a list of one type [[String]]
-- and applies that function to the list to make it of a different type
-- [String]

-- We could write in this case
-- map :: ([String] -> String) -> [[String]] -> [String]
-- We see that the function here is simply the [] list constructor
-- map :: (List String -> String) -> List (List String) -> List String

-- the fmap function defined in the Functor class is simply a generalization of
-- this to an arbitrary function and data

-- class Functor f where
--      fmap :: (a -> b) -> f a -> f b

-- map is map :: (a -> b) -> [a] -> [b]
-- instance Functor [] where
--      fmap = map

-- map is fmap over lists only, simply
-- now we can define new, more useful fmaps over the plain old map, like

-- instance Functor Maybe where
--     fmap f (Just x) = Just (f x)
--     fmap _ Nothing = Nothing

data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show, Read, Eq)

singleton :: a -> Tree a
singleton x = Node x EmptyTree EmptyTree

treeInsert :: (Ord a) => a -> Tree a -> Tree a
treeInsert x EmptyTree = singleton x
treeInsert x (Node a left right)
    | x == a = Node x left right
    | x < a  = Node a (treeInsert x left) right
    | x > a  = Node a left (treeInsert x right)

instance Functor Tree where
    fmap f EmptyTree = EmptyTree
    fmap f (Node x leftTree rightTree) = Node (f x) (fmap f leftTree) (fmap f rightTree)

m = Map.fromList [('A', 65), ('B', 66), ('C', 67)]

-- A Functor over Map
-- instance Functor (Map.Map a) where
--     fmap = Map.map
