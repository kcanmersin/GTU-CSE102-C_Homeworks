#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void hist_of_firstdigits(void (*f)(int xs, int currentlen, int seqlen, int *seq), int xs, int seqlen, int *h, int digit)
{
    int seq[seqlen];
    seq[0]=xs;
    //crate sequence
    (*f)(xs,1,seqlen,&seq[0]);
    
    int number;
    for(int a=0;a<seqlen;a++)
    {
        number = seq[a];
        //divide number until it lower than 10
        while(number >= 10)
        {
        number = number / 10;
        }
        //if the remaining number is equal to the number seqrched in that round, add 1 to the h array 
        if(number==digit)
        {
            (*(h+digit-1))+=1;
           
        }
    }
    //this fucntion call itself untill digit became 0
    if(digit<=0)
    {
        return;
    }else if(digit>0)
    {
        digit=digit-1;
           hist_of_firstdigits(generate_sequence,  xs, seqlen, &h[0],digit);
    }

}
void check_loop_iterative(void (*f)(int xs, int currentlen, int seqlen, int *seq), int xs, int seqlen, int *loop,int *looplen)
{   

    int is_has_loop=0;
    int ls,le;
    int seq[seqlen];
    seq[0]=xs;
    (*f)(xs,1,seqlen,&seq[0]);
    //this if block print sequence only once because every time looplen decrease 1
    if(*looplen==seqlen/2)
    {
        printf("\nSequence : {");
          for(int a=0; a<seqlen; a++)
        {
            printf("%d",seq[a]);
            if(a!=seqlen-1)
            {
                printf(",");
            }
        }printf("}");
    }
    
    printf("\n");
    printf("Checking if there is a loop of length %d...\n",*looplen);
    is_has_loop=has_loop(&seq[0],seqlen-1,*looplen,&ls,&le);
    //if loop has found function return, if not decrease looplen 1 and call itself again until looplen==1
    if(is_has_loop==0)
    {
        *looplen=(*looplen)-1;
        if(*looplen==1)
        {
            *looplen==0;
            return ;
        }
        check_loop_iterative(generate_sequence,  xs, seqlen, loop,looplen);
    } else if(is_has_loop==1)
    {
        printf("\n Loop detecdet with a length of %d\n",*looplen);
        printf("\n The indexse of the loops first occurance: %d (first digit), %d (last digit) \n",ls,le);
      
        for(int a=ls,b=0;a<=le;a++,b++)
        {
           
           loop[b]=seq[a];

        }
        

    } 

}
int has_loop(int *arr, int n, int looplen, int *ls, int *le)
{
    int check=1;
    int a;
        //compares the minus of the last term of the array and the length of the loop
        for( a=0; a<looplen; a++)
        {
            if(arr[n-a]!=arr[n-looplen-a])
            {//if there are differences function return
               
                return 0;
            }
        }
        if(check==1)
        {
            int left=n-looplen-a+1;
            int right=n-a;
            *ls=left;
            *le=right;
            return 1;
        }

    
    return 0;
}
//generate sequence according to collatz theory formulas
void generate_sequence (int xs, int currentlen, int seqlen, int *seq)
{

    if(xs%2==1)
    {
        xs=(3*xs)+1;

        seq[currentlen]=xs;

    } else
    {
        xs=xs/2;

        seq[currentlen]=xs;
    }

    if(currentlen==seqlen-1)
    {
       
        return  ;
    } else
    {

        generate_sequence (xs,currentlen+1,seqlen,&seq[0]);

    }

}