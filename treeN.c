#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
  int tag; // 0:variable, 1:int, 2:operador
  char id[20];
  int value;
  struct node *left;
  struct node *right;
}Node;


/*PROTOTIPOS*/
Node *newNode(int xTag, char xId[], int xValue);
void insertTree(Node *raiz, Node *leafL, Node *leafR);
void preorden(Node *raiz);


// Crea un nuevo nodo con toda la informacion pasada
Node *newNode(int xTag, char xId[], int xValue){
  Node *new;
  new = (Node *) malloc(sizeof(Node));

  new->tag = xTag;
  if(xId!=NULL)
    for (int i = 0; i < sizeof(new->id); i++) {
      new->id[i] = xId[i];
    }
  if(xValue!=NULL)
    new->value = xValue;
  else
    new->value = NULL;
  return new;
}

// Le inserta al nodo 'root', sus hijos izquierdo y derecho
void insertTree(Node *root, Node *leafL, Node *leafR){
  root->left = leafL;
  root->right = leafR;
}


// Recorrido preorden
void preorden(Node *raiz){
	if( !raiz ) return;
  if(raiz->value!=NULL)
	  printf( "%i ", raiz->value );
  else
    printf("%s", raiz->id);
	preorden(raiz->left);
	preorden(raiz->right);
}

/*int main(int argc, char const *argv[]) {
  Node *root;
  Node *left;
  Node *right;

  root = newNode(0,"pepe",10);
  left = newNode(0,"jose",20);
  right = newNode(0,"juan",30);

  insertTree(root,left,right);
  preorden(root);

  return 0;
}*/
