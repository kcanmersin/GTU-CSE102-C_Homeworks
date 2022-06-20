#include <stdio.h>
#include <stdlib.h>
#define STACK_BLOCK_SIZE 10
typedef struct stack
{
    int * array;
    int currentsize;
    int maxsize;
    int stack_number;
} stack;
int stack_number=1;//1 is the left, 2 is the middle 3 is the rightest stack
int move_counter=0;
int * resize(stack *s);
stack * init_return();/* initializes an empty stack */
void push(stack * s, int d); /* the stack array will grow STACK_BLOCK_SIZE entries at
a time */
int pop(stack * s); /* the stack array will shrink STACK_BLOCK_SIZE entries at a
time */
void start_game(int towersize,stack *s1,stack *s2, stack *s3);
int try(int s ,int val, int even, stack *st);
int init(stack *s);
void shift(stack *from , stack *this);
int main ()
{
    //empty stacks crated//
    stack *s1,*s2,*s3;
    s1=init_return();
    s2=init_return();
    s3=init_return();
    
    printf("  *    ***********************************   *   \n * *   * Welcome to the Hanoi Tower Game *  * *\n* * *  *********************************** * * *\n");
    int tower_size;
    printf("Enter Tower Size bigger then 3 :\n");
    scanf("%d",&tower_size);
    if(tower_size<=2)
    {
        printf("\nPlease enter number bigger then 3!!\n");
        return 0;
    }
    //place disk to the first stack
    for(int a=tower_size; a>0; a--)
    {
        
        push(s1,a);
     
    }
   
    start_game(tower_size,s1,s2,s3); 
    free(s1);
    free(s2);
    free(s3);

}
//this initialize empty stack//
stack * init_return()
{
    stack *new=(stack*)malloc(sizeof(stack));
    int control=0;
    control=init(new);
    if(control==-1)
    {   //i only use recursion here. it is not affect my algorithm
        init_return();
    }
    new->currentsize=0;
    new->maxsize=STACK_BLOCK_SIZE;
    new->stack_number=stack_number;
    stack_number++;
    new->array=(int*)calloc(sizeof(int),STACK_BLOCK_SIZE);

    return new;

} 
//if malloc return 0 this funciton return -1 
int init(stack *s)
{

    if(s==NULL)
    {
        return -1;
    }
    return 1;
}
//this fucntion try it can be place disk to the ts(Target Stack), if it can replace it return 1
int try(int s ,int val, int even, stack *ts)
{
    if(ts->currentsize==0)
    {
        return 1;
    }
    if(val<ts->array[ts->currentsize-1])
    {
        return 1;
    } else
    {
        return -1;
    }
}
//this function apply pop and push action
void shift(stack *from , stack *this)
{
    int value;
    value=pop(from);
    push(this,value);
   printf(" '%d'\n",this->stack_number);


}
void start_game(int towersize,stack *s1,stack *s2, stack *s3)
{
    int value=-1;
    int control=0;//this variable is control disk replaced or not
    int last_put=0;//this variable is for prevent take again the last disk

    if(towersize%2==1)
    {
        do
        {   
            //take first stacks last entry end looks for first third stack then second stack to replace
            value=s1->array[s1->currentsize-1];
            control=try(0,value,0,s3);
            if(last_put!=value && value!=0)
            {
                if(control==1)
                {
                    shift(s1,s3);
                    last_put=value;
                } else
                {
                    control=try(0,value,0,s2);
                    if(control==1)
                    {
                        shift(s1,s2);
                        last_put=value;
                    }
                }
            }
            //take second stacks last entry end looks for first first stack then third stack to replace

            value=s2->array[s2->currentsize-1];
            control=try(0,value,0,s1);
            if(last_put!=value && value!=0)
            {
                if(control==1)
                {
                    shift(s2,s1);
                    last_put=value;
                } else
                {
                    control=try(0,value,0,s3);
                    if(control==1)
                    {
                        shift(s2,s3);
                        last_put=value;
                    }
                }
            }
             //take third stacks last entry end looks for first second stack then first stack to replace

            value=s3->array[s3->currentsize-1];
            control=try(0,value,0,s2);
            if(last_put!=value && value!=0)
            {
                if(control==1)
                {
                    shift(s3,s2);
                    last_put=value;
                } else
                {
                    control=try(0,value,0,s1);
                    if(control==1)
                    {
                        shift(s3,s1);
                        last_put=value;
                    }
                }
            }
        } while(s3->currentsize!=towersize );

    } else
    {
        do
        {   //these are the same but they are for even number of disk 
            value=s1->array[s1->currentsize-1];
            control=try(0,value,0,s2);
            if(last_put!=value && value!=0)
            {
                if(control==1)
                {
                    shift(s1,s2);
                    last_put=value;
                } else
                {
                    control=try(0,value,0,s3);
                    if(control==1)
                    {
                        shift(s1,s3);
                        last_put=value;
                    }
                }
            }
            value=s2->array[s2->currentsize-1];
            control=try(0,value,0,s3);
            if(last_put!=value && value!=0)
            {

                if(control==1)
                {
                    shift(s2,s3);
                    last_put=value;
                } else
                {
                    control=try(0,value,0,s1);
                    if(control==1)
                    {   
                        shift(s2,s1);
                        last_put=value;
                    }
                }
            }
            value=s3->array[s3->currentsize-1];
            control=try(0,value,0,s1);
            if(last_put!=value && value!=0)
            {
                if(control==1)
                {
                    shift(s3,s1);
                    last_put=value;
                } else
                {
                    control=try(0,value,0,s2);
                    if(control==1)
                    {
                        shift(s3,s2);
                        last_put=value;
                    }
                }
            }
        } while(s3->currentsize!=towersize);
    }
printf("\n%d total move\n",move_counter);
}
int pop(stack * s)
{
    int value=s->array[s->currentsize-1];
    s->array[s->currentsize-1]=0;
    s->currentsize=s->currentsize-1;
    move_counter++;
  
   printf("\nMove the disk %d from '%d' to",value,s->stack_number);
    return value;
}
//this is resize stacks array 

int * resize(stack *s)
{
    int *arr =(int*)calloc(sizeof(int),s->currentsize+1);//resize the array only 1 index bigger
        for(int a=0;a<s->currentsize;a++)
        {
            arr[a]=s->array[a];
        }
        s->maxsize=s->currentsize;
        free(s->array);
        return arr;

}
void push(stack * s, int d)
{
    if(s->currentsize>s->maxsize)
    {
        s->array=resize(s);
    }
 
        
    
    s->array[s->currentsize]=d;
    s->currentsize=s->currentsize+1;
}