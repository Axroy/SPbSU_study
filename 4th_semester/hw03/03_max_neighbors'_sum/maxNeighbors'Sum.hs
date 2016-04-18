import Data.Ord (comparing)
import Data.List (maximumBy)

maxSumPos :: [Int] -> Int
maxSumPos list = fst $ maximumBy (comparing snd) $ reverse indexedSums where 
                                                        indexedSums = [(fst(x) - 1, snd(x) + snd(y)) | x <- indexedList, y <- indexedList, fst(x) - fst(y) == 2]
                                                        indexedList = zip [1..] list                                                                                               