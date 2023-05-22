module PracticaTrees where

import Data.List

--1 
data Nat = Cero | Succ Nat deriving Show

--a) Succ es constructor

--b)
int2Nat 0 = Cero
int2Nat x = Succ(int2Nat (x-1))

--c)
suma Cero y = y
suma (Succ x) y = suma x (Succ y)

--d)
nat2Int Cero = 0
nat2Int (Succ x) = nat2Int x + 1

--2)

data Arb = E | H Int | N Arb Arb deriving Show

data Cmd = L | R deriving(Show,Eq)

--a) N es constructor
--b)

-- selec xs E = E
-- selec [] arb = arb
-- selec (x:xs) (N (H a) der) = if(x == R) then selec xs der else (H a)
-- selec (x:xs) (N izq (H b)) = if(x == L) then selec xs izq else (H b)
-- selec (x:xs) (N izq der) = if(x == L) then selec xs izq else selec xs der 


selec [] arb = arb  
selec (L:xs) (N izq der) = selec xs izq
selec (R:xs) (N izq der) = selec xs der 

enum (N E (H b)) = 
enum (N (H a) E) = 
enum (N izq der) = L : enum izq 



