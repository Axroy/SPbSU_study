rhombus :: Int -> IO ()
rhombus n = do
        putStrLn (rhombus_ 1 [])
        where
            buildString :: Int -> String
            buildString pos = '\n' : replicate (n - pos) ' ' ++ replicate (2 * pos - 1) '*'
            
            rhombus_ :: Int -> String -> String
            rhombus_ pos rl | pos == n = buildString pos ++ rl
                            | otherwise = buildString pos ++ rhombus_ (pos + 1) (buildString pos ++ rl)