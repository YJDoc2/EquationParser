# MARK I

This is the initial version of equation parser. It All started here.

### Supported Operations

\- : Negation (of single digit numbers only)
\+ : Addition  
\- : Subtraction  
\* : Multiplication  
/ : Division  
\% : Integer Division  
\*\* or e or E : Exponentiation

### Usage

Compile postfix.c to executable file.  
Tested on GCC.

### Global Variables

| stack\.c | valparser\.c |
| -------- | ------------ |
| in       | infix        |
| postfix  |              |
| opSt     |              |
| valArr   |              |
| evalSt   |              |
| opTop    |              |
| vTop     |              |
| eTop     |              |

### Functions

| postfix\.c | stack\.c | valparser\.c |
| ---------- | -------- | ------------ |
| priority   | pushOp   | prepParse    |
| convert    | pushVal  | parseVal     |
| eval       | pushEval |              |
| main       | popOp    |              |
|            | popVal   |              |
|            | popEval  |              |
