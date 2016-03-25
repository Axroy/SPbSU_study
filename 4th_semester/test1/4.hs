sumDivCos :: [Float] -> Float
sumDivCos [] = 0
sumDivCos l = sum(l) / (cos' l 1)
    where
        cos' :: [Float] -> Float -> Float
        cos' [] acc = acc
        cos' (x:xs) acc = cos' xs (acc * cos(x))