import qualified Data.Map as Map

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
