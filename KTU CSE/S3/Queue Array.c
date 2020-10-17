#include<stdio.h>

int q[10], rear = 0, front = 0, n = 5, item;
void enqueue(); //function prototype
void dequeue();
void display();
void main() {
  int c;
  printf("Queue limit is set to be 5..");
  do {
    printf("\nMenu\n1-Enqueuenn\n2-Dequeue\n3-Display\n4-Exit  ::");
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
      printf("Wrong option choosed");
    }
  } while (c != 4);
}
void enqueue() {
  if (rear == n) {
    printf("Queue is full..");
  } else {
    printf("Element to add:");
    scanf("%d", & item);
    if ((front == 0) && (rear == 0)) {
      front = 1;
      rear = 1;
      q[rear] = item;
    } else {
      rear = rear + 1;
      q[rear] = item;
    }
  }
}
void dequeue() {
  if (front == 0) {
    printf("Queue is empty..");
  } else {
    item = q[rear];
    if (rear == front) {
      front = 0;
      rear = 0;
    }
    elsefront = front + 1;
  }
}
void display() {
  int a, b;
  a = front;
  b = rear;
  if (front == 0) printf("Queue is empty.");
  else {
    printf("Elements::");
    while (a <= b) {
      printf("%d ", q[a]);
      a = a + 1;
    }
  }
}