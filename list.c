#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "treeN.c"

typedef struct elem{
  Node *info;
  struct elem *next;
}Elem;

typedef struct list{
  Elem *head;
  Elem *last;
  int length;
}List;


/*PROTOTIPOS*/

void initList (List *l);
int insertList (List *l, Node *p);
void showList (List * l);

void initList (List *l){
  l = (List *)malloc(sizeof(List));
  l->head = NULL;
  l->last = NULL;
  l->length = 0;
}

int insertList (List *l, Node *p){
  Elem *new_elem;
  if ((new_elem = (Elem *) malloc (sizeof (Elem))) == NULL)
    return -1;

  new_elem->info = p;
  printf("%s\n", new_elem->info->id );
  l->last->next = new_elem;
  printf("%s\n", "---- Error ^ ----");
  new_elem->next = NULL;

  l->last = new_elem;

  l->length++;
  return 0;
}

void showList (List *l){
  Elem *current;
  current = l->head;
  while (current != NULL){
      printf ("%i - %s\n", current->info->tag, current->info->id);
      current = current->next;
  }
}

int main(int argc, char const *argv[]) {
  Node *root;
  Node *left;
  Node *right;

  root = newNode(0,"pepe",10);
  left = newNode(0,"jose",20);
  right = newNode(0,"juan",30);

  insertTree(root,left,right);
  preorden(root);

  /* Prueba lista */

  List *list;
  initList(list);
  insertList(list,root);
  showList(list);
  return 0;
}
