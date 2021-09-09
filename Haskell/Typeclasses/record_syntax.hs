-- -- We've to design a Person class
-- data Person = Person String String Int Float String String deriving (Show)
-- -- First name, last nae=me, age, height, phone number, fav ice-cream flavour
--
-- guy = Person "Buddy" "Finkestein" 43 184.2 "526-2982" "Chocalate"
--
-- -- defining functions for every parameter will be a PAIN
--
-- firstName :: Person -> String
-- firstName (Person firstname _ _ _ _ _) = firstname
--
-- lastName :: Person -> String
-- lastName (Person _ lastname _ _ _ _) = lastname
--
-- age :: Person -> Int
-- age (Person _ _ age _ _ _) = age
--
-- height :: Person -> Float
-- height (Person _ _ _ height _ _) = height
--
-- phoneNumber :: Person -> String
-- phoneNumber (Person _ _ _ _ number _) = number
--
-- flavor :: Person -> String
-- flavor (Person _ _ _ _ _ flavor) = flavor

-- a much better way to define them is through record syntax

data Person = Person {
            firstName :: String,
            lastName :: String,
            age :: Int,
            height :: Float,
            phoneNumber :: String,
            flavor :: String
        } deriving (Show)
    -- this automatiacally defines getter functions for each field. Try :t
    -- with them

guy = Person "Buddy" "Finkestein" 43 184.2 "526-2982" "Chocalate"

data Car = Car {
        company :: String,
        model :: String,
        year :: Int
} deriving (Show)

ford = Car "Ford" "54A" 1952
mustang = Car {model="Mustang", year=1992, company="Ford"} -- with record syntax
-- we can specify in any order as long as we specify all of them
