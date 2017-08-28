%{

#include <stdlib.h>
#include <stdio.h>
#include "treeN.c"
#include "list.c"

List *list;
%}

%union { int i; char *s; Node *treeN; }


%token<i> INT
%token<s> ID
%token<i> VAR

%type<treeN> expr

%left '+'
%left '*'

%%

prog: expr ';'          { printf("%s%d\n", "Resultado: ",$1);
                          preorden($1);
                        }

    | variable ';' expr ';'
    ;

expr: INT               {
                          Node *new = newNode(1,NULL,$1);
                          $$ = new;
                          printf("%s%d\n","Constante entera:",$1);
                        }
    | ID                {$$ = findElem(list, $1)}

    | expr '+' expr     {
                          Node *new = newNode(2,"+",NULL);
                          insertTree(new,$1,$3);
                          $$ = new;
                          // printf("%s,%d,%d,%d\n","Operador Suma\n",$1,$3,$1+$3);
                        }
    | expr '*' expr     {
                          Node *new = newNode(2,"*",NULL);
                          insertTree(new,$1,$3);
                          $$ = new;
                          // printf("%s,%d,%d,%d\n","Operador Producto\n",$1,$3,$1*$3);
                        }
    | '(' expr ')'              { $$ =  $2; }
    ;

variable: VAR ID '=' INT {
                            Node *dato = newNode(0,$2,$4);
                            newList(list,dato);
                          }

        | variable ';' VAR ID '=' INT {
                                        Node *dato = newNode(0,$4,$6);
                                        insertLast(list,dato);
                                      }

   ;

%%
