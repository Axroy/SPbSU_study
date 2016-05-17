sums :: Int -> [[Int]]
sums n = sums_ n n where
    sums_ :: Int -> Int -> [[Int]]
    sums_ 0 _ = [[]]
    sums_ 1 _ = [[1]]
    sums_ n m  = [(x : y) | x <- [1 .. (min n m)], y <- (sums_ (n - x) (min x m))]