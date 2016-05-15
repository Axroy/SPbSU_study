data Tree a = Nil 
            | Leaf a 
            | Branch (Tree a) a (Tree a)

search_ :: (a -> Bool) -> Tree a -> [a] -> [a]
search_ f Nil result = result
search_ f (Leaf l) result = if f l then l : result else result
search_ f (Branch l m r) result = if f m then m : (search_ f r (search_ f l result)) else (search_ f r (search_ f l result))

search :: (a -> Bool) -> Tree a -> [a]
search f tree = search_ f tree []

fold :: (a -> a -> a) -> a -> Tree a -> a
fold f x Nil = x
fold f x (Leaf l) = f x l
fold f x (Branch l m r) = fold f (fold f (f x m) l) r