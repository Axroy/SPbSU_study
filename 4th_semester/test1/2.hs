matrixList :: Int -> Int -> Int -> [Int]
matrixList line n i = if i < line then line : matrixList line n (i + 1)
                      else if i >= line && i < n then (i + 1) :matrixList line n (i + 1)
                      else []

cornerMatrixBuilder :: Int -> Int -> [[Int]]
cornerMatrixBuilder n i = if i <= n then matrixList i n 0 : cornerMatrixBuilder n (i + 1)
                          else []
                      
cornerMatrix :: Int -> [[Int]]
cornerMatrix 0 = []
cornerMatrix n = cornerMatrixBuilder n 1