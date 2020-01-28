#include<stdio.h>
#include<conio.h>
struct dir
{
 char name[10],file[10][10];
 int size;
};
typedef struct dir dir;
void main()
{
 int nod,i,j;
 dir d[12];
 clrscr();
 printf("No of Dir:");
 scanf("%d",&nod);
 printf("Details of dir:\n");
 for(i=0;i<nod;++i)
 {
  printf("Name of Dir:");
  scanf("%s",&d[i].name);
  printf("Size of Dir:");
  scanf("%d",&d[i].size);
  printf("Files:\n");
  for(j=0;j<d[i].size;++j)
   scanf("%s",&d[i].file[j]);
 }
 printf("\n\nAvailable:\n");
 printf("Name\tsize\tfiles");
 for(i=0;i<nod;++i)
 {
  printf("\n%s\t%\d\t",d[i].name,d[i].size);
  for(j=0;j<d[i].size;++j)
  {
   printf("%s",d[i].file[j]);
   if(j!=d[i].size-1)
    printf("\n\t\t");
  }
 }
 getch();
}
