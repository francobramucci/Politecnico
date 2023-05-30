module PracticaTrees where

import Data.List

--1 
data Nat = Cero | Succ Nat deriving Show

--a) Succ es constructor. Succ :: Nat -> Nat

--b)
int2Nat 0 = Cero
int2Nat x = Succ(int2Nat (x-1))

--c)
suma Cero y = y
suma (Succ x) y = suma x (Succ y)

add n Cero = n
add n (Succ m) = Succ (add m n)


--d)
nat2Int Cero = 0
nat2Int (Succ x) = nat2Int x + 1

--2)

--data Arb = E | H Int | N Arb Arb deriving Show

--data Cmd = L | R deriving(Show,Eq)

--a) N :: Arb -> Arb -> Arb
--b)

-- selec xs E = E
-- selec [] arb = arb
-- selec (x:xs) (N (H a) der) = if(x == R) then selec xs der else (H a)
-- selec (x:xs) (N izq (H b)) = if(x == L) then selec xs izq else (H b)
-- selec (x:xs) (N izq der) = if(x == L) then selec xs izq else selec xs der 


-- selec [] arb = arb  
-- selec (L:xs) (N izq der) = selec xs izq
-- selec (R:xs) (N izq der) = selec xs der 

-- --c)
-- -- addToList c [] = []
-- -- addToList c (x:xs) = (c : x) : addToList c xs

-- -- enum E = []  
-- -- enum (H _) = [[]]  
-- -- enum (N izq der) = map (L:) (enum izq) ++ map (R:) (enum der)  


--4)
--a)

-- data Bin a = E | N (Bin a) a (Bin a) deriving Show

-- contar bst 0 = 1
-- contar E n = 0
-- contar (N izq x der) n = contar izq (n-1) + contar der (n-1) 

-- --b)
-- altura E = 0
-- altura (N E x E) = 0
-- altura (N izq x der) = 1 + if(altura(izq) > altura(der)) then altura izq else altura der 

-- ifbalance E = True
-- ifbalance (N izq x der) = (altura der == altura izq && ifbalance izq && ifbalance der) 

-- --c)

-- -- sucesor (N E x der) = 
-- -- sucesor (N izq x E) n = x
-- -- sucesor (N izq x der) n = if(n < x) then sucesor izq n else sucesor der n

-- bintolist E = []
-- bintolist (N izq x der) = bintolist izq ++ [x] ++ bintolist der

-- buscar [] n = 0
-- buscar (x:xs) n = if(x > n) then x else buscar xs n 

-- buscar2 [] n c = c
-- buscar2 (x:xs) n c = if(x < n && x > c) then buscar2 xs n x else buscar2 xs n c  

-- sucesor arb n = buscar (bintolist arb) n

-- antecesor arb n = buscar2 (bintolist arb) n 0

--d)
-- type Rank = Int 
-- data Heap a = E | N Rank a (Heap a) (Heap a) deriving Show

-- preorden E = []
-- preorden (N r x izq der) = [x] ++ preorden izq ++ preorden der

-- qsort [] = []
-- qsort (x:xs) = qsort chicos ++ [x] ++ qsort grandes
--     where chicos = [a | a <- xs, a <= x]
--           grandes = [b | b <- xs, b > x]

-- horden h = qsort (preorden h)

-- --e)
-- eship E = True
-- eship (N r x E E) = True
-- eship (N r x h1 E) = True
-- eship (N r x E h2) = False
-- eship (N r x h1@(N r1 x1 izq1 der1) h2@(N r2 x2 izq2 der2)) = (x < x1 && x < x2 && r1 >= r2 && eship h1 && eship h2)

-- --f)

--g)

-- data Color = R | B deriving Show
-- data RBT a = E | T Color (RBT a) a (RBT a)

-- alturab E = 0
-- alturab (T B izq der) = 1 + alturab izq
-- alturab (T R izq der) = 0 + alturab izq

-- alturablack (T R izq der) m = alturablack izq m || alturablack der m 
-- alturablack (T B izq der) m = alturablack izq (m-1) 

--esrbt (T a izq der) =  





