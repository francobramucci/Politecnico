module Practica2 where

import Data.List

--1)
data Color = C{red :: Int, green :: Int, blue :: Int} deriving (Show)

mezclar x y = C (div (red x+red y) 2) (div (green x + green y) 2) (div (blue x + blue y) 2)

mezclar2 x y = C {red = (div ((red x)+(red y)) 2)
, green=(div ((green x) + (green y)) 2)
, blue=(div (blue(x) + blue(y)) 2)}

type Rgb = (Int,Int,Int)

mezclart (a,b,c) (a1,b1,c1) = ((a+a1)/2,(b+b1)/2,(c+c1)/2)

type Linea = ([Char], Int)

--2)
vacia = ([],0)
moverIzq (xs, n) = if n > 0 then (xs,n-1) else (xs, n)
moverDer (xs, n) = if n < length xs then (xs, n+1) else (xs, n)
moverIni (xs, n) = (xs, 0)
moverFin (xs, n) = (xs, length xs)

-- insertar c (xs, 0) = (c:xs, 1) 
insertar c (xs, n) = (ins c xs n, n+1) 

ins c xs 0 = c : xs
ins c (x:xs) n = x : ins c xs (n-1)

borrar ((x:xs), 1) = (xs, 0)
borrar (xs, 0) = (xs, 0)
borrar (xs, n) = (bor xs n, n-1)

bor (x:xs) 1 = xs
bor (x:xs) n = x : bor xs (n-1) 

--3)
data CList a = EmptyCL | CUnit a | Consnoc a (CList a) a deriving Show

headCL (CUnit a) = CUnit a
headCL (Consnoc i clist f) = CUnit i

tailCL (CUnit a) = EmptyCL
tailCL (Consnoc i EmptyCL f) = CUnit f
tailCL (Consnoc i clist f) = Consnoc ((\(CUnit a)-> a) (headCL clist)) (tailCL clist) f  

isEmptyCL EmptyCL = True
isEmptyCL (CUnit a) = False
isEmptyCL (Consnoc a b c) = False

isCUnit EmptyCL = False
isCUnit (CUnit a) = True
isCUnit (Consnoc a b c) = False

--4

--5
data BST a = E | N (BST a) a (BST a)

maximum1 (N E x E) = x
maximum1 (N l x r) = maximum1 r

minimum1 (N E x E) = x
minimum1 (N l x r) = minimum1 l

checkBST E = True
checkBST (N E x E) = True
checkBST (N E x r) = minimum1 r > x && checkBST r
checkBST (N l x E) = maximum1 l <= x && checkBST l
checkBST (N l x r) = minimum1 r > x && maximum1 l <= x && checkBST l && checkBST r

--6
completo x 0 = E
completo x n = N (completo x (n-1)) x (completo x (n-1))

balanceado x 0 = E
balanceado x n = 


--data Linea = L{linea :: String, pos :: Int} deriving (Show)

-- data Reserv = Ins Char | D | L | R deriving Show
-- type Programa = [Reserv]

-- eval :: Reserv -> Linea -> Linea
-- eval (Ins c) l = insertar c l
-- eval D l = borrar l
-- eval L l = moverIzq l
-- eval R l = moverDer l

-- compilador :: Programa -> Linea -> Linea
-- compilador [] l = l
-- compilador (i:is) l = compilador is (eval i l) 



-- type Linea = ([Char], Int)

-- vacia = ([],0)

-- moverIzq (xs,0) = (xs, 0)
-- moverIzq (xs,n) = (xs, n-1)

-- moverDer (xs,n) | (n < length xs) = (xs, n-1) | otherwise = (xs,n)

-- moverIni (xs,n) = (xs,0)
-- moverFin (xs,n) = (xs, length xs)

-- borrar (xs,0) = (xs,0)
-- borrar (xs,n) = (bor n xs, n-1)

-- bor 1 (x:xs) = xs
-- bor n (x:xs) = x: bor (n-1) xs

-- {-
--     bor 2 "hola"
--                 <def 2.bor>-- Por def 2 de bor
--     'h':bor 1 ('o':"la")
--                 <def 1.bor>
--     'h' : "la"
-- -}

-- insertar c (xs,0) = (c:xs,1)
-- insertar c (xs,n) = (ins n c xs, n+1)

-- ins 1 c (x:xs) = x:c:xs
-- ins n c (x:xs) = x: ins (n-1) c xs


-- -- Qué es un BST?

-- data BST a = E | N (BST a) a (BST a) 

-- E es BST
-- (N l x r) l & r son BST
-- si y e l y<= x
-- si y e r >= x
-- Se debe cumplir recursivamente

-- minimum N E x r = x
-- minimum N l x r = minimum l 

-- maximum N l x E = x
-- maximum N l x r = maximum r 


-- checkBST E = True
-- checkBST N E x E = True
-- checkBST N E x r = checkBST r && (minimum r) > x
-- checkBST N l x E = checkBST l && (maximum) <= x
-- checkBST N l x r = checkBST l && 
--                      checkBST r &&
--                      (maximum l) <= x &&
--                      (minimum r) > x


-- insert x E = N E x E
-- insert x N l y r | x > y = N l y (insert x r)
--                  | otherwise = N (insert x l) y r

-- member e E = False
-- member e N l y r | (e == y) = True
--                  | e>y = member e r 
--                  | otherwise = member e l

-- -- c = elemento candidato elemento que voy actualizando si e es menor o igual a la raíz. Candidato a ser igual a "e".
-- member2 e c E = 
-- member2 e c (N l y r) | e > y = member2 e c r
--                       | otherwise = member2 e y l

-- -- member e t@(N l x r) = member2 e x t


-- completo e 0 = E
-- completo e n = N (completo e (n-1)) e (completo e (n-1)) 

-- completo e n = let t = completo e (n-1) in (N t e t)

-- data CList a = EmptyCL | CUnit a | Consnoc a (CList) a

-- [] = EmptyCL
-- [1] = CUnit 2
-- [1,2] = Conscnoc 1 EmptyCL 2
-- [1,2,3] = Consnoc 1 (CUnit 2) 3
-- [a,b,c,d] = Consnoc 'a' (Consnoc b EmptyCL c) d

-- headCL (CUnit x) = xs
-- headCL (Consoc x xs y) = x

-- tailCL (CUnit x) = x
-- tailCL (Consnoc x EmptyCL y) = CUnit y
-- tailCL (Consnoc x xs y) = Consnoc (headCL xs) (tailCL xs) y

-- reverseCL EmptyCL = EmptyCL
-- reverseCL (CUnit x) = CUnit x
-- reverseCL (Consnoc x xs y) = Consnoc y (reverseCL xs) x

-- foldr f e [] = e
-- foldr f e (x:xs) = x 'f' (foldr e xs)

-- sum = foldr (+) 0
-- -- Cuando no pongo el argumento se llama transparencia referencial

-- length'= foldr (\x xs = 1+xs) 0

-- -- Invariantes RBtree, Leftist Heaps, Heaps

-- -- Traza
-- foldr (\x xs = 1 + xs) 0 ['a':['b']] 
--                                     <por def 2.fodlr>
-- (\x xs = 1 + xs) 'a' (foldr (\x xs = 1 + xs) 0 ['b'])
-- 1 + foldr (\x xs = 1 + xs) 0 ('b':[])
--                                     <por def 2.fodlr>
-- 1 + (\x xs = 1 + xs) 'b' (foldr (\x xs = 1 + xs) 0 [])
-- 1+(1+foldr fcualquiera 0 [])
--                                     <por def 1.foldr>
-- 1+(1+0) = 2

-- --Tecnica tupling

-- balanceado 0 x= E
-- balanceado n x | even (n-1) = 
--                             let m = div (n-1) 2
--                                 t = balanceado m x
--                             in N t x t
--                | otherwise = let m = div (n-1) 2
--                              in N balanceado (m+1) x balanceado m x

-- --  otherwise lo cambio por

-- = let m = div (n-1) 2
--     (t1,t2) = balanceado' m x
--     in N t1 x t2

-- where balanceado' m x = (balanceado)

-- -- Convertir en BST 
-- -- let xs = [3,5,8,11,15,17,20,21]
-- --            0,1,2,3,4,5,6,7,8
-- -- length xs = 8;
-- -- -- Agarramos el elemento del medio (15) para balancear el arbol
-- -- 15 = xs !! div 8 2

-- -- zs = [3,5,8,11] = take 4
-- -- ys = [17,20,21] = drop (4+1) xs

-- -- N zs 15 ys

-- --Algoritmo

-- fromOrdList [] = E
-- fromOrdList xs = let n = length xs
--                      m = div n 2
--                      x = xs !! m
--                      zs = take m xs
--                      ys = drop (m+1) xs
--                      (t1,t2) = (fromOrdList zs fromOrdList ys)
--                      in N t1 x t2 


-- data Heap a = E | N a (Heap a) (Heap a)

-- xs = [2,5,4,3]

-- [N 2 E E, N 5 E E, N 4 E E, N 3 E E]
--     t1      t2        t3       t4
-- map (\x-> N x E E) xs

-- [merge t1 t2, merge t3 t4]
--      t1'           t2'
-- [merge t1' t2']
--       t1''

-- fromList [] = e
-- fromList zs = let hs = map (\x-> N x E E) zs
--                   pares [] = []
--                   pares [x]  
--                   pares (x:y:xs) = merge x y : pares xs
--                   g [] = E
--                   g [h] = h
--                   g ys = g(pares ys)
--                   in g hs


--Notas 30/05:


