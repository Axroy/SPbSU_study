data Tree a = Nil 
            | Leaf a 
            | Branch (Tree a) a (Tree a)

search :: (a -> Bool) -> Tree a -> [a]
search f Nil = []
search f (Leaf l) = if f l then [l] else []
search f (Branch l m r) = if f m then m : (search f l) ++ (search f r) else (search f l) ++ (search f r)

fold :: (a -> a -> a) -> a -> Tree a -> a
fold f x Nil = x
fold f x (Leaf l) = f x l
fold f x (Branch l m r) = fold f (fold f (f x m) l) r