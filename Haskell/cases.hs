-- cases do pattern matching

head' :: [a] -> a
head' xs = case xs of
     [] -> error "No head for empty lists"
     (x:_) -> x

describeList :: [a] -> String
describeList xs = "The list is " ++ case xs of
                                [] -> "empty"
                                [x] -> "a singleton list"
                                xs -> "a longer list"
