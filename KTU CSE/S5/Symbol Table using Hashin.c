#include<stdio.h>   
#include<string.h>
#include<stdlib.h>
#include<alloc.h>
#include<conio.h>

#define NULL 0
int size = 0;

struct SymbTab {
  char label[10];
  int addr;
  struct SymbTab * next;
};
struct SymbTab * first, * last;
int hash(int number) {
  int hash = number * 11;
  return hash;
}
int de_hash(int hash) {
  int number = hash / 11;
  return number;

}
int Search(char lab[]) {
  int i, flag = 0;
  struct SymbTab * p;
  p = first;

  for (i = 0; i < size; i++) {

    if (strcmp(p -> label, lab) == 0) 137 flag = 1;
    p = p -> next;
  }

  return flag;

}
void Insert() {
  int n;
  char l[50];
  printf("\n\tEnter the label : ");
  scanf("%s", l);
  n = Search(l);

  if (n == 1) {
    printf("\n\tThe label exists already in the symbol table\n\tDuplicate can't be inserted");
  } else {
    struct SymbTab * p, temp;
    p = malloc(sizeof(struct SymbTab));
    strcpy(p -> label, l);
    printf("\n\tEnter the address : ");
    scanf("%d", & temp);
    temp = temp * 11;
    p -> addr = temp;
    p -> next = NULL;

    if (size == 0) {
      first = p;
      last = p;

    } else {
      last -> next = p;
      last = p;

    }
    size++;

  }
  printf("\n\tLabel inserted\n");

}
void Display() {
  int i;
  struct SymbTab * p;
  p = first;
  printf("\n\tLABEL\t\tADDRESS\n");

  for (i = 0; i < size; i++) {
    printf("\t%s\t\t%d\n", p -> label, d_hash(p -> addr));
    p = p -> next;

  }

}
void Delete() {
  int a;
  char l[10];
  struct SymbTab * p, * q;
  p = first;
  printf("\n\tEnter the label to be deleted : ");
  scanf("%s", l);
  a = Search(l);

  if (a == 0) printf("\n\tLabel not found\n");

  else {

    if (strcmp(first -> label, l) == 0) 193 first = first -> next;

    else if (strcmp(last -> label, l) == 0) {
      q = p -> next;

      while (strcmp(q -> label, l) != 0) {
        p = p -> next;
        q = q -> next;

      }
      p -> next = NULL;
      last = p;

    } else {
      q = p -> next;

      while (strcmp(q -> label, l) != 0) {
        p = p -> next;
        q = q -> next;

      }
      p -> next = q -> next;

    }
    size--;
    printf("\n\tAfter Deletion:\n");
    Display();

  }

}
void main() {
  int x;
  char sr[10], y;
  clrscr();
  do {
    printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.EXIT\n");
    printf("\n\tEnter your option : ");
    scanf("%d", & x);

    switch (x) {

    case 1:
      Insert();

      break;

    case 2:
      Display();

      break;

    case 3:
      Delete();

      break;

    case 4:
      printf("\n\tEnter the label to be searched : ");
      scanf("%s", sr);
      y = Search(sr);
      printf("\n\tSearch Result:");

      if (y == 1) {
        printf("\n\tThe label is present in the symbol table\n");
      } else {
        printf("\n\tThe label is not present in the symbol table\n");
      }

      break;

    case 5:
      exit(0);

      break;

    default:
      printf("Wrong Choice/n");

    }

  } while (x < 5);
  getch();

}