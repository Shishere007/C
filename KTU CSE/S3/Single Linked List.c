#include<stdio.h>

#include<stdlib.h>

struct node {
  int data;
  struct node * link;
};
struct node * first = NULL;
struct node * ptr, * ptr1, * new;
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
void firstnode();
int llcheck();
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
      ptr -> link = ptr1;
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
      ptr = ptr -> link;
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
    ptr -> link = first;
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
    while (ptr -> link != NULL) ptr = ptr -> link;
    ptr -> link = new;
    new -> link = NULL;
  }
}
void insertanypos() {
  if (first == NULL) firstnode();
  else {
    new = (node * ) malloc(sizeof(node));
    printf("Data:");
    scanf("%d", & new -> data);
    printf("After which node:");
    scanf("%d", & ptr1 -> data);
    ptr = first;
    while ((ptr -> data != key) && (ptr -> link != NULL)) ptr = ptr -> link;
    if (ptr -> data == key) {
      new -> link = ptr -> link;
      ptr -> link = new;
    }
    elseprintf("Provided key doesnt exist..!");
  }
}
void deletefront() {
  if (llcheck) {
    ptr = first -> link;
    first = ptr;
  }
}
void deleteend() {
  if (llcheck) {
    ptr = first;
    if (ptr -> link == NULL) {
      ptr = first -> link;
      first = ptr;
    } else {
      while (ptr -> link != NULL) {
        ptr1 = ptr;
        ptr = ptr -> link;
      }
      ptr1 -> link = NULL;
    }
  }
}
void deleteanypos() {
  ptr = first;
  if (ptr -> link == NULL) deletefront();
  else {
    printf("Data to delete:");
    scanf("%d", & key);
    while ((ptr -> data != key) && (ptr -> link != NULL)) {
      ptr1 = ptr;
      ptr = ptr -> link;
    }
    if ((ptr -> data == key) && (ptr -> link == NULL)) deleteend();
    else if (ptr -> data == key) ptr1 -> link = ptr -> link;
    elseprintf("Provided data doesnt exist...!");
  }
}
int llcheck() {
  if (first == NULL) printf("Linked list empty...");
  elsereturn 1;
}
void firstnode() {
  ptr = (node * ) malloc(sizeof(node));
  printf("Data:");
  scanf("%d", & ptr -> data);
  ptr -> link = NULL;
  first = ptr;
}