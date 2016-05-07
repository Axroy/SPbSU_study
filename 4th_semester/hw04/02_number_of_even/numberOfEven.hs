numberOfEven1 :: [Int] -> Int
numberOfEven1 [] = 0
numberOfEven1 l = sum $ map (\x -> if x `mod` 2 == 0 then 1 else 0) l

numberOfEven2 :: [Int] -> Int
numberOfEven2 [] = 0
numberOfEven2 l = length $ filter (\x -> x `mod` 2 == 0) l

numberOfEven3 :: [Int] -> Int
numberOfEven3 [] = 0
numberOfEven3 l = foldr (\x y -> if x `mod` 2 == 0 then y + 1 else y) 0 l