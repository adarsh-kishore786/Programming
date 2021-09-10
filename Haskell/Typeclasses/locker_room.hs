-- showing the Either data type through an example
-- data Either a b = Left a | Right b deriving (Eq, Ord, Read, Show)

-- functions use it usually when returning Just or Nothing is not sufficient
-- the data type returned conveys some more info. Failures are usually
-- returned by the Left data type, and success by Right

-- An example: a high-school has lockers so that students have some place to put their Guns'n'Roses posters. Each locker has a code combination. When a student wants a new locker, they tell the locker supervisor which locker number they want and he gives them the code. However, if someone is already using that locker, he can't tell them the code for the locker and they have to pick a different one. We'll use a map from Data.Map to represent the lockers. It'll map from locker numbers to a pair of whether the locker is in use or not and the locker code.

import qualified Data.Map as Map

data LockerState = Taken | Free deriving (Show, Eq)
type Code = String
type LockerMap = Map.Map Int (LockerState, Code)

lockerLookup :: Int -> LockerMap -> Either String Code
lockerLookup lockerNumber l_map =
    case Map.lookup lockerNumber l_map of
        Nothing -> Left $ "Locker number " ++ show lockerNumber ++ " doesn't exist!"
        Just (state, code) -> if state /= Taken
                                then Right code
                                else Left $ "Locker " ++ show lockerNumber ++ " is already taken!"

lockers :: LockerMap
lockers = Map.fromList
    [(100,(Taken,"ZD39I"))
    ,(101,(Free,"JAH3I"))
    ,(103,(Free,"IQSA9"))
    ,(105,(Free,"QOTSA"))
    ,(109,(Taken,"893JJ"))
    ,(110,(Taken,"99292")) ]
