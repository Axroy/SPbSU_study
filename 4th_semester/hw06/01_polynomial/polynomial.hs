newtype Polynomial = Polynomial [Int]

add_ :: [Int] -> [Int] -> [Int]
add_ [] x = x
add_ x [] = x
add_ (x : xs) (y : ys) = (x + y) : (add_ xs ys)

add :: Polynomial -> Polynomial -> Polynomial
add (Polynomial p1) (Polynomial p2) = Polynomial (add_ p1 p2)

substract_ :: [Int] -> [Int] -> [Int]
substract_ [] (x : xs) = (-x) : (substract_ [] xs)
substract_ x [] = x
substract_ (x : xs) (y : ys) = (x - y) : (substract_ xs ys)

substract :: Polynomial -> Polynomial -> Polynomial
substract (Polynomial p1) (Polynomial p2) = Polynomial (substract_ p1 p2)

multiply_ :: [Int] -> [Int] -> [Int]
multiply_ [] _ = []
multiply_ _ [] = []
multiply_ (x : xs) ys = add_ (map (x *) ys) (0 : (multiply_ xs ys))
              
multiply :: Polynomial -> Polynomial -> Polynomial
multiply (Polynomial p1) (Polynomial p2) = Polynomial (multiply_ p1 p2)

showPlus :: Int -> String
showPlus x | x > 0 = "+"
           | otherwise = ""

showMonomial :: Int -> Int -> String
showMonomial 0 _ = ""
showMonomial x 0 = show x
showMonomial x 1 = showPlus x ++ show x ++ "x"
showMonomial 1 power = "+x^" ++ show power
showMonomial (-1) power = "-x^" ++ show power
showMonomial x power = showPlus x ++ show x ++ "x^" ++ show power

show_ :: [Int] -> Int -> String
show_ [] _ = ""
show_ (x : xs) power = showMonomial x power ++ show_ xs (power + 1)

instance Show Polynomial where
    show (Polynomial p) = show_ p 0
    
main = do
    putStrLn (show $ multiply (add (Polynomial[2, 0]) (Polynomial[0, 1])) (Polynomial[-2, 1]))