#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main()
{
    int first,size;
    printf("Please enter the sequence lenght: ");
    scanf("%d",&size);
    printf("Please enter the first element: ");
    scanf("%d",&first);
    printf("\n\n----------------\n\n");
    int looplen=size/2;
    int *loop;
    //open loop array
    loop=(int*)malloc(looplen*sizeof(int)); 
    check_loop_iterative(generate_sequence,  first, size, loop,&looplen);
    //if after the check_loop function looplen is bigger than 2 there is a loop if not there is not a loop in the sequence
    if(looplen>=2)
    {
         int a;
       printf("\nLoop: {");
         for( a=0;a<looplen;a++)
        {

            printf("%d",loop[a]);
            if(a!=looplen-1)
            {
                printf(",");
            }
        } printf("}\n");

    }else
    {
           printf("\n No loop found \n");
    }
    int *h=(int *)calloc(9,sizeof(int));
    int digit=9;
 
    //this function found first digit of sequence
    hist_of_firstdigits(generate_sequence,  first, size, &h[0],digit);
    printf("\nHistogram of the sequence : {");
    for(int a=0;a<9;a++)
    {
       printf("%d",h[a]);
       if(a!=9-1)
        {
            printf(",");
        }
    }printf("}");
    free(loop);
    free(h);
}