pos :: Int -> [Int] -> Int
pos _ [] = 0
pos n (l) = sum $ map (\x -> if (n == snd(x)) then fst(x) else 0) (zip [1..] l)