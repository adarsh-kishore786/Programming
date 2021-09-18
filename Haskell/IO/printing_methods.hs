main = do
    -- putStrLn prints and gives a new line
    putStrLn "This is on line 1"
    putStrLn "This is on line 2"
    -- putStr just prints
    putStr "This "
    putStr "is "
    putStr "on the same line\n"
    -- putChar prints a char
    putChar 'A'
    putChar '\n'

    -- putStr is actually defined using putChar
    -- putStr :: String -> IO ()
    -- putStr [] = return ()
    -- putStr (x:xs) = do
    --      putChar(x)
    --      putStr(xs)

    -- print takes any data type under Show, calls Show on it and
    -- prints it
    print 2
    print True
    print "Strings are of Show also"
    print [1..10]
