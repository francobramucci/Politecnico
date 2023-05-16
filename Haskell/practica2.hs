module Practica2 where

import Data.List

data Color = C{red :: Int, green :: Int, blue :: Int} deriving (Show)


mezclar x y = C (div ((red x)+(red y)) 2) (div ((green x) + (green y)) 2) (div (blue(x) + blue(y)) 2)

mezclar2 x y = C {red = (div ((red x)+(red y)) 2)
, green=(div ((green x) + (green y)) 2)
, blue=(div (blue(x) + blue(y)) 2)}

--data Linea = L{linea :: String, pos :: Int} deriving (Show)

data Reserv = Ins Char | D | L | R deriving Show
type Programa = [Reserv]

eval :: Reserv -> Linea -> Linea
eval (Ins c) l = insertar c l
eval D l = borrar l
eval L l = moverIzq l
eval R l = moverDer l

compilador :: Programa -> Linea -> Linea
compilador [] l = l
compilador (i:is) l = compilador is (eval i l) 



type Linea = ([Char], Int)

vacia = ([],0)

moverIzq (xs,0) = (xs, 0)
moverIzq (xs,n) = (xs, n-1)

moverDer (xs,n) | (n < length xs) = (xs, n-1) | otherwise = (xs,n)

moverIni (xs,n) = (xs,0)
moverFin (xs,n) = (xs, length xs)

borrar (xs,0) = (xs,0)
borrar (xs,n) = (bor n xs, n-1)

bor 1 (x:xs) = xs
bor n (x:xs) = x: bor (n-1) xs

{-
    bor 2 "hola"
                <def 2.bor>-- Por def 2 de bor
    'h':bor 1 ('o':"la")
                <def 1.bor>
    'h' : "la"
-}

insertar c (xs,0) = (c:xs,1)
insertar c (xs,n) = (ins n c xs, n+1)

ins 1 c (x:xs) = x:c:xs
ins n c (x:xs) = x: ins (n-1) c xs


-- Qué es un BST?

data BST a = E | N (BST a) a (BST a) 

-- E es BST
-- (N l x r) l & r son BST
-- si y e l y<= x
-- si y e r >= x
-- Se debe cumplir recursivamente

minimum N E x r = x
minimum N l x r = minimum l 

maximum N l x E = x
maximum N l x r = maximum r 


checkBST E = True
checkBST N E x E = True
checkBST N E x r = checkBST r && (minimum r) > x
checkBST N l x E = checkBST l && (maximum) <= x
checkBST N l x r = checkBST l && 
                     checkBST r &&
                     (maximum l) <= x &&
                     (minimum r) > x


insert x E = N E x E
insert x N l y r | x > y = N l y (insert x r)
                 | otherwise = N (insert x l) y r

member e E = False
member e N l y r | (e == y) = True
                 | e>y = member e r 
                 | otherwise = member e l

-- c = elemento candidato elemento que voy actualizando si e es menor o igual a la raíz. Candidato a ser igual a "e".
member2 e c E = 
member2 e c (N l y r) | e > y = member2 e c r
                      | otherwise = member2 e y l

-- member e t@(N l x r) = member2 e x t


completo e 0 = E
completo e n = N (completo e (n-1)) e (completo e (n-1)) 

completo e n = let t = completo e (n-1) in (N t e t)

