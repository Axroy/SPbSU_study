hasUniqueElements :: Eq a => [a] -> Bool
hasUniqueElements [] = True
hasUniqueElements (x:xs) = if not (x `elem` xs) then hasUniqueElements xs else False