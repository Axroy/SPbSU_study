data Tree a = Leaf a
            | Branch (Tree a) a (Tree a)
            
height :: Tree a -> Int
height a = height_ a 0 where
            height_ :: Tree a -> Int -> Int
            height_ (Leaf _) h = h
            height_ (Branch l x r) h = max (height_ l h) (height_ r h) + 1
            
minHeight :: Tree a -> Int
minHeight a = minHeight_ a 0 where
            minHeight_ :: Tree a -> Int -> Int
            minHeight_ (Leaf _) h = h
            minHeight_ (Branch l x r) h = min (minHeight_ l h) (minHeight_ r h) + 1