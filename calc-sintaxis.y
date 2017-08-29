%{

#include <stdlib.h>
#include <stdio.h>
#include "list.c"

List *list;
%}

%union { int i; char *s; struct Node *treeN; }


%token<i> INT
%token<s> ID
%token<i> VAR

%type<treeN> expr

%left '+'
%left '*'

%%

prog: expr ';'          {
                          printf("%s\n", "Recorrido....");
                          dfs($1);
                          printf("\n");
                          printf("%s\n\n", "Evaluar....");
                          int result = valueExpr($1);
                          printf("%i\n", result);
                        }

    | variable ';' expr ';' {
                              printf("%s\n", "Recorrido....");
                              dfs($3);
                              printf("\n");
                              printf("%s\n", "Evaluar....");
                              int result = valueExpr($3);
                              printf("%i\n", result);
                            }
    ;

expr: INT               {
                          Node *new = newNode(1,NULL,$1);
                          $$ = new;
                          //printf("%s%d\n","Constante entera:",$1);
                        }
    | ID                {
                          Node *new = findElem(list, $1);
                          printf("Buscado: %s\n", new->id);
                          $$ = new;
                        }

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
                            list = newList(list,dato);
                          }

        | variable ';' VAR ID '=' INT {
                                        Node *dato = newNode(0,$4,$6);
                                        insertLast(list,dato);
                                      }

   ;

%%
int valueExpr(Node *root){
    if(root->tag == 1){
        return root->value;
    }
    if(root->tag == 2){
        int cond1 = strcmp(root->id,"+");
        if(cond1 == 0){
            return valueExpr(root->left) + valueExpr(root->right);
        }
        int cond2 = strcmp(root->id,"*");
        if(cond2 == 0){
            return valueExpr(root->left) * valueExpr(root->right);
        }
    }
    if(root->tag == 0){
        return root->value;
    }
}
