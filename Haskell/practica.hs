module Practica0 where
import Data.List (nub)
import Data.List
import Data.Char
import Language.Haskell.TH (fromE)
import Distribution.Simple.Utils (xargs)
{-
1) Los siguientes códigos tienen errores, cargar el archivo 20.Practica.0.hs en el interprete de Haskell
GHCi, leer los mensajes de error y corregirlos hasta que el archivo se cargue correctamente.
-}

-- a)
regla b = case b of
    True -> "Quedate en Casa"
    False -> "Quedate en Casa"

-- b)
case' [x]         =  []
case' (x:y:xs)      =  y : case' (x:xs)
case' []          =  []

-- c)
mymap f [] = []
mymap f (x:xs) = f x : mymap f xs

-- d)
listNumeros = 1 : 2 : 3 : []

-- e)
[] ++! ys = ys
(x:xs) ++! ys = x : xs ++! ys

-- f)
addToTail x xs = map (+x) (tail xs)

-- g)
listmin xs = (head.sort) xs

-- h) (*)
smap f [] = []
smap f [x] = [f x]
smap f (x:xs) = f x : smap f (smap f xs)

{-
2. Definir las siguientes funciones y determinar su tipo: 
a) five, que dado cualquier valor, devuelve 5
-}

five :: Num a => p -> a
five _ = 5

{-b) apply, que toma una función y un valor, y devuelve el resultado de
aplicar la función al valor dado
-}
apply :: (t1 -> t2) -> t1 -> t2
apply f x = f x

{-c) identidad, la función identidad
-}
identidad :: p -> p
identidad x = x

{-d) first, que toma un par ordenado, y devuelve su primera componente
-}
first :: p1 -> p2 -> p1
first x y =  x

{-e) derive, que aproxima la derivada de una función dada en un punto dado
-}
derive :: Fractional a => a -> (a -> a) -> a -> a
derive h f x = (f (x+h) - f x) / h

{-f) sign, la función signo
-}
sign :: (Ord a1, Num a1, Num a2) => a1 -> a2
sign n | n<0 = -1 | n > 0 = 1 | otherwise = 0

{-g) vabs, la función valor absoluto (usando sign y sin usarla)
-}
vabs :: (Ord a, Num a) => a -> a
vabs x | x < 0 = (-x) | otherwise = x
vabs2 :: (Num a1, Ord a1) => a1 -> a1
vabs2 x = x * sign x;


{-h) pot, que toma un entero y un número, y devuelve el resultado de
elevar el segundo a la potencia dada por el primero
*Eq es un tipo de dato que contiene a aquellas clases que permiten igualdad, tales como int, float, double*
-}
pot :: (Eq t, Num t, Num a) => t -> a -> a
pot 0 y = 1
pot x y = pot (x-1) y * y 


{-i) xor, el operador de disyunción exclusiva
-}
myxor :: Bool -> Bool -> Bool
myxor x y | x && y = True | x || y = True | otherwise = False

{-j) max3, que toma tres números enteros y devuelve el máximo entre ellos
-}
max3 :: Ord a => a -> a -> a -> a
max3 x y z = if x>y then if x>z then x else z else if y>z then y else z

{-k) swap, que toma un par y devuelve el par con sus componentes invertidas
-}
swap :: (b, a) -> (a, b)
swap (x,y) = (y,x)

{-
3) Definir una función que determine si un año es bisiesto o no, de
acuerdo a la siguiente definición:
Año bisiesto 1. m. El que tiene un día más que el año común, añadido al mes de febrero. Se repite
cada cuatro años, a excepción del último de cada siglo, cuyo número de centenas no sea múltiplo
de cuatro. (Diccionario de la Real Academia Espaola, 22ª ed.)
¿Cuál es el tipo de la función definida?
*Prueba el primer caso posible (más a la izquierda) y luego prueba el segundo caso
de modo que no es necesario preguntar nuevamente si es múltiplo de 100*
-}

esbisiesto :: Integral a => a -> Bool
esbisiesto n | (mod n 4 == 0) && (mod n 100 /= 0) = True | mod n 400 == 0 = True | otherwise = False

{-
4) Dar al menos dos ejemplos de funciones que tengan cada uno de los siguientes tipos:
a) (Int -> Int) -> Int
b) Int -> (Int -> Int)
c) (Int -> Int) -> (Int -> Int)
d) Int -> Bool
e) Bool -> (Bool -> Bool)
f) (Int,Char) -> Bool
g) (Int,Int) -> Int
h) Int -> (Int,Int)
i) a -> Bool
j) a -> a
-}

--a)
division f = f 1  + 1 
modulo(x,y) = mod x y;

--b)
add x y = x+y
mult x y = x*y
sumarN n = \x-> n+x;

--c)
mult3 x y z = x*y*z
funmas1 f x = f x +1

--d)
espar = even
div10 x = mod x 10 == 0

--e)
myand x y = x && y;
myxor2 x y | x && y = True | x || y = True | otherwise = False

--f)
esascii(x,c) = x == ord c
eschar(x,c) = chr x == c

--g)
primercompdiv5(x,y) = div x 5
multcomps(x,y) = div x y

--h)
dupcompmitad x = (div x 2,div x 2)
dupcompmenos5 x = (x-5, x-5)

--i)
verdad x = True
falso x = False

--j)
identidad1 x = x;
cuadrado w = cuadrado w

{-
5) Definir las siguientes funciones usando listas por comprensión:
a) 'divisors', que dado un entero positivo 'x' devuelve la
lista de los divisores de 'x' (o la lista vacía si el entero no es positivo)
b) 'matches', que dados un entero 'x' y una lista de enteros descarta
de la lista los elementos distintos a 'x'
c) 'cuadrupla', que dado un entero 'n', devuelve todas las cuadruplas
'(a,b,c,d)' que satisfacen a^2 + b^2 = c^2 + d^2,
donde 0 <= a, b, c, d <= 'n'
(d) 'unique', que dada una lista 'xs' de enteros, devuelve la lista
'xs' sin elementos repetidos
unique :: [Int] -> [Int]
-}

--a)
divisores x = [n | n <-[1..x], mod x n == 0]

--b)
matches x xs = [n | n <-xs, n == x]

--c)
cuadrupla n = [(a,b,c,d) | a<-[0..n], b<-[0..n], c<-[0..n], d<-[0..n], a^2 + b^2 == c^2 + d^2]

--d)
apariciones x [] = 0
apariciones x xs = if x == head xs then apariciones x (tail xs) + 1 else apariciones x (tail xs)

apariciones2 x xs = [y | y<-xs, y==x] == [x]

unique xs = [x | x <-xs, apariciones x xs == 1]

{-
Version de unique del profe

elem' x xs = not([y | y<-xs, e==x] == [])
drop' n xs = [x | (i,x) <- zip xs [1..], i>n]
unique' xs = [u | (i,u)<- zip xs [1..], not (elem' u (drop i xs)) ]
-}
{-
6) El producto escalar de dos listas de enteros de igual longitud
es la suma de los productos de los elementos sucesivos (misma
posición) de ambas listas.  Definir una función 'scalarProduct' que
devuelva el producto escalar de dos listas.
Sugerencia: Usar las funciones 'zip' y 'sum'. -}

--6)
scalarProduct xs ys = sum [x*y | (x, y) <- zip xs ys]

{-
7) Sin usar funciones definidas en el
preludio, defina recursivamente las siguientes funciones y
determine su tipo más general:
a) 'suma', que suma todos los elementos de una lista de números
b) 'alguno', que devuelve True si algún elemento de una
lista de valores booleanos es True, y False en caso
contrario
c) 'todos', que devuelve True si todos los elementos de
una lista de valores booleanos son True, y False en caso
contrario
d) 'codes', que dada una lista de caracteres, devuelve la
lista de sus ordinales
e) 'restos', que calcula la lista de los restos de la
división de los elementos de una lista de números dada por otro
número dado
f) 'cuadrados', que dada una lista de números, devuelva la
lista de sus cuadrados
g) 'longitudes', que dada una lista de listas, devuelve la
lista de sus longitudes
h) 'orden', que dada una lista de pares de números, devuelve
la lista de aquellos pares en los que la primera componente es
menor que el triple de la segunda
i) 'pares', que dada una lista de enteros, devuelve la lista
de los elementos pares
j) 'letras', que dada una lista de caracteres, devuelve la
lista de aquellos que son letras (minúsculas o mayúsculas)
k) 'masDe', que dada una lista de listas 'xss' y un
número 'n', devuelve la lista de aquellas listas de 'xss'
con longitud mayor que 'n' -}

--7)
--a)
sumaList [] = 0
sumaList (x:xs) = x + sumaList xs

--b)
alguno [] = False
alguno (x:xs) = x || alguno xs

--c)
todos [] = True
todos (x:xs) = x && todos xs

--d)
code y [] = 0
code y (x:xs) = if y == x then 0 else 1 + code y xs

codeabc x = code x (['a'..'n'] ++ ['ñ'] ++ ['o'..'z'] ++ ['A'..'N'] ++ ['Ñ'] ++ ['O'..'Z']) 

codes xs = [codeabc x | x<-xs]
--e)
mymodule x y | x > 0 = mymodule (x-y) y | x < 0 = x+y | x == 0 = 0

restos y [] = []
restos y (x:xs) = mymodule x y : restos y xs

--f)
cuadrados [] = []
cuadrados (x:xs) = x * x : cuadrados xs

--g)
long [] = 0
long (x:xs) = 1 + long xs

longitudes [] = []
longitudes (x:xss) = long x : longitudes xss

--h)
orden xs = [(x,y) | (x,y)<-xs, x < 3*y]

--i)
pares xs = [x | x<-xs, mymodule x 2 == 0]

--j)
letras [] = []
letras (x:xs) | x == 'ñ' || x == 'Ñ'|| x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z' = x : letras xs | otherwise = letras xs

--k)
masDe xss n = [x | x<-xss, long x > n]

{-
8) Redefinir las funciones del ejercicio anterior usando foldr, map y filter.
ver su definición en https://hoogle.haskell.org/
-}

--8)

--a)
sumafold xs = foldr (+) 0 xs 

--b)
algunofold xs = foldr (||) False xs

--c)
todosfold xs = foldr (&&) True xs

--d)
codesmap xs = map codeabc xs

--e)
restosmap y xs = map (\w-> mymodule w y) xs 

--f)
cuadradosmap xs = map (\x->x*x) xs

--g)
longitudesmap xs = map long xs

--h) Recordar que para filter las funciones deben retornar Bool
filterorden (x,y) = x<y*3
ordenfilter xs = filter filterorden xs 

--i)
paresfilter xs = filter even xs

--j)
filterletras x = x == 'ñ' || x == 'Ñ'|| x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z'
letrasfilter xs = filter filterletras xs

{-
9) Definir una funcion collect que dada una lista de tuplas (clave, valor) retorne una lista de tuplas donde 
el primer valor de la tupla sea la clave y el segundo sea la lista de valores asociados a la clave. Puede ser recursiva
y se pueden utilizar funciones auxiliares.
-}

primera [] = []
primera [(x,y)] = [x]
primera ((x,y):ol) = x : primera ol

res x ol = [y | (n,y) <- ol, n == x]

clave [] ol = []
clave [x] ol = (x, res x ol) : clave [] ol
clave (x:xs) ol = (x, res x ol) : clave xs ol

collect ol = clave (nub (primera ol)) ol




