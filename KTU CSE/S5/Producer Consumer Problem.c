#include<stdio.h>

int mutex = 1, full = -1, empty, buffer[20];
int wait(int x) {
  return --x;
}
int signal(int x) {
  return ++x;
}
void producer() {
  int item;
  printf("Enter item to be produced");
  scanf("%d", & item);
  mutex = wait(mutex);
  full = signal(full);
  buffer[full] = item;
  empty = wait(empty);
  printf("%d produced", item);
  mutex = signal(mutex);

}
void consumer() {
  mutex = wait(mutex);
  printf("consumed %d", buffer[full]);
  empty = signal(empty);
  full = wait(full);
  mutex = signal(mutex);
}
void main() {
  int bufferSize, ch;
  printf("\nEnter buffer size");
  scanf("%d", & bufferSize);
  empty = bufferSize;
  do {
    printf("\n1.Producers\n2.Consumers\n3.Exit");
    scanf("%d", & ch);
    switch (ch) {
    case 1:
      if (mutex == 1 && empty != 0) producer();
      else printf("Buffer is full");
      break;
    case 2:

      if (mutex == 1 && full != -1) consumer();
      else {
        printf("Buffer empty");
      }
      break;
    case 3:
      exit(0);
      deafult: printf("Wrong choice!!");
    }
  } while (1);
}