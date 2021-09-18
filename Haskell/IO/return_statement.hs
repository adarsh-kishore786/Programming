-- The return of Haskell is nothing like the return of imperative
-- languages. It does not end execution. For example

-- main = do
--     return ()
--     return "HAHAHA"
--     line <- getLine
--     putStrLn line
--     return "BLAH BLAH"
--     putStrLn "I will execute"

-- return simply makes IO actions from data types using monads. They
-- don't do anything and are thrown away if not bound to a name

main = do
    a <- return "hell"
    b <- return "yeah!"
    putStrLn $ a ++ " " ++ b
