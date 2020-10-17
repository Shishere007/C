#include<stdio.h>

#include<stdlib.h>

int item;
struct node {
  int data;
  struct node * link;
};
typedef struct node node;
node * top = NULL, * ptr, * ptr1;
void push();
void pop();
void display();
void main() {
  char c;
  do {
    printf("\nMenu\n1-PUSH\n2-POP\n3-Display\n4-Stop ::");
    scanf("%d", & c);
    switch (c) {
    case 1:
      push();
      display();
      break;
    case 2:
      pop();
    case 3:
      display();
    default:
      break;
    }
  } while (c != 4);
}
void display() {
  if (top == NULL) {
    printf("\nStack is Empty.");
  } else {
    ptr = top;
    printf("\nElemets:");
    while (ptr != NULL) {
      printf("%d\t", ptr -> data);
      ptr = ptr -> link;
    }
  }
}
void push() {
  if (top == NULL) {
    ptr = (node * ) malloc(sizeof(node));
    printf("data:");
    scanf("%d", & ptr -> data);
    top = ptr;
    top -> link = NULL;
    printf("Pushed data is %d", top -> data);
  } else {
    ptr1 = (node * ) malloc(sizeof(node));
    printf("data:");
    scanf("%d", & ptr1 -> data);
    ptr1 -> link = top;
    top = ptr1;
    printf("Pushed data is %d", top -> data);
  }
}
void pop() {
  if (top == NULL) {
    printf("\nStack is Empty.");
  } else {
    printf("Poped item is %d", top -> data);
    ptr = top -> link;
    top = ptr;
  }
}