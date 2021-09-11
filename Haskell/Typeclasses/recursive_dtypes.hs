-- As we've seen, a constructor in an algebraic data type can have several (or none at all) fields and each field must be of some concrete type. With that in mind, we can make types whose constructors have fields that are of the same type! Using that, we can create recursive data types, where one value of some type contains values of that type, which in turn contain more values of the same type and so on.

-- Think about this list: [5]. That's just syntactic sugar for 5:[]. On the left side of the :, there's a value and on the right side, there's a list. And in this case, it's an empty list. Now how about the list [4,5]? Well, that desugars to 4:(5:[]). Looking at the first :, we see that it also has an element on its left side and a list (5:[]) on its right side. Same goes for a list like 3:(4:(5:6:[])), which could be written either like that or like 3:4:5:6:[] (because : is right-associative) or [3,4,5,6].

-- We could say that a list can be an empty list or it can be an element joined together with a : with another list (that can be either the empty list or not).

-- data List a = Empty | Cons a (List a) deriving (Show, Read, Eq, Ord)

-- Cons is basically the ":" operator of lists. so Cons a (list a) is equivalent
-- to a : (List a). In record syntax,

-- data List a = Empty | Cons { listHead :: a, listTail :: List a } deriving (Show, Read, Eq, Ord)

-- An infixity (line 11) basically is a shorthand. So we can use :-: now instead
-- of calling the constructor by its name. The number 5 indicates its precedence
-- higher it is, more is the precedence. For example, "*" is 7 and "+" is 5, so
-- * has higher precedence (as it should have)

infixr 5 :-:
data List a = Empty | a :-: (List a) deriving (Show, Read, Eq, Ord)

list' = 3 :-: 4 :-: 5 :-: Empty

infixr 5 .++
(.++) :: List a -> List a -> List a
Empty .++ ys = ys
(x :-: xs) .++ ys = x :-: (xs .++ ys)
