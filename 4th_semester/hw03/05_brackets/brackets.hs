brackets :: String -> Bool
brackets s = brackets_ s 0 where
                brackets_ :: String -> Int -> Bool
                brackets_ [] 0 = True
                brackets_ [] _ = False
                brackets_ (s:xs) x = if s == ')' then if x == 0 then False else brackets_ xs (x - 1) 
                                     else if s == '(' then brackets_ xs (x + 1) 
                                     else brackets_ xs x