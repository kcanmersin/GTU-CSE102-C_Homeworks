#include <stdio.h>
#include <stdlib.h>
#include "util.h"

//This part calculate first divisible number
int find_divisible(int x, int y, int z)
{	
	int flag=0;
	int f_i=x;

	while(f_i<y-1 && flag==0)
	{
		
		f_i++;
		if(f_i%z==0)
		{	
			flag=1;		
		}
	}
	
	if(flag==1)
	{
		return f_i;	
	}else
	{
		return -1;
	}
}

int find_nth_divisible(int n, int f_i, int z)
{
	f_i=f_i+(z*n);
	return f_i;
}

///////////////////////////////////////////////////

int validate_identity_number(char identity_number [ ])
{ 
  int counter=0;
  //sum_even and sum_odd is holds the sum of values whose digit numbers are even or odd
  int sum_even=0,sum_odd=0;

while(identity_number[counter]!='\0')
{
  /*this checks if there is anything other than a digit in the entered identity number */
  if(identity_number[counter]<48 || identity_number[counter]>57)

  {
    return 0;
  }
  //this part sums the numbers whose digit number is odd 
  if((counter+1)%2==1 && counter!=10)
  {
    sum_odd+=identity_number[counter]-'0';
  }//this part sums the numbers whose digit number is even 
  else if((counter+1)%2==0 && counter!=9)
  {
    sum_even+=identity_number[counter]-'0';
  }
  counter++;
}
//checks the special status related to the identity number
if(((sum_odd*7)-(sum_even))%10!=(identity_number[9]-'0'))
{

  return 0;
}
//checks whether the entered identity number is less than 11 digits
  if(counter<11)
{

    return 0;
}
  //checks whether the first digit of the entered identity number is 0
  if(identity_number[0]=='0')
  {
    return 0;
  }
  return 1;

}

int create_customer(char identity_number [ ], int password)
{

  FILE *customer=fopen("customeraccounts.txt","w");

  if(customer==NULL){
        printf("File can't open!");
        exit(1);
    }else
    {
      fprintf(customer,"%s,%d",identity_number,password);
    }

  fclose(customer);
}

//this checks whether the identity number and password entered by the user is the same as in the file
int check_login(char identity_number [ ], int password)
{
  char fid; // id from file
  char comma[1];
  int fpassword; // password from file
  FILE *customer=fopen("customeraccounts.txt","r");
   if(customer==NULL){
        printf("File can't open!");
        exit(1);
    }
  

	for(int i=0;i<11;i++)
		{
			fscanf(customer,"%c",&fid);
			if(fid!=identity_number[i])
			{
				return 0;
			}
		}
	fscanf(customer,"%c",comma);
	fscanf(customer,"%d",&fpassword);
  fclose(customer);
	if(fpassword!=password)
	{
		return 0;
	}
	
  return 1;
}

int withdrawable_amount(float cash_amount)
{
  //a, b and c indicate in how many banknotes the desired amount of money will be given to the client.
  //a 50 , b 20, c 10
  int a,b,c;
  a=cash_amount/50;
  cash_amount-=a*50;
  b=cash_amount/20;
  cash_amount-=b*20;
  c=cash_amount/10;

	return a*50 + b*20 + c*10;
}