palindrom :: String -> Bool
palindrom [] = True
palindrom [_] = True
palindrom (x : xs) = if x == last xs then palindrom (init xs) else False
