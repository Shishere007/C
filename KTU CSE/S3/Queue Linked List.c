#include<stdio.h>

#include<stdlib.h>

void enqueue();
void dequeue();
void display();
struct node {
  int data;
  struct node * llink, * rlink;
};
typedef struct node node;
node * new = NULL, * front = NULL, * rear = NULL, * ptr;
int item;
void main() {
  char c;
  do {
    printf("\nMenu\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit..::");
    scanf("%d", & c);
    switch (c) {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    default:
      printf("\nWrong option choosed..\n");
    }
  } while (c != 4);
}
void enqueue() {
  new = (node * ) malloc(sizeof(node));
  ptr = (node * ) malloc(sizeof(node));
  printf("Element to add:");
  scanf("%d", & new -> data);
  if (front == NULL) {
    front = new;
    rear = front;
  } else {
    rear -> rlink = new;
    new -> llink = rear;
  }
  rear = new;
}
void dequeue() {
  if (front == NULL) {
    printf("\nQueue is Empty...\n");
  } else {
    item = front -> data;
    printf("\nDelete item:%d\n", item);
    if (front == rear) {
      front = NULL;
      rear = NULL;
    } else {
      front = front -> rlink;
    }
  }
}
void display() {
  ptr = front;
  if (front == NULL) printf("\nQueue is empty..\n");
  else {
    printf("\n Elements: ");
    while (ptr != NULL) {
      printf("%d\t", ptr -> data);
      ptr = ptr -> rlink;
    }
  }
}