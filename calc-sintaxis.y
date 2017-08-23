%{

#include <stdlib.h>
#include <stdio.h>
#include "node.c"

%}

%union { int i; char *s; }

%token<i> INT
%token<s> ID
%token<i> VAR

%type<i> expr

%left '+'
%left '*'

%%

prog: expr ';'          { printf("%s%d\n", "Resultado: ",$1); }

    | variable ';' expr ';'
    ;

expr: INT               { $$ = $1;
                           printf("%s%d\n","Constante entera:",$1);
                        }
    | ID                {$$=0;}

    | expr '+' expr     { $$ = $1 + $3;
                          // printf("%s,%d,%d,%d\n","Operador Suma\n",$1,$3,$1+$3);
                        }
    | expr '*' expr     { $$ = $1 * $3;
                          // printf("%s,%d,%d,%d\n","Operador Producto\n",$1,$3,$1*$3);
                        }
    | '(' expr ')'              { $$ =  $2; }
    ;

variable: VAR ID '=' INT

        | variable ';' VAR ID '=' INT

   ;

%%
