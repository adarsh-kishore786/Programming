import qualified Data.Set as Set

-- fromList function converts a list into a Set
text1 = "I just had an anime dream. Anime...Reality... Are they so different?"
text2 = "The old man left his garbage can out and now his trash is all over my lawn!"

set1 = Set.fromList text1
set2 = Set.fromList text2

-- intersection finds the common elements between two sets
set_intersect = Set.intersection set1 set2

-- union puts together their unique elements
set_union = Set.union set1 set2

-- difference to find A / B
set_diff1 = Set.difference set1 set2
set_diff2 = Set.difference set2 set1

-- null, size, member, empty, singleton, insert, delete functions
-- behave as expected

-- Set.isSubsetOf and Set.isProperSubsetOf pretty obvious
d1 = Set.fromList [0..10]
d2 = Set.fromList [-2..2]

f :: (Num a) => a -> a
f x = x^2

r1 = Set.map f d1
r2 = Set.map f d2

-- Set.map and Set.filter are as expected
