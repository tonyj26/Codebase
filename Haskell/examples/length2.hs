length2 :: (Num b) => [a] -> b
length2 [] = 0
length (_:xs) = 1 + length2 xs
