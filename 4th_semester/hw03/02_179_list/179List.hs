l179 :: [Integer]
l179 = 1 : 7 : 9 : [x * 10 + y | x <- l179, y <- [1, 7, 9]]