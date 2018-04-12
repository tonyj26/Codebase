module Main where

factorial :: (Integral a) => a -> a
factorial 0 = 1
factorial n = n * factorial (n - 1)

main :: IO ()

main = do

factorial 5
