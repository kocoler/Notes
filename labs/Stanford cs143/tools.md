
The Lex & Yacc Page: http://dinosaur.compilertools.net/

A compiler or interptreter for a programminning language is often decomposed into two parts:
1. Read the source program and discover its structure.
2. Process this structure, e.g. to generate the target program.

Lex and Yacc can generate program fragments that solve the first task.
The task of discovering the source structure again is decomposed into subtasks:

1. Split the source file into tokens (Lex).
2. Find the hierarchical structure of the program (Yacc).

- Lex
    Lex - A Lexical Analyzer Generator

![图 1](https://s2.loli.net/2022/04/18/DV4SjfXYmowIxF2.png)  


If you except to write a compiler from more basic layer, not using lex & yacc, you should read through: https://llvm.org/docs/tutorial/ .
