### Algebraic Data Types

```haskell
data AlgDataType = Constr1 Type11 Type12
                 | Constr2 Type21
                 | Constr3 Type31 Type32 Type33
                 | Constr4
```

`AlgDataType` be declared as a new type.

```haskell
pat ::= _
     |  var
     |  var @ ( pat )
     |  ( Constructor pat1 pat2 ... patn )
```

This show how haskell do the pattern matching.

```haskell
case exp of
  pat1 -> exp1
  pat2 -> exp2
  ...
```
`case` actually is a syntactic sugar in haskell.

### Recursion patterns, polymorphism, and the Prelude

#### Recursion patterns

- map
- filter
- fold(reduce)

#### Polymorphic

```haskell
data List t = E | C t (List t)
```

Polymorphism is a property of a function that it can work with **any type**.

> One important thing to remember about polymorphic functions is that the caller gets to pick the types. When you write a polymorphic function, it must work for every possible input type. 


Functions which have certain inputs that will make them recurse infinitely are also called partial.
Functions which are well-defined on all possible inputs are known as total functions.


### Higher-order programming and type inference

#### Anonymous functions

```haskell
-- basic anonymous function
greaterThan100_2 :: [Integer] -> [Integer]
greaterThan100_2 xs = filter (\x -> x > 100) xs

-- multi parameter
(\x y z -> [x,2*y,3*z]) 5 6 3

-- particular case
-- (?x) y means \y -> y ? x
-- (x?) y means \y -> x ? y
greaterThan100_3 :: [Integer] -> [Integer]
greaterThan100_3 xs = filter (>100) xs

-- also
map (*6) [1..5]
```

#### Function composition

```haskell
gt100 :: Integer -> Bool
gt100 x = x > 100

greaterThan100 :: [Integer] -> [Integer]
greaterThan100 xs = filter gt100 xs


myTest :: [Integer] -> Bool
myTest xs = even (length (greaterThan100 xs))
-- same as
myTest' :: [Integer] -> Bool
myTest' = even . length . greaterThan100

-- '.' means
Prelude CodeWorld> :t (.)
(.) :: (b -> c) -> (a -> b) -> a -> c
```

**function application is backwards**

#### Currying and partial application

```haskell
schönfinkel :: ((a,b) -> c) -> a -> b -> c
schönfinkel f x y = f (x,y)

unschönfinkel :: (a -> b -> c) -> (a,b) -> c
unschönfinkel f (x,y) = f x y
```

#### Wholemeal programming

```haskell
foobar :: [Integer] -> Integer
foobar []     = 0
foobar (x:xs)
  | x > 3     = (7*x + 2) + foobar xs
  | otherwise = foobar xs

-- to

foobar' :: [Integer] -> Integer
foobar' = sum . map (\x -> 7*x + 2) . filter (>3)
```

> This style of coding in which we define a function without reference to its arguments—in some sense saying what a function is rather than what it does—is known as “**point-free**” style.

#### Folds

```haskell
fold :: b -> (a -> b -> b) -> [a] -> b
fold z f []     = z
fold z f (x:xs) = f x (fold z f xs)
```
