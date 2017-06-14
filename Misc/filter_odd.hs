import Data.List
import Data.Maybe

filterOdd :: [Int] -> [Int]
filterOdd [] = []
filterOdd xs = func xs 0
  where
    func :: [Int] -> Int -> [Int]
    func [] _ = []
    func (x:xs) count
      | even count = func xs (count + 1)
      | otherwise = x : func xs (count + 1)


filterOdd' :: [Int] -> [Int]
filterOdd' [] = []
filterOdd' [x] = []
filterOdd' (x:y:xs) = y : filterOdd' xs
