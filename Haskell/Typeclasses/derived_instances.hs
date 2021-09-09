-- the data types we define can derive themselves from typeclasses already
-- defined

data Person = Person {
    firstName :: String,
    lastName :: String,
    age :: Int
} deriving (Eq, Show, Read)

-- now we can equate persons to check two variables referring to the same
-- person, assuming that no two persons have the same name and age
-- Since person is an Eq now, we can use it in all functions which require
-- an (Eq a)

p1 = Person "Ash" "Ketchum" 20
p2 = Person "Gary" "Oak" 20
pList = p1:p2:[]
res = (Person "Ash" "Ketchum" 21) `elem` pList

data Day = Monday | Tuesday | Wednesday | Thursday | Friday | Saturday |       Sunday  deriving (Eq, Ord, Show, Read, Bounded, Enum)

-- We can compare them, print them, read them
dayList = [Thursday .. Sunday]
dayList' = [minBound .. maxBound] :: [Day]
