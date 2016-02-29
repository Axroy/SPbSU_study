firstOccurrence :: Int -> [Int] -> Int
firstOccurrence n l = firstOccurrence' n l 1
	where
		firstOccurrence' :: Int -> [Int] -> Int -> Int
		firstOccurrence' _ [] _ = 0
		firstOccurrence' n (l : ls) count = if l == n then count else firstOccurrence' n ls (count + 1)