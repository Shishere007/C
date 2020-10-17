#include<stdio.h>

int a[100], size, top, item;
void push() {
  if (top >= size - 1) {
    printf("Stack is full\n");
  } else {
    top = top + 1;
    printf("New data:");
    scanf("%d", & item);
    a[top] = item;
    printf("The pushed item is %d\n", item);
  }
}
void pop() {
  if (top < 0) {
    printf("Stack is Empty..\n");
  } else {
    item = a[top];
    top = top - 1;
    printf("The poped item is %d\n", item);
  }
}
void display() {
  int i = top;
  if (top < 0) {
    printf("\nstack is empty");
  } else {
    printf("\nElements:");
    for (; i >= 0; --i) printf("%d\t", a[i]);
  }
  printf("\n\n");
}
void main() {
  int c;
  printf("Size of the stack:");
  scanf("%d", & size);
  top = -1;
  do {
    printf("\nMenu\n1-PUSH\n2-POP\n3-Display\n4-Stop  ::");
    scanf("%d", & c);
    switch (c) {
    case 1:
      push();
      display();
      break;
    case 2:
      pop();
      display();
      break;
    case 3:
      display();
    case 4:
      break;
    default:
      printf("Wrong option choosed..");
      break;
    }
  } while (c != 4);
}