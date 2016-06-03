import Prelude hiding (id)
import Data.List
import Data.Ord
import Data.Maybe
import Control.Monad.Writer

data Edge = Edge {
    from :: Int,
    to :: Int,
    value :: Int
}

instance Show Edge where
    show (Edge from to value) = show from ++ "-" ++ show to

data Vertex = Vertex {
    id :: Int,
    path :: Writer [(Edge, String)] Int
}

instance Eq Vertex where
    (==) a b = id a == id b
    
instance Ord Vertex where
    compare (Vertex _ a) (Vertex _ b) = compare (fst $ runWriter a) (fst $ runWriter b)
    
instance Show Vertex where
    show (Vertex id path) = "\n\n(" ++ show id ++ ":" ++ show (fst $ runWriter path) ++ ", " ++ "Seen edges:" ++ show (snd $ runWriter path) ++ ")"

data Graph = Graph [Vertex] [Edge]
    deriving Show
    
infinity = maxBound :: Int    

dijkstra :: Graph -> Int -> [Vertex]
dijkstra (Graph vertices edges) start = dijkstra_ vertices edges start
    where
        dijkstra_ :: [Vertex] -> [Edge] -> Int -> [Vertex]
        dijkstra_ [] _ _ = []
        dijkstra_ vertices edges start | length vertices == 1 = vertices
                                       | otherwise = minVertex : dijkstra_ newVertices edges (id newMinVertex)
                                            where
                                                minVertex :: Vertex
                                                minVertex = minimum vertices
                                                
                                                newMinVertex :: Vertex
                                                newMinVertex = minimum newVertices
                                                
                                                getEdge :: Vertex -> Vertex -> [Edge] -> Maybe(Edge)
                                                getEdge _ _ [] = Nothing
                                                getEdge fromV toV (current : rest) | id fromV == from current && id toV == to current = Just current
                                                                                   | id fromV == to current && id toV == from current = Just current
                                                                                   | otherwise = getEdge fromV toV rest
                                                
                                                newVertices :: [Vertex]
                                                newVertices = filter (\x -> (id x) /= start) (updateDistances vertices minVertex)
                                                
                                                doEdge :: Writer [(Edge, String)] Int -> Writer [(Edge, String)] Int -> Edge -> Writer [(Edge, String)] Int
                                                doEdge wr1 wr2 e = do
                                                    v1 <- wr1
                                                    v2 <- wr2
                                                    if v1 + (value e) < v2
                                                    then do 
                                                        tell ((e, "Updated distance to " ++ show (to e)) : [])
                                                        return (v1 + (value e))
                                                    else do
                                                        tell ((e, "No changes") : [])
                                                        return v2
                                                
                                                updateDistances :: [Vertex] -> Vertex -> [Vertex]
                                                updateDistances [] _ = []
                                                updateDistances (toV : rest) fromV = case (getEdge fromV toV edges) of
                                                                                        Nothing -> toV : (updateDistances rest fromV)
                                                                                        Just edge -> (min (Vertex (id toV) (doEdge (path fromV) (path toV) edge)) toV) : (updateDistances rest fromV)
                                                                                                     

-- Graph from Wikipedia's article about the algorithm                                                                                                     
wikiGraph = Graph [(Vertex 1 (writer (0, []))), (Vertex 2 (writer (infinity, []))), (Vertex 3 (writer (infinity, []))), (Vertex 4 (writer (infinity, []))), (Vertex 5 (writer (infinity, []))), (Vertex 6 (writer (infinity, [])))] 
                  [(Edge 1 6 14), (Edge 1 3 9), (Edge 1 2 7), (Edge 2 3 10), (Edge 2 4 15), (Edge 3 6 2), (Edge 3 4 11), (Edge 4 5 6), (Edge 5 6 9)]

main = putStrLn $ show (dijkstra wikiGraph 1)