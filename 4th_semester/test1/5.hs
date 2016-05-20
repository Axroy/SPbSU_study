rhombus :: Int -> IO ()
rhombus n = rhombus_ 0 n
            where
                buildString :: Int -> String
                buildString pos = '\n' : replicate (n - pos) ' ' ++ replicate (2 * pos - 1) '*'
            
                rhombus_ :: Int -> Int -> IO ()
                rhombus_ pos max | pos <= max = do putStrLn (buildString pos)
                                                   rhombus_ (pos + 1) max
                                 | pos <= (2 * max) && pos > max = do putStrLn (buildString (2 * max - pos))
                                                                      rhombus_ (pos + 1) max
                                 | otherwise = return ()