isOpeningBracket :: Char -> Bool
isOpeningBracket x = x == '(' || x == '[' || x == '{'

isClosingBracket :: Char -> Bool
isClosingBracket x = x == ')' || x == ']' || x == '}'

sameTypeBrackets :: Char -> Char -> Bool
sameTypeBrackets x y = (x == '(' && y == ')') || (x == '[' && y == ']') || (x == '{' && y == '}')

brackets :: String -> Bool
brackets s = brackets_ s []
    where
        brackets_ :: String -> String -> Bool
        brackets_ [] [] = True
        brackets_ [] _ = False
        brackets_ (x:xs) []
            | isOpeningBracket x = brackets_ xs [x]
            | isClosingBracket x = False
            | otherwise = brackets_ xs []
        brackets_ (x:xs) (y:ys)
            | isOpeningBracket x = brackets_ xs (x:y:ys)
            | isClosingBracket x = if sameTypeBrackets y x then brackets_ xs ys else False
            | otherwise = brackets_ xs (y:ys)