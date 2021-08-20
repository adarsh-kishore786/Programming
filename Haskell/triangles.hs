-- Find all the right angled triangles with integral sides and 24 area

all_tri = [ (a, b, c) | a <- [1..10], b <- [1..10], c <- [1..10] ]
right_t = [  (a, b, c) | c <- [1..10], b <- [1..c], a <- [1..b],             a^2 + b^2 == c^2 ]
final_t = [  (a, b, c) | c <- [1..10], b <- [1..c], a <- [1..b],             a^2 + b^2 == c^2, a + b + c == 24 ]  
