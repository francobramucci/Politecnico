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