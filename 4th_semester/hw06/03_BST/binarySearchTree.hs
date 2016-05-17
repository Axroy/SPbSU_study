data BinarySearchTree a = Empty | Node a (BinarySearchTree a) (BinarySearchTree a) deriving (Show, Eq)

size :: BinarySearchTree  a -> Int
size Empty = 0
size (Node node left right) = size left + size right + 1

height :: BinarySearchTree a -> Int
height Empty = 0
height (Node node left right) = (max (height left) (height right)) + 1

add :: (Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
add Empty x = Node x Empty Empty
add (Node node left right) value | value < node = Node node (add left value) right
                                 | value > node = Node node left (add right value)
                                 | otherwise = Node node left right
                                 
remove :: (Ord a) => BinarySearchTree a -> a -> BinarySearchTree a
remove Empty _ = Empty
remove (Node node left right) value | value < node = Node node (remove left value) right
                                    | value > node = Node node left (remove right value)
                                    | left == Empty = right
                                    | right == Empty = left
                                    | otherwise = Node (maxElement left) (remove left (maxElement left)) right where
                                        maxElement :: (Ord a) => BinarySearchTree a -> a
                                        maxElement (Node node left Empty) = node
                                        maxElement (Node node left right) = maxElement right
                                        
contains :: (Ord a) => BinarySearchTree a -> a -> Bool
contains Empty _ = False
contains (Node node left right) value | value < node = contains left value
                                      | value > node = contains right value
                                      | otherwise = True