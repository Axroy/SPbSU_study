import Data.List
import Data.Ord
import Data.Maybe

data Graph = Graph [(Int, Int)] [(Int, Int, Int)]
    deriving Show
    
infinity = maxBound :: Int    

getThird :: (Int, Int, Int) -> Int
getThird (_, _, c) = c

dijkstra :: Graph -> Int -> [(Int, Int)]
dijkstra (Graph vertices edges) start = dijkstra_ (map (\(x, y) -> if x == start then (x, 0) else (x, infinity)) vertices) edges start
    where
        dijkstra_ :: [(Int, Int)] -> [(Int, Int, Int)] -> Int -> [(Int, Int)]
        dijkstra_ [] _ _ = []
        dijkstra_ vertices edges start | length vertices == 1 = vertices
                                       | otherwise = minVertex : dijkstra_ newVertices edges (fst $ newMinVertex)
                                            where
                                                minVertex :: (Int, Int)
                                                minVertex = minimumBy (comparing snd) (vertices)
                                                
                                                newMinVertex :: (Int, Int)
                                                newMinVertex = minimumBy (comparing snd) (newVertices)
                                                
                                                getEdge :: (Int, Int) -> (Int, Int) -> Maybe(Int, Int, Int)
                                                getEdge from to = find (\(x, y, z) -> x == fst from && y == fst to || x == fst to && y == fst from) edges
                                                
                                                newVertices :: [(Int, Int)]
                                                newVertices = filter (\(x, y) -> x /= start) (updateDistances vertices minVertex)
                                                
                                                updateDistances :: [(Int, Int)] -> (Int, Int) -> [(Int, Int)]
                                                updateDistances [] _ = []
                                                updateDistances (current : rest) from = case (getEdge from current) of
                                                                                        Nothing -> current : (updateDistances rest from)
                                                                                        Just edge -> if snd from + getThird edge < snd current
                                                                                                     then (fst current, snd from + getThird edge) : (updateDistances rest from)
                                                                                                     else current : (updateDistances rest from)

-- Graph from Wikipedia's article about the algorithm                                                                                                     
wikiGraph = Graph [(1, 0), (2, 0), (3, 0), (4, 0), (5, 0), (6, 0)] 
                  [(1, 6, 14), (1, 3, 9), (1, 2, 7), (2, 3, 10), (2, 4, 15), (3, 6, 2), (3, 4, 11), (4, 5, 6), (5, 6, 9)]

main = putStrLn $ show (dijkstra wikiGraph 1)