import Data.Char
import Data.List
import Data.Function

res = all isAlpha "abcxyz"

group' :: [Char] -> [[Char]]
group' = filter (not. any isSpace) . groupBy ((==) `on` isSpace)

-- the GeneralCategory type class has types for spaces, letters, digits etc

-- toUpper, toLower work as they sound
-- toTitle - capitalization
-- digitToInt - Integer.parseInt from Java but works for base 16 as well
-- intToDigit - takes integer from 0..15

-- ord and chr are ASCII converters like in Python

encode :: Int -> String -> String
encode shift = map (chr . (+shift) . ord)

decode :: Int -> String -> String
decode shift = encode (negate shift)
