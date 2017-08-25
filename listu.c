#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treeN.c"

typedef struct list { 
  Node *node;
  struct list *next;
}List;

List *createList(void);
List *newList(List *l, Node *p);
List *insertLast(List *l, Node *dato);
List *insertFirst(List *l, Node *dato);
Node *findElem(List *p, char _id[]);
List *deleteList(List *l);
void showList(List *l);
int longList(List *l);
List *deleteElem(List *p, char _id[]);

// Pide memoria para la lista
List *createList(void) {
  return (List *) malloc(sizeof(List));
}

List *newList(List *l, Node *p) {
  //l = (List *) malloc(sizeof(List));
  l->node = p;
  l->next = NULL;
  return l;
}


// Inserta dato al final de la lista
List *insertLast(List *l, Node *dato) {
  List *p,*q;
  q = createList(); // crea un nuevo nodo 
  q->node = dato; // copiar los datos 
  q->next = NULL;
  if (l == NULL)
    return q;
  // la lista argumento no es vacía. Situarse en el último 
  p = l;
  while (p->next != NULL)
    p = p->next;
  p->next = q;
  return l;
}


// Inserta dato al comienzo de la lista
List *insertFirst(List *l, Node *dato) {
  List *p,*q;
  q = createList(); // crea un nuevo nodo 
  q->node = dato; // copiar los datos 
  q->next = l;
  l = q;
  return l;
}


// Retorna el elemento si fue en contrado en la lista (busca por id)
Node *findElem(List *p, char _id[]) {
  int cond;
  if (p == NULL) // no hay nada que borrar 
    return NULL;
   
  cond = strcmp(p->node->id,_id); // compara el dato
  if (cond == 0) { // encontrado! 
  	return (p->node);
  } else // no encontrado 
    return ( findElem(p->next,_id) ); // avanzo 
  return NULL;
}


// Elimina el elemento si se encuentra en la lista
List *deleteElem(List *p, char _id[]) {
  int cond;
  if (p == NULL) // no hay nada que borrar 
    return p;

  cond = strcmp(p->node->id,_id);
  if (cond == 0) { // encontrado! 
    List *q;
    q = p->next;
    free(p); // libera la memoria y hemos perdido el enlace, por eso se guarda en q 
    p = q; // restaurar p al nuevo valor 
  } else // no encontrado 
    return ( deleteElem(p->next,_id) ); // avanzo
  return p;
}


// Devuelve la longitud de una lista 
int longList(List *l) {
  List *p;
  int n;
  n = 0;
  p = l;
  while (p != NULL) {
    ++n;
    p = p->next;
  }
  return n;
}


// anula una lista liberando la memoria 
List *deleteList(List *l) {
  List *q;
  while (l != NULL) {
    q = l->next; // para no perder el nodo 
    free(l);
    l = q;
  }
  return NULL;
}


// Imprimir la lista 
void showList(List *l) {
  List *p;
  p = l;
  while (p != NULL) {
    printf("tag:%i\n",p->node->tag);
    printf("id:%s\n",p->node->id);
    printf("value: %i\n\n",p->node->value);
    p = p->next;
  }
}

/*void initList (List *l){

  l = createNode();//(List *)malloc(sizeof(List));
  l->node = NULL;
  l->next = NULL;

}*/


/*int main(int argc, char const *argv[]) {
  Node *root;
  //Node *left;
 // Node *right;

  root = newNode(0,"pepe",10);
  //left = newNode(0,"jose",20);
  //right = newNode(0,"juan",30);

  //insertTree(root,left,right);
  //preorden(root);

  /* Prueba lista /

  list *test;
  //initList(list);
  test = createNode();
  insertFirst(test,root);
  showList(test);
  return 0;
}*/