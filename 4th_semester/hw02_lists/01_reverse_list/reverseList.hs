reverse' :: [a] -> [a]
reverse' [] = []
reverse' x = listReverser x []
    where
        listReverser :: [a] -> [a] -> [a]
        listReverser [] y = y
        listReverser (x:xs) y = listReverser xs (x:y)