sumOfDigits :: Int -> Int
sumOfDigits 0 = 0
sumOfDigits x = sumOfDigits (x `div` 10) + (x `mod` 10)