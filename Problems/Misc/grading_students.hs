convertGrades :: [Int] -> [Int]
convertGrades = map convertRules

convertRules :: Int -> Int
convertRules x
  | x < 38 = x
  | findNextMultipleOfFive x - x < 3 = findNextMultipleOfFive x
  | otherwise = x


findNextMultipleOfFive :: Int -> Int
findNextMultipleOfFive x
  | x `mod` 5 == 0 = x
  | otherwise = findNextMultipleOfFive (x + 1)
