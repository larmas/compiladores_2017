#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
  int tag;
  char id[20];
  int value;
  struct node *left;
  struct node *right;
};

typedef struct node Node;
typedef Node *node;

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

void insert(Node *raiz, Node *leafL, Node *leafR){
  raiz->left = leafL;
  raiz->right = leafR;
}

void preorden(Node *raiz){
	if( !raiz ) return;

	printf( "%i ", raiz->value );
	preorden(raiz->left);
	preorden(raiz->right);
}

int main(int argc, char const *argv[]) {
  Node *root;
  Node *left;
  Node *right;

  root = newNode(0,"pepe",10);
  left = newNode(0,"jose",20);
  right = newNode(0,"juan",30);

  insert(root,left,right);
  preorden(root);
  return 0;
}
