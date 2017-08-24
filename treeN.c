#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
  int tag;
  char id[20];
  int value;
  struct node *left, *right;
}Node;


/*PROTOTIPOS*/
Node *newNode(int xTag, char xId[], int xValue);
void insert(Node *raiz, Node *leafL, Node *leafR);
void preorden(Node *raiz);


Node *newNode(int xTag, char xId[], int xValue){
  Node *new;
  new = (Node *) malloc(sizeof(Node));

  new->tag = xTag;

  for (int i = 0; i < sizeof(new->id); i++) {
    new->id[i] = xId[i];
  }
  new->value = xValue;
  return new;
}

void insertTree(Node *root, Node *leafL, Node *leafR){
  root->left = leafL;
  root->right = leafR;
}

void preorden(Node *raiz){
	if( !raiz ) return;

	printf( "%i\n ", raiz->value );
	preorden(raiz->left);
	preorden(raiz->right);
}
