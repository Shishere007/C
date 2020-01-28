#include<stdio.h>
#include<conio.h>
struct resourse{
    int a,b,c;
};
typedef struct resourse rcs;
struct process{
    int status;
    rcs alloc,max,need;
};
typedef struct process process;
rcs avlb;
rcs readrcsdata();
int workcheck(rcs);
process readprsdata(process);
void avlbUpdate();
void main(){
    process p[10];
    int nop,safe[10],i,j,ilc,pass=0;
    clrscr();
    printf("No of Process:");
    scanf("%d",&nop);
    for(i=0;i<nop;++i){
        printf("For Process %d:",i);
        p[i]=readprsdata(p[i]);
    }
    printf("Available:");
    avlb=readrcsdata();
    i=0;
    while(pass!=nop)
    {
		for(j=0;j<nop;++j)
		{
			if(p[j].status==0)
				if(workcheck(p[j].need)){
					avlbUpdate(p[j]);
					p[j].status=1;
					safe[pass]=j;
					pass++;
				}
				ilc++;
		}
		if(ilc>pass*2)
			break;
    }
    if(pass!=nop && ilc>nop-pass)
		printf("Safe Sequence Not Possible..!");
    else{
		printf("Safe Sequence Possible\n");
		printf("Additional Process\nProcess %d:",nop);
		p[nop]=readprsdata(p[nop]);
		if(workcheck(p[nop].need)){
			printf("Safe Sequence Possible \nSafe Sequence: ");
			p[nop].status=1;
			safe[pass]=nop;
			pass++;
			for(i=0;i<pass;++i)
				printf("P%d\t",safe[i]);
		}
		else
		printf("Safe Sequence Not Possible.");
    }
    getch();
}
int workcheck(rcs t){
if((t.a<=avlb.a && t.b<=avlb.b ) && t.c<=avlb.c)
    return 1;
else
    return 0;
}
rcs readrcsdata(){
    rcs t;
    printf("value of A,B,C:");
    scanf("%d%d%d",&t.a,&t.b,&t.c);
    return t;
}
process readprsdata(process t){
    printf("\nAllocation: ");
    t.alloc=readrcsdata();
    printf("Maximum: ");
    t.max=readrcsdata();
    t.need.a=t.max.a-t.alloc.a;
    t.need.b=t.max.b-t.alloc.b;
    t.need.c=t.max.c-t.alloc.c;
    t.status=0;
    return t;
}
void avlbUpdate(process t){
    avlb.a+=t.alloc.a;
    avlb.b+=t.alloc.b;
    avlb.c+=t.alloc.c;
}
