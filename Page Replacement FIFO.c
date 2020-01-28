#include<stdio.h>
void main(){
    int string[30],loopVar,loopVar2,frame[10] ,hit = 0,fault = 0;
    int stringC,current = 0,frameC,found;
    printf("Number of Frames:");
    scanf("%d",&frameC);
    printf("Page count:");
    scanf("%d",&stringC);
    printf("pages:");
    for (loopVar = 0;loopVar < stringC; loopVar++)
        scanf("%d",&string[loopVar]);
    for (loopVar = 0;loopVar < frameC; loopVar++)
        frame[loopVar] = -1;
    for (loopVar = 0;loopVar < frameC; loopVar++)
         printf ("%d",frame[loopVar]);
    for (loopVar = 0;loopVar < stringC; loopVar++){
        found = 0;
        for (loopVar2 = 0;loopVar2 < frameC ; ++loopVar2)
             if (frame[loopVar2] == string[loopVar]){
                hit++;
                found = 1;
                break;
            }
        if (found == 0){
            frame[current] = string[loopVar];
            fault++;
            if (current < frameC - 1)
                current++;
            else
                current = 0;
        }}
    printf("\nfault=%d\nHit=%d",fault,hit);
}   
