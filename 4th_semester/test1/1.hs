primes :: [Int]
primes = sieve [2..]
    where
        sieve :: [Int] -> [Int]
        sieve (x:xs) = x : sieve [y | y <- xs, y `mod` x > 0]