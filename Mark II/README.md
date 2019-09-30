# Mark II

Next Version of the basic parser.  
This supports algebric operations, Solving system of linear equations and finding approximate roots of real equations.  
Also has some inbuilt constants, default variables and user-defined named variables.  
It can store variables in current session to a file and load it from file in a session.

### Usage

Compile main.c to executable file and run.  
Tested on GCC.

One can use 'back' or 'q' or 'Q' to go back into General Parser from linear or polynomial mode.
Use 'q' or 'Q' to quit from General Mode.

#### General Parser

Initial Screen is General Parser. It is used to solve algebric equations.
Supporeted operations are :

<ul>
<li>- for Negation</li>
<li>+ for Addition</li>
<li>- for Subtraction</li>
<li>* for Multiplication</li>
<li>/ for division</li>
<li>% for Remainder or Modulus</li>
<li>^ for Exponentiation</li>
<li> (),[],{} brackets</li>
</ul>

Enter the equation to solve,with all brackets correctly matched, the Answer will be displayed on next line.  
Use polysolve to use Polynomial solving mode, and linsolve to use Linear equation system solving mode.

##### Variables

<ul>
<li>Default Variables : $0 to $9 are defined as default variables.  Also 'Ans' is default named variable which stores values of last answer.</li>
<li>User Defined : One Can define named variables by var_name = equation.</li>
</ul>

One can use var_num = equation to save value of equation in a variable, and also use variables in equations.  
In case a variable is already defined it will ask before overwriting variables.

One can use 'help' to display help page.  
One can use 'vardump' to save variables except Ans on a file named 'vardump.log'.  
One can use 'varload' to load values of variables saved in 'vardump.log'.  
One can use 'varclear' to delete all named variables, and set values of default variables to 0.  
One can use 'showConst' and 'showVars' to display Values of constants and variables repectively.

#### Constants

| Notation | value           | info                          |
| -------- | --------------- | ----------------------------- |
| PI       | 3\.14159        | Mathematical Pi               |
| e        | 2\.71828        | Euler's Number                |
| h        | 6\.62607e\-34   | Plank's Constant              |
| hbar     | 1\.05457e\-34   | Reduced Plank's : h/\(2\*pi\) |
| N        | 6\.02214e23     | Avagadro's Number             |
| Kb       | 1\.380649e\-23  | Boltzmann Constant            |
| G        | 6\.67430e\-11   | Universal Gravitational Const |
| c        | 299792458       | Speed of Light                |
| Me       | 9\.1093837e\-31 | Mass of Elctron               |
| Mp       | 1\.6726219e\-27 | Mass of Proton                |
| Mn       | 1\.6749275e\-27 | Mass of Neutron               |
| Qe       | 1\.6021e\-19    | Elementary Charge of Electron |
| eps0     | 8\.8541878e\-12 | Vaccum Permitivitty           |
| mu0      | 1\.256637e\-6   | Vaccum Permeability           |
| R        | 8\.314463       | Universal Gas Const           |

#### Linear Equation Solver

This has two modes :

<ul>
<li>Use 'coeff' to enter equation by coefficients  </li>
<li>Use 'solve' to parse equation and solve.  </li>
</ul>
It solves the System by reducing Augmented Matrix to Upper triangular matrix.

###### coeff

Compare Equations to a1x1+a2x2+...+anxn =constant, and enter coefficients to solve the equations.  
In case System is inconsistent it will show a message saying so.

##### solve

First give number of variables and then enter equations one by one.  
It can only solve System of equations upto 9 variables,For n variables use variables x0 to xn-1.  
One can give algebric eqations containing variables and constants NOT containing x and values of them will be used.

#### Polynomial Equation Solver

This has three modes :

<ul>
<li>Use 'coeff' to enter equation by coefficients  </li>
<li>Use 'div' to divide a polynomial equation by a linear factor.  </li>
<li>Equation Parsing.</li>
</ul>
This solves the polynomial equations by Newton-Raphson Method, accurate upto approximately 0.0001.

##### Coeff

Compare Polynomial Equation to anX^n+an-1X^n-1+...+a1x+constant =0,and give coefficients.  
The real roots of equation will be displayed.If no real roots are found it will show a message saying so.

##### div

Give r of the dividing linear factor 'x-r'.
Compare Polynomial Equation to anX^n+an-1X^n-1+...+a1x+constant =0,and give coefficients.  
The division and remainder will be displayed.

#### parsing

Enter Equation in format anx^n+an-1x^n-1+...+a1x+constant = 0.  
One can give algebric eqations containing variables and constants NOT containing x and values of them will be used.  
The real roots of equation will be displayed.If no real roots are found it will show a message saying so.

### Global Variables

| config\.c  | constants\.c | inbuilt\.c | linear\.c  | linkedlist\.c | linwrap\.c | parser\.c | poly\.c | polydiv\.c | polywrap\.c | preparser\.c | queues\.c | stacks\.c | variables\.c |
| ---------- | ------------ | ---------- | ---------- | ------------- | ---------- | --------- | ------- | ---------- | ----------- | ------------ | --------- | --------- | ------------ |
| varlogFile | const_start  | file       | augmentedM | newnode       | currentEq  | postfix   | rootErr | root1      | nextStart   | infix        | cfront    | top       | var_start    |
|            | const_end    |            | tempM      | qstart        |            | linear    |         | Remainder  |             | buf          | crear     | gTemp     | var_end      |
|            |              |            | X          | rootstart     |            | poly      |         | crrPoly    |             | ASSIGN       | qTemp     | opTop     |              |
|            |              |            | numVars    | flushtemp     |            |           |         | polyQtnt   |             | DEFAULT      |           | tempOp    |              |
|            |              |            | det        | qlast         |            |           |         |            |             | EXISTING     |           | pTop      |              |
|            |              |            |            | newnodeP      |            |           |         |            |             | v_name       |           | tempP     |              |
|            |              |            |            | pstart        |            |           |         |            |             |              |           |           |              |
|            |              |            |            | last          |            |           |         |            |             |              |           |           |              |

### Functions

| config\.c  | constants\.c | help\.c  | inbuilt\.c | linear\.c         | linkedlist\.c | linwrap\.c      | main\.c                | parser\.c    | poly\.c  | polydiv\.c | polywrap\.c       | preparser\.c   | queues\.c | stacks\.c     | util\.c    | variables\.c |
| ---------- | ------------ | -------- | ---------- | ----------------- | ------------- | --------------- | ---------------------- | ------------ | -------- | ---------- | ----------------- | -------------- | --------- | ------------- | ---------- | ------------ |
| setConfig  | setConst     | showHelp | vardump    | initLinear        | pushList      | getCoeffNum     | checkExit              | priority     | root     | initPoly   | pushPolyConstTerm | initPreparse   | enQVal    | pushOp,popOp  | getCharPos | setDefVar    |
| showConfig | getConst     |          | varload    | determinant       | displayList   | setLinConstTerm | checkAndEvalInternalFn | convert      | absolute | getDivisor | pushPolyCoeff     | removeSpaces   | deQVal    | peekOp        |            | getDefVar    |
|            | initConst    |          |            | addLinCoeff       | pushRoot      | parserLinear    | polyInterface          | eval         | getSum   | polyDiv    | setPolyTerms      | checkAssign    | flushQVal | displayOp     |            | getVar       |
|            | showConst    |          |            | addLinConstTerm   | pushPolyTerm  | linearSolve     | linInterface           | bracketCheck | evalPoly | getPoly    | getPower          | loadVal        |           | pushP,popP    |            | setVar       |
|            |              |          |            | inputCoeff        | flushTermList |                 | main                   | parse        |          | displayQ   | parsePoly         | isop           |           | push,pop      |            | clearVars    |
|            |              |          |            | solveLinear       | flushRootList |                 |                        |              |          |            | solvePoly         | adjustNegetive |           | getTop,setTop |            | showVars     |
|            |              |          |            | displayLinearSoln | displayRoot   |                 |                        |              |          |            |                   | preparse       |           |               |            |              |
