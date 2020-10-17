#include<stdio.h>

#include<stdlib.h>

struct node {
  int data;
  struct node * rlink, * llink;
};
struct node * first = NULL, * ptr, * ptr1, * new, * ptr2;
int key;
typedef struct node node;
void create();
void traverse();
void insertfront();
void insertend();
void insertanypos();
void deletefront();
void deleteend();
void deleteanypos();
int llcheck();
void firstnode();
void main() {
  int op;
  create();
  traverse();
  do {
    printf("\n1-Insert at front\n2-Insert at end\n3-Insert at any position\n4-Delete from front\n5-Delete from end\n6-Delete from any position\n7-Disalay\n8-Exit:");
    scanf("%d", & op);
    switch (op) {
    case 1:
      insertfront();
      traverse();
      break;
    case 2:
      insertend();
      traverse();
      break;
    case 3:
      insertanypos();
      traverse();
      break;
    case 4:
      deletefront();
      traverse();
      break;
    case 5:
      deleteend();
      traverse();
      break;
    case 6:
      deleteanypos();
      traverse();
      break;
    case 7:
      traverse();
    case 8:
      break;
    default:
      printf("Wrong option choosed..!");
    }
  } while (op != 8);
}
void create() {
  char c;
  do {
    if (first == NULL) firstnode();
    else {
      ptr1 = (node * ) malloc(sizeof(node));
      printf("Data:");
      scanf("%d", & ptr1 -> data);
      ptr1 -> llink = ptr;
      ptr -> rlink = ptr1;
      ptr1 -> rlink = NULL;
      ptr = ptr1;
    }
    printf("Add more nodes(y/n):");
    scanf("%s", & c);
  } while (c == 'y' || c == 'Y');
}
void traverse() {
  ptr = first;
  if (ptr != NULL) {
    printf("Datas in linked list:\n");
    while (ptr != NULL) {
      printf("%d\t", ptr -> data);
      ptr = ptr -> rlink;
    }
  }
  elseprintf("List is empty..");
}
void insertfront() {
  if (first == NULL) firstnode();
  else {
    ptr = (node * ) malloc(sizeof(node));
    printf("Data:");
    scanf("%d", & ptr -> data);
    ptr -> llink = NULL;
    ptr -> rlink = first;
    first -> llink = ptr;
    first = ptr;
  }
}
void insertend() {
  if (first == NULL) firstnode();
  else {
    new = (node * ) malloc(sizeof(node));
    printf("Data:");
    scanf("%d", & new -> data);
    ptr = first;
    while (ptr -> rlink != NULL) ptr = ptr -> rlink;
    ptr -> rlink = new;
    new -> llink = ptr;
    new -> rlink = NULL;
  }
}
void insertanypos() {
  if (first == NULL) firstnode();
  else {
    new = (node * ) malloc(sizeof(node));
    printf("Data:");
    scanf("%d", & new -> data);
    printf("After which node:");
    scanf("%d", & key);
    ptr = first;
    while ((ptr -> data != key) && (ptr -> rlink != NULL)) ptr = ptr -> rlink;
    if (ptr -> data == key) {
      ptr1 = ptr -> rlink;
      ptr -> rlink = new;
      new -> llink = ptr;
      new -> rlink = ptr1;
      ptr1 -> llink = new;
    }
    elseprintf("Provided key doesnt exist..!");
  }
}
void deletefront() {
  if (llcheck) {
    ptr = first -> rlink;
    ptr -> llink == NULL;
    first = ptr;
  }
}
void deleteend() {
  if (llcheck) {
    ptr = first;
    if (ptr -> rlink == NULL) deletefront();
    else {
      while (ptr -> rlink != NULL) {
        ptr1 = ptr;
        ptr = ptr -> rlink;
      }
      ptr1 -> rlink = NULL;
    }
  }
}
void deleteanypos() {
  ptr = first;
  if (llcheck) {
    if (ptr -> rlink == NULL) deletefront();
    else {
      printf("Data to delete:");
      scanf("%d", & key);
      ptr = first;
      while ((ptr -> data != key) && (ptr -> rlink != NULL)) {
        ptr1 = ptr;
        ptr = ptr -> rlink;
      }
      if ((ptr -> data == key) && (ptr -> rlink == NULL))
        deleteend();
      else if (ptr -> data == key) {
        ptr2 = ptr -> rlink;
        ptr1 -> rlink = ptr2;
        ptr2 -> llink = ptr1;
      }
      elseprintf("Provided data doesnt exist...!");
    }
  }
}
int llcheck() {
  if (ptr == NULL) printf("Liked list empty...");
  elsereturn 1;
}
void firstnode() {
  ptr = (node * ) malloc(sizeof(node));
  printf("Data:");
  scanf("%d", & ptr -> data);
  ptr -> rlink = NULL;
  ptr -> llink = NULL;
  first = ptr;
}