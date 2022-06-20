#include <stdio.h>
#include "util.h"


int main()
{
  // This part takes integers and divisor from user
	int f_i,x,y,z;
	printf("Enter the first integer: ");
	scanf("%d",&x);
	printf("Enter the second integer: ");
	scanf("%d",&y);
	printf("Enter the divisor: ");
	scanf("%d",&z);
	
	f_i=find_divisible(x,y,z);

	if(f_i==-1)
	{
		printf("There is not any integer between %d and %d can be divided by %d\n",x,y,z);
	}else
	{
		printf("The first integer between %d and %d divided by %d is %d\n",x,y,z,f_i);
  
	
		int nth,n;
		printf("\nEnter the number how many next:");
		scanf("%d",&n);
		  //this equation provides that the number user entered does not exceed the upper limit
		if(n*z+f_i<y)
		{
			nth=find_nth_divisible(n,f_i,z);
			printf("The %d th integer between %d and %d divided by %d is %d\n\n\n",n+1,x,y,z,nth);
		}else
		{
		printf("No possible to find %d th divisible between %d and %d divided by %d\n\n\n",n+1,x,y,z);
		}
			
	}


  ///////////////////////////////////////////////////////////////////////////

  char id[12];
  int password;
  int check;
  //This part take identity number and password to create customer
  printf("Enter your identity number : ");
  scanf("%s", id);
  printf("Enter your password:" );
  scanf("%d",&password);
  
  
  if(password>9999 && password<1000)
  {
    printf("Invalid password");
    return 0;
  }
  //this checks whether identity number is valid
  int is_valid=validate_identity_number(id);

  if(is_valid==1)
  {
    create_customer(id,password);
  }else
  {
    printf("Invalid id!!");
	  return 0;
  }
  //This part take id and password to login
  printf("Enter your identity number : ");
  scanf("%s", id);
  printf("Enter your password:" );
  scanf("%d",&password); 
//this checks whether the identity number and password entered by the user is the same as in the file
  check=check_login(id,password);

  if(check==1)
 { 
  float amount;
  printf("\nLogin Successful\n");
  printf("Enter your withdraw amount : ");
  scanf("%fl",&amount);
  amount=withdrawable_amount(amount);
  printf("\nWithdrawable amount is: %0.lf \n",amount);
 }else
 {
  printf("Wrong identitty number or password!\n");
 }

}
