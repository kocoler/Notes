Overview: Introduction to lisp
===

### Black-box abstraction

### Conventional interface

- generic operations
- large-scale structure and modularity
- object-oriented programming
- operations on aggregates(streams)

### Meta-Linguistic Abstraction

- Interpretation
    APPLY and EVAL
- example - logic programming
- register machines

### When we talk about language

compound-procedure

just two things: procedure and data

- Primitive elements
    
- means of combination
    operators + operands -> combination
    prefix notation

    COND; IF
- means of abstraction
    **DEFINE**
    (define (square x) (* x x)) -> sort of syntactic sugar
    the same as =>
    (define square (lambda (x) (* x x)))
    lambda -> make a procedure

    ((COND ((< x 0) (- x))
            ((= x 0) 0)
            ((> x 0) (+ x))))
    (if (< x 0)
        (- x)
        x)

    whether or not you're defining a procedure


![图 2](https://i.loli.net/2021/11/23/P4cwSyBdLOhmzDC.png)  


### Substitution model

#### Kind of expressions

- numbers
- symbols
- lambda expressions
- definitions
- conditions
- combinations

#### Substitution Rule

To evaluate an application
- evaluate the operator to get procedure
- operands to get arguments
- apply the procedure to the arguments
    BY:
    - copy the body of the procedure
        substituting the arguments supplied for the formal parameters of the procedure
    - evaluate the resulting new body
Right to Left

> if you have the name of a spirit, you have power over it


