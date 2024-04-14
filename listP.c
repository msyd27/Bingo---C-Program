#include <stdio.h>
#include <stdlib.h>
#include "listP.h"

void print(List L) {
 int i; NodeType *p;
 printf("List is: ");  
 for (i=0,p=L.head; i<L.length; i++,p=p->next) {
   printf(" %c ", p->ch);
 }
 putchar('\n');
}

void check(int item, List L) {

}

void init(List *L, int maxSize) {
   L->length=maxSize;
   L->head=NULL;
}

int length(List L) {
return L.length;
}

void add(List *L, char c) {
  NodeType *new;
  new=(NodeType *) malloc(sizeof(NodeType));
  new->ch=c;
  new->next=L->head;
  L->head=new;
  L->length++;
}

