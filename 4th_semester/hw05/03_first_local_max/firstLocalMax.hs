import Control.Monad
                   
firstLocalMax :: (Ord a) => [a] -> Maybe a
firstLocalMax (x : y : z : xs) = mplus (localMax (x, y, z)) (firstLocalMax (y : z : xs)) where
    localMax :: (Ord a) => (a, a, a) -> Maybe a
    localMax (x, y, z) | x < y && z < y = Just y
                       | otherwise = Nothing
firstLocalMax _ = Nothing