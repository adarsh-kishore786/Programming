import qualified Data.Map as Map
import Data.Char

phoneBook =
    Map.fromList
    [("betty","555-2938")
    ,("bonnie","452-2928")
    ,("patsy","493-2928")
    ,("lucille","205-2928")
    ,("wendy","939-8282")
    ,("penny","853-2492")
    ]

findKey :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey _ [] = Nothing
findKey key (ft:rest)
    | fst ft == key = Just $ snd ft
    | otherwise = findKey key rest

-- the fromList creates an actual map. In phonebook, the keys need
-- only be equatable but now they need to be orderable as well, bcz
-- the map stores them in a tree for fast retrieval. Duplicates are
-- discarded

-- empty means what it means - Map is empty
-- insert takes a (k, v) pair and a map and inserts it into the map

-- null is checking if map is empty
-- size gives size of map
size' = Map.size phoneBook

-- singleton takes a single (k, v) and creates a singleton map
map' = Map.insert 6 7 $ Map.singleton 3 9

-- Map.lookup works like the normal lookup of lists, returns Something or
-- Nothing

-- Map.map and Map.filter work like their list equivalents.
map'' = Map.map (/100) $ Map.fromList [(1, 10), (2, 20), (3, 50)]
map_ = Map.filter isUpper $ Map.fromList [(1, 'a'), (2, 'B'), (3, '*'),
            (4, 'G')]

-- toList is just inverse of fromList
list' = Map.toList $ Map.fromList [(1, 'a'), (2, 'b'), (3, 'c')]

-- Map.keys and Map.elems return the keys and values respectively of a
-- map
-- Map.keys m = map fst . Map.toList m
-- Map.elems m = map snd . Map.toList m

-- fromListWith reserves the duplicates
phoneBook' =
    [("betty","555-2938")
    ,("betty","342-2492")
    ,("bonnie","452-2928")
    ,("patsy","493-2928")
    ,("patsy","943-2929")
    ,("patsy","827-9162")
    ,("lucille","205-2928")
    ,("wendy","939-8282")
    ,("penny","853-2492")
    ,("penny","555-2111")
    ]

phoneBookToMap :: (Ord k) => [(k, String)] -> Map.Map k String
phoneBookToMap xs = Map.fromListWith (\num1 num2 -> num1 ++ ", " ++ num2) xs
-- phoneBookToMap :: (Ord k) => [(k, a)] -> Map.Map k [a]
-- phoneBookToMap xs = Map.fromListWith (++) $ map (\(k, v) -> (k, [v])) xs

-- insertWith : insert :: fromListWith : fromList. It inserts a key and if
-- that key exists already, it provides a function to accomodate the new value
map_' = Map.insertWith (+) 3 100 $ Map.fromList [(3, 4), (5, 103), (6, 339)]
