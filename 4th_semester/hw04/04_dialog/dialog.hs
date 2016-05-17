module Main
    where

import System.IO

main = do
    hSetBuffering stdin LineBuffering
    doLoop []

doLoop :: [Int] -> IO()
doLoop list = do
    putStrLn "Enter a command:"
    putStrLn "0 - exit"
    putStrLn "1 - add value to sorted list"
    putStrLn "2 - remove value from list"
    putStrLn "3 - print list"
    command <- getLine
    case command of
        '0':_ -> return ()
        '1':_ -> do doAdd list >>= \x -> doLoop(x)
        '2':_ -> do doRemove list >>= \x -> doLoop(x)
        '3':_ -> do print list
                    doLoop list
        _     -> doLoop list
        
doAdd :: [Int] -> IO [Int]    
doAdd list = do
    putStrLn "Enter value to add: "
    value <- readLn
    return (addValue list value) where
        addValue :: [Int] -> Int -> [Int]
        addValue [] value = [value]
        addValue (x:xs) value | x < value = x : (addValue xs value)
                              | otherwise = value : x : xs
                              
doRemove :: [Int] -> IO [Int]
doRemove list = do
    putStrLn "Enter value to remove: "
    value <- readLn
    return (removeValue list value) where
        removeValue :: [Int] -> Int -> [Int]
        removeValue [] _ = []
        removeValue (x:xs) value | x == value = xs
                                 | x < value = x : (removeValue xs value)
                                 | otherwise = x : xs