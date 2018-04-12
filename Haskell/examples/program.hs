hypotenuse a b = sqrt (a ^ 2 + b ^ 2)

identifyCamel humps = if humps == 1 then "dromedary"
                                    else "Bractian"

increasing :: (Ord a) => [a] -> Bool
increasing (x:y:ys) = x <= y && increasing (y:ys)
increasing _ = True

noVowels :: String -> String
noVowels "" = ""
noVowels (x:xs)
  | x `elem` "aeiouAEIOU" = noVowels xs
  | otherwise = x : noVowels xs
           
maximum' :: (Ord a) => [a] -> a
maximum' [] = error "maximum of empty list"
maximum' [x] = x
maximum' (x:xs)
  | x > mx = x
  | otherwise = mx
  where mx = maximum' xs

