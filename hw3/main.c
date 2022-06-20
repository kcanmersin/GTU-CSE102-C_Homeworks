
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
int sum (int n1, int n2, int flag);
int multi (int n1, int n2, int flag);
int isprime (int a);
void print_file();
int write_file(int value);
void sort_file();
int read_sort();
void write_temp1(int min1,int min2, int min3);
void last_write();
int find_digit(int value);
int main()
{
    int option=1;
    int is_written=0;
    while(option!=0)
    {
        printf("\n\nSelect operation\n  1. Calculate sum/multiplication between two numbers \n  2. Calculate prime numbers\n  3. Show number sequence in file\n  4. Sort number sequence in file\n  0. Exit\n");
        scanf("%d",&option);
        if(option!=4 && option!=3 && option!=2 && option!=1 && option!=0)
        {
            printf("\nPlease enter integer between 1-4!!\n");
        
        }
        int operation,flag,n1,n2,result;
        int input;
    switch (option )
    {
    case 1:
        printf("Select operation\n Please enter '0 for sum, '1' for multiplication.\n");
        scanf("%d",&operation);
        printf("Please enter '0 to work on even numbers, '1 to work on odd numbers.\n");
        scanf("%d",&flag);
        if((operation!=0 && operation!=1)||(flag!=0 && flag!=1))
        {
            printf("\nYou entered unwanted numbers!!");
            break;
        }
        printf("Please enter two different number: \nNumber 1:");
        scanf("%d",&n1);
        printf("Number 2: ");
        scanf("%d",&n2);
        if(n1==n2)
        {
            printf("\n You entered same numbers!! Please enter two different number!!\n");
            break;
        }
        if(n1<0 || n2<0)
        {
            printf("\nPlease enter positive value!!\n\n");
            break;
        }
        int temp;
        if(n1>n2)
        {
            temp=n1;
            n1=n2;
            n2=temp;
        }
        switch (operation)
        {
            case 0:
            result=sum(n1,n2,flag);
            break;
        
            case 1:
            result= multi(n1,n2,flag);
            break;
        }
        is_written=write_file(result);
        if(is_written==1)
        {
            printf("\nThe result is written to the result.txt file");
        }else
        {
            printf("\nThe result could not be written to the result.txt file!");
        }
        break;
    case 2:
        printf("Please enter an integer: ");
        scanf("%d",&input);
        for(int a=2;a<input;a++)
        {
            result=isprime(a);
            if(result==0)
            {
                printf("%d is a prime number.\n",a);
            }else
            {
                printf("%d is not a prime number, it is divideble by %d\n",a,result);
            }
        }
        break;
    case 3:
        print_file();
        break;
    case 4:
        sort_file ();
        break;
    }
        }
   
return 0;
}

int sum (int n1, int n2, int flag)
{
    int sum=0;
    n1++;
    if(flag==0)
    {
         for(;n1<n2;n1++)
        {
            if(n1%2==0)
            {
                printf("%d",n1);
                sum=sum+n1;
            }

            if(n1%2==0 && n1<n2-2)
            {
                printf("+");
            }
        }

    }else
    {
            for(;n1<n2;n1++)
        {
            if(n1%2==1)
            {
                printf("%d",n1);
                sum=sum+n1;
            }

            if(n1%2==1 && n1<n2-2)
            {
                printf("+");
            }
        }
    }
           
    printf("=%d \n",sum);
    return sum;
}
int multi (int n1, int n2, int flag)
{
    int temp, sum=1;
      n1++;
       if(flag==0)
    {
         for(;n1<n2;n1++)
        {
            if(n1%2==0)
            {
                printf("%d",n1);
                sum=sum*n1;
            }

            if(n1%2==0 && n1<n2-2)
            {
                printf("*");
            }
        }

    }else
    {
            for(;n1<n2;n1++)
        {
            if(n1%2==1)
            {
                printf("%d",n1);
                sum=sum*n1;
            }

            if(n1%2==1 && n1<n2-2)
            {
                printf("*");
            }
        }
    }
           
    printf("=%d \n",sum);
    return sum;
}
int isprime (int a)
{
    int sqrt_a=sqrt(a);
    int flag=0;
    for(int b=2;b<=sqrt_a;b++)
    {
        if(a%b==0)
        {
            return b;
        }
    }
    return 0;
}
//take result as a parameter and write result.txt
int write_file(int value)
{
    FILE *fp=fopen("result.txt","a+");
    if(fp == NULL)
    {
      printf("Error!");   
      return 0;             
    }else
    {
        fprintf(fp,"%d ",value);
    }
    
    fclose(fp);
    return 1;
}
void print_file()
{
    int value;
    FILE *fp=fopen("result.txt","a+");
    while((fscanf(fp, "%d", &value)==1))
    {
        
        printf("%d ",value);
    }
    fclose(fp);
}
void sort_file ()
{
    int is_sorted=0;  
    //this check file is sorted. if it is sorted loop over  
    while(is_sorted==0)
    { 
        is_sorted=read_sort();
    } 
    if(is_sorted==1)
    {
        printf("File sorted\n");
        print_file();
    }
}

int read_sort()
{
    FILE *fp=fopen("result.txt","r+");
  
    int min1, min2, min3, value, temp, tempmin;
    int temp1,temp2,temp3;
    int middle,highest,lowest;
    
    //these block scan values from result. they return 0 if there is not any number
    if (fscanf(fp, "%d", &temp) == 1)
    {
        min1 = temp;
       
        
    }else
    {
        last_write();
        fclose(fp);
        return 1;
    }

    if (fscanf(fp, "%d", &temp) == 1)
    {
        min2 = temp;
    }else
    {
        write_temp1(min1,-1,-1);
        last_write();
         fclose(fp);
        return 1;
    }
     if (fscanf(fp, "%d", &temp) == 1)
    {
        min3 = temp;
    }else
    {
        if(min1>min2)
        {
        write_temp1(min2,min1,-1);
         
        }else
        {
         write_temp1(min1,min2,-1);
        }
        last_write();
         fclose(fp);
        return 1;
    }
    //these block sorted first three values
    if (min1 > min2)
    {
        middle = min1;
        lowest = min2;
    }
    else
    {
        middle = min2;
        lowest = min1;
    }
    if (middle > min3)
    {
        highest = middle;
        if (lowest > min3)
        {
            middle = lowest;
            lowest = min3;
        }
        else
        {
            middle = min3;
        }
    }
    else
    {
          highest = min3;
    }
    //this block scan every number in result and compare with first three number. 
     while (  fscanf(fp, "%d", &value)==1)
    {
        
        if (value <= lowest)
        {
            temp1 = lowest;
            lowest = value;

            temp2 = middle;
            middle = temp1;

            temp3 = highest;
            highest = temp2;
        }else if(value <= middle)
        {
            temp2 = middle;
            middle = value;

            temp3 = highest;
            highest = temp2;
        }
        else if (value <= highest)
        {

            temp3 = highest;
            highest = value;
        }
    }
    //3 value sent to function to wrote temp1.txt
    write_temp1(lowest,middle,highest);
    int cursor,digit; 
    fseek( fp, 0, SEEK_SET );
    int min1_counter=0,min2_counter=0,min3_counter=0;//these prevent deleting more than one number of them when the same numbers are found in the file
    //this block scan and delete value from result which we sorted before
     while((fscanf(fp, "%d", &temp)==1))
     {   
         if(temp==lowest && min1_counter==0)
         {
         	min1_counter++;
            digit=find_digit(temp);
            cursor=-1*digit;
            fseek( fp, cursor, SEEK_CUR );
            for(int w=0;w<digit;w++)
            { 
                fprintf(fp," ");
            }
		 }else if(temp==middle && min2_counter==0)
         {
         	min2_counter++;
            digit=find_digit(temp);
            cursor=-1*digit;
            fseek( fp, cursor, SEEK_CUR );
            for(int w=0;w<digit;w++)
            {
                fprintf(fp," ");
            }
	    }else if(temp==highest && min3_counter==0)
        {
         	min3_counter++;
            digit=find_digit(temp);
            cursor=-1*digit;
            fseek( fp, cursor, SEEK_CUR );
            for(int w=0;w<digit;w++)
            {
                fprintf(fp," ");
            }
        }
     }
     fclose(fp);

}
int find_digit(int value)
{   
   int  digit=1;
     while (value>=10)
        {
            value=value/10;
            digit++;
        }
    return digit;
}

void write_temp1(int min1, int min2 , int min3)
{
    FILE *temp1=fopen("temp1.txt","a+");
    if(min2==-1)
    {
        fprintf(temp1,"%d ",min1);
    }else if(min3==-1)
    {
        fprintf(temp1,"%d %d ",min1,min2);
    }else
    { 
        fprintf(temp1,"%d %d %d ",min1,min2,min3);
    }
    fclose(temp1);
}
//after sort this fucntion owerwrite temp1.txt to result.txt then delete temp1.txt
void last_write()
{
    int temp;
    FILE *fp=fopen("result.txt","w");
    FILE *temp1=fopen("temp1.txt","r");
    while ((fscanf(temp1, "%d", &temp)==1))
    {
        fprintf(fp,"%d ",temp);
    }
    fclose(fp);
    fclose(temp1);
    remove("temp1.txt");
}
