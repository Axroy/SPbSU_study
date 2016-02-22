involutionOfTwo :: Int -> [Int]
involutionOfTwo 0 = []
involutionOfTwo x = map (\x -> 2^x) (take x [1, 2..])