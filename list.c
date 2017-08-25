#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treeN.c"

typedef struct list {
  Node *node;
  struct list *next;
}List;

List *newList(List *l, Node *p);
void insertLast(List *l, Node *dato);
void insertFirst(List *l, Node *dato);
Node *findElem(List *p, char _id[]);
List *deleteList(List *l);
void showList(List *l);
int longList(List *l);
int deleteElem(List *p, char _id[]);


List *newList(List *l, Node *p) {
  l = (List *) malloc(sizeof(List));
  l->node = p;
  l->next = NULL;
  return l;
}


// Inserta dato al final de la lista
void insertLast(List *l, Node *dato) {
  List *p,*q;
  q = (List *) malloc(sizeof(List)); // crea un nuevo nodo
  q->node = dato; // copiar los datos
  q->next = NULL;
  /*if (l == NULL)
    return q;*/
  // la lista argumento no es vacía. Situarse en el último
  p = l;
  while (p->next != NULL)
    p = p->next;
  p->next = q;
}


// Inserta dato al comienzo de la lista
void insertFirst(List *l, Node *dato) {
  List *p,*q;
  q = (List *) malloc(sizeof(List)); // crea un nuevo nodo
  q->node = dato; // copiar los datos
  q->next = l;
  l = q;
}


// Retorna el elemento si fue en contrado en la lista (busca por id)
Node *findElem(List *p, char _id[]) {
  int cond;
  if (p == NULL){ // no hay nada que borrar
    return NULL;
  }
  cond = strcmp(p->node->id,_id); // compara el dato
  if (cond == 0) { // encontrado!
    printf("%s\n", "------");
  	return (p->node);
  } else{ // no encontrado

    return ( findElem(p->next,_id) ); // avanzo
  }
  return NULL;
}


// Elimina el elemento si se encuentra en la lista
int deleteElem(List *p, char _id[]) {
  int cond;
  if (p == NULL) // no hay nada que borrar
    return -1;

  cond = strcmp(p->node->id,_id);
  if (cond == 0) { // encontrado!
    printf("%s\n", "-----");
    List *q;
    q = p->next;
    free(p); // libera la memoria y hemos perdido el enlace, por eso se guarda en q
    p = q; // restaurar p al nuevo valor
    return 0;
  } else // no encontrado
    deleteElem(p->next,_id); // avanzo
  return -1;
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

  int main(int argc, char const *argv[]) {
  Node *root;
  Node *left;
  Node *right;

  root = newNode(0,"pepe",10);
  left = newNode(0,"jose",20);
  right = newNode(0,"juan",30);

  //insertTree(root,left,right);
  //preorden(root);

  /* Prueba lista */

  List *test;
  test = newList(test,root);
  insertLast(test,left);
  insertLast(test,right);
  Node *find;
  find = findElem(test, "pepe32");
  //printf("%s\n", find->id );
  showList(test);
  /*deleteElem(test,"pepe");
  showList(test);*/
  int length = longList(test);
  printf("%i\n", length);
  return 0;
}
