#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
char opcode[10],mnemonic[10],operand[10],label[10],code[10];
int locctr,start,length;FILE *fp1,*fp2,*fp3,*fp4;
fp1=fopen("sourceFile.txt","r");
fp2=fopen("symtab.txt","w");
fp3=fopen("out.txt","w");
fp4=fopen("optab.txt","r"); 
fscanf(fp1,"%s%s%s",label,opcode,operand);
if(strcmp(opcode,"START")==0)
{
	start=atoi(operand);
	locctr=start;
	fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);
	fscanf(fp1,"%s%s%s",label,opcode,operand);
	printf("%s\t%s\t%s\n",label,opcode,operand);
	scanf("%s%s%s",label,opcode,operand);
}
else
	locctr=0;
while(strcmp(opcode,"END")!=0)
{
	printf("%d\t",locctr);
	fprintf(fp3,"%d\t",locctr);
	if(strcmp(label,"**")!=0)
		fprintf(fp2,"%s\t%d\n",label,locctr);
	rewind(fp4);fscanf(fp4,"%s",mnemonic);
	while(strcmp(mnemonic,"END")!=0)
	{
		if(strcmp(opcode,mnemonic)==0)
		{
			locctr+=3;
			break;
		}
		fscanf(fp4,"%s",mnemonic);

} 
if(strcmp(opcode,"WORD")==0)
	locctr+=3;
else if(strcmp(opcode,"RESW")==0)
	locctr+=(3*(atoi(operand)));
else if(strcmp(opcode,"RESB")==0)
	locctr+=(atoi(operand));
else if(strcmp(opcode,"BYTE")==0)
	++locctr;
fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);
fscanf(fp1,"%s%s%s",label,opcode,operand);
}
fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
length=locctr-start;
printf("\nThe length of the program is %d",length);
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4); 
}

