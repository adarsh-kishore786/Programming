-- getChar gets a single character from the terminal
import Control.Monad

-- main = do
--     c <- getChar
--     if c /= ' '
--         then do
--             putChar c
--             main
--         else do
--             putChar '\n'
--             return()

-- the when() function in Control.Monad() is useful for simulating
-- the if this then do ... else return

-- main = do
--     c <- getChar
--     when (c /= ' ') $ do
--         putChar c
--         main

-- sequence takes a list of I/O actions and returns an IO Action which will
-- perform them one after the other

-- sequence :: [IO a] -> [IO a]
main = do
    rs <- sequence [getLine, getLine, getLine]
    print rs
