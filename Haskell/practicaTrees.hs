module PracticaTrees where

import Data.List

--1 
data Nat = Cero | Succ Nat deriving Show

--a) Ninguno, es un constructor

--b)
int2Nat 0 = Cero
int2Nat x = Succ(int2Nat (x-1))

--c)
suma Cero y = y
suma (Succ x) y = suma x (Succ y)

--d)
nat2Int Cero = 0
nat2Int (Succ x) = nat2Int x + 1

--e)
