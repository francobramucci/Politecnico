module Practica1 where

import Data.List

--1)
--a)
borrarUltimo [] = []
borrarUltimo [x] = []
borrarUltimo (x:xs) = x : borrarUltimo xs

--c)
serie [] = []
serie [x] = [] : [[x]]
serie xs = serie (borrarUltimo xs) ++ [xs]

--d)
--paresIguales a b c d = if(a == b) then funcion c d else if(a == c) then funcion b d else (funcion b c && a == d)
funcion x y = x == y

paresIguales a b c d cont = if (cont /= 0) then if(a == b) then c == d else (paresIguales a c d b (cont-1)) else False
paresIguales1 a b c d = paresIguales a b c d 4

--e)
isosceles1 x y z cont = cont /= 0 && ((x == y || y == z) || isosceles1 x z y (cont-1))
isosceles x y z = isosceles1 x y z 2

--f)
ror 0 xs = xs
ror n (x:xs) = ror (n-1) (xs ++ [x])

--g)
upto n m = if n <= m then n : upto (n+1) m else []

--h)
pos [] n = []
pos (x:xs) n = repe x (n+1) ++ pos xs (n+1)

repe x 0 = []
repe x n = x: repe x (n-1)

eco xs = pos xs 0

--2)
--a)
comp i xs = (i /= length xs -1) && (xs !! i) /= (xs !! (i+1))
cambios xs = [i | (x,i)<- zip xs [0..], comp i xs]

--b)
oblongoNumber = [y*z| (y,z)<-zip [1..][2..]]

--c)
abundancia x = sum [y | y<-[2..(x-1)], mod x y == 0]
abundantes = [x | x<-[1..], x < abundancia x ]

--d)
repet x y = [x | _<-[1..y]]
eco1 xs = [repet x y | (x,y)<-zip xs [1..]]

--e)
euler n = sum[x | x<-[1..(n-1)], mod x 3 == 0 || mod x 5 == 0]

--f)
copias x = [x | _<-[1..x]]
expandir xs = concat [copias x | x <-xs]

--3)
--a)
hola f = \x -> if x then (f 0 == 0) else True  
--b
chau x = if x then \y -> y > 5 else \y -> y > 5
--c
buenas c = if c == 'a' then 'b' else 'a'
noches c | c == 'a' = 'a'

--d
pan x f = if (f (x+1)) then [x] else [div x 2]

--e
queso (x:xs) f = [f x]

--f
leche (x:xs) f | (f (head x)) = x

--g
juan (a,b,c) = (a>5 && b/2 == 4.1 && c < 0)

--h
rasta (a,b,c) n | div n 2 == 4 = c

--i
rucu (a,b,c) n | (a == b) && (b == c) && div n 2 == 20 = a


--4 
--a foo1 :: Bool -> (Bool -> Bool)
--b foo2 :: (Int -> Int) -> (Int -> Int) -> Int  