#include <stdio.h>
#include <stdlib.h>
#include <string.h>
union Person
{
    char name[50];
    char address[50];
    int phone;
    int id;
};
union Loan
{
    float arr[3];
};

struct BankAccount
{
    union Person Customer;
    union Loan Loans;
};

void listCustomers();
int addCustomer ();
void newLoan ();
double calculateLoan(float amount, int period, float interestRate);
void getReport();
struct BankAccount Loan ;

struct BankAccount Person [50];
int main ()
{
    FILE *fp=fopen("customers.txt","a");
    FILE *floan=fopen("loans.txt","a");
    close(fp);
    close(floan);

    FILE *fptr;
    if ( !( fptr = fopen( "customers.txt", "r+" ))) {
        printf( "File could not be opened to retrieve your data from it.\n" );
    }
    else {
        fseek(fptr, 0, SEEK_END);
        unsigned long len = (unsigned long)ftell(fptr);
        if (len > 0) {  //check if the file is empty or not.
            rewind(fptr);

        } else
        {
            printf("bos");
            fprintf(fptr,"0 ");
        }
        fclose( fptr );
    }
    int option=1;
    printf("*************************************\nWelcome to the Bank Management System\n*************************************\n");
    printf("\t1. List All Customers\n\t2. Add New Customers\n\t3. New Loan Application\n\t4. Report Menu\n\t5. Exit Sytsem\n");
    int val;

    do
    {
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("\n 1. List All Customers\n");

            listCustomers();
            break;
        case 2:
            printf("\n 2 Add New Customers\n");
            val=addCustomer ();
            if(val==0)
            {
                printf("\nCustomer was not added to the file!");
            }
            break;
        case 3:
            printf("\n3. New Loan Application\n");
            newLoan ();
            break;
        case 4:
            printf("\n 4. Report Menu\n");

            getReport();
            break;
        }
        printf("\t1. List All Customers\n\t2. Add New Customers\n\t3. New Loan Application\n\t4. Report Menu\n\t5. Exit Sytsem\n");
    } while(option!=5);

    return 0;
}

void listCustomers()
{
    //this fucntion read customers.txt and print names to the terminal
    FILE *fp=fopen("customers.txt","r");
    char temp[50],fid[50];
    int tt;
    int count=0;
    fscanf(fp,"%d\n",&tt);//read current customer count
    while(count<tt)
    {
        //read file and takes name to the person array
        fscanf(fp, "%50[^,], ",temp);
        fscanf(fp,"%50[^,],",fid);
        fscanf(fp,"%50[^,],",&(Person[count].Customer.name));
        fscanf(fp,"%*[^\n]");
        count++;

    }
    for(int a=0; a<tt; a++)
    {
        printf("Name: %s\n",(Person[a].Customer.name));
    }
    fclose(fp);

}

int addCustomer ()
{
    FILE *fp=fopen("customers.txt","r+");
    if(fp == NULL)//if file cannot be open give an error messega
    {
        printf("Error! File cannot be open");
        return 0;
    }
    //current customer number is located at the head of file. this part read that number and increase one
    int _tid;
    fscanf(fp,"%d",&_tid);
    if(_tid==50)
    {
        printf("The quota for 50 people has expired\n");
        return 0;
    }
    fseek(fp, 0, SEEK_END);

    _tid=_tid+1;
    fprintf(fp,"\nid,%d",_tid);
    //take customer infos and write them to customers.txt
    printf("Write Customer's\nName: ");
    scanf(" %[^\n]",&(Person[0].Customer.name));
    fprintf(fp,",%s,0,",Person[0].Customer.name);
    while(getchar()!='\n');
    printf("Adress:  ");
    scanf(" %[^\n]",&(Person[0].Customer.address));
    fprintf(fp,"%s,",Person[0].Customer.address);
    while(getchar()!='\n');
    printf("Phone:  ");
    scanf("%d",&(Person[0].Customer.phone));
    fprintf(fp,"%d,",Person[0].Customer.phone);
    fseek(fp, 0, SEEK_SET);
    fprintf(fp,"%d",_tid);
    printf("\nCustomer added\nReturning menu...\n");
    fclose(fp);
    return 1;

}


void newLoan ()
{
    FILE *fp=fopen("customers.txt","r+");
    FILE *floan=fopen("loans.txt","a+");
    fseek(fp, 0, SEEK_SET);
    char _tname[50],_tid[5], fname[50], temp[50],_loancount[5], fid[50];

    int _floancount;
    printf("Enter customer name: ");
    scanf(" %[^\n]",_tname);
    while(getchar()!='\n');
    printf("ID: ");
    scanf(" %[^\n]",_tid);
    while(getchar()!='\n');
    int tt;
    fscanf(fp,"%d\n",&tt);

    printf("\n\n");
    int is_found=0;
    int count=0;
    while(is_found==0 && count<tt)
    {
        fscanf(fp, "%50[^,], ",temp);
        fscanf(fp,"%50[^,],",fid);
        fscanf(fp,"%50[^,],",fname);
        fscanf(fp,"%d,",&_floancount);
        //searches the inside of the file for the given id and name
        if((strcmp(fid,_tid)==0)&&(strcmp(fname,_tname)==0))
        {
            if(_floancount>=3)
            {
                printf("\nCustomer cannot take any loan!\n");
                return ;
            }

            fseek(fp, -2, SEEK_CUR);
            fprintf(fp,"%d",_floancount+1);
            is_found=1;
        }
        fscanf(fp,"%*[^\n]");
        count++;
    }
    if(is_found==0)
    {
        //if given name and id cannot be found at file close files and return menu
        printf("\nCustomer cannot be found!\nReturning menu...\n");

        fclose(fp);
        fclose(floan);
        return ;
    }
    //if name and id if it is located in the file and loan count is lower then 3 takes loan informations
    int _tphone,_tperiod;
    float _tamount,_tinterestrate;
    double current_loan;
    int loan_count;

    printf("Amount:  ");
    scanf("%fl",&(Loan.Loans.arr[0]));
    if(Loan.Loans.arr[0]<=0)
    {
        printf("\nCustomer cannot take that amount of loan!\n");
        fclose(fp);
        fclose(floan);
        return;
    }
    printf("Interest Rate:  ");
    scanf("%fl",&(Loan.Loans.arr[1]));
    printf("Period:  ");
    scanf("%fl",&(Loan.Loans.arr[2]));
    Loan.Loans.arr[0]=calculateLoan(Loan.Loans.arr[0], 0, Loan.Loans.arr[1]);

    fprintf(floan,"\nid%s-%d,%lf,%d,%lf",fid,_floancount+1,Loan.Loans.arr[0],(int)Loan.Loans.arr[2],Loan.Loans.arr[1]);
    fclose(fp);
    fclose(floan);

}

double calculateLoan(float amount, int period, float interestRate)
{

    if(period== Loan.Loans.arr[2])
    {

        return amount;
    } else
    {
        return ((1+interestRate)*calculateLoan(amount, period+1, interestRate));
    }
}



void getReport()
{
    int option;
    printf("1-Customer Detail\n2-Loan Detail\n");
    scanf("%d",&option);
    FILE *fp=fopen("customers.txt","r");
    FILE *floan=fopen("loans.txt","r");
    char _tname[50],_tid[5],fname[50],temp[50], fadress[50], fphone[50], _loancount[5],fid[50];
    char key[50]="id";
    int is_found=0,fperiod,counter=0;
    double famount,finterestrate;
    printf("Write Customer's\nName: ");
    scanf(" %[^\n]",_tname);
    while(getchar()!='\n');
    printf("\nID: ");
    scanf(" %[^\n]",_tid);
    while(getchar()!='\n');
    int tt;//tt dosyanın başındaki id counter
    fscanf(fp, "%d\n",&tt);
    while(is_found==0 && counter<tt)
    {
        fscanf(fp, "%50[^,], ",temp);
        fscanf(fp,"%50[^,],",fid);
        fscanf(fp,"%50[^,],",fname);
        fscanf(fp,"%50[^,],",_loancount);
        fscanf(fp,"%50[^,],",fadress);
        fscanf(fp,"%50[^,],",fphone);
        if((strcmp(fid,_tid)==0)&&(strcmp(fname,_tname)==0))
        {


            is_found=1;
        }



        counter++;
    }
    if(is_found==0)
    {
        printf("\nCustomer cannot be found!\nReturning menu...\n");
        fclose(fp);
        fclose(floan);
        return ;
    }
    int loan_bound=_loancount[0]-'0';//convert loan count to the integer for use at for
    if(loan_bound==0 && option==2)
    {

        printf("\nCustomer does not have loan...Returning menu...\n");
        fclose(fp);
        fclose(floan);
        return ;
    }
    if(option==1)
    {   printf("\nCustomer ID: %s\nCustomer Namee: %s\nCustomer Loan Count: %s\nCustomer Adress: %s\nCustomer Phone: %s\n",fid,fname,_loancount,fadress,fphone);

        //these strcats crate a key, after that looks for that key in loans.txt and found every loan the customer took
        strcat(key,_tid);
        strcat(key,"\0");
        int count=0;
        int x;

        double sum=0;
        printf("Loans =[");

        while(count<loan_bound)
        {

            fscanf(floan, "%50[^-]- ",temp);
            if(strcmp(key,&temp[1])==0)
            {

                is_found=1;
                fscanf(floan,"%d,%lf,%d,%lf",&x,&famount,&fperiod,&finterestrate);
                printf(" %lf +",famount);
                sum=famount+sum;
                count++;


            } else
            {
                fscanf(floan,"%*[^\n]");

            }

        }
        printf("\b]=>%lf",sum);

    } else
    {
        printf("\nLoan count: ");
        scanf(" %[^\n]",_loancount);
        int d=_loancount[0]-'0';
  
        if(d>loan_bound)
        {
            printf("\nCustomer does not have that loan\n");
            fclose(fp);
            fclose(floan);
            return ;
        }
        //these strcats crate a key, after that looks for that key in loans.txt and found the loan customer want to see detail
  
        strcat(key,_tid);
        strcat(key,"-");
        strcat(key,_loancount);
        
        strcat(key,"\0");
      
        int cc=0;
      
        fseek(floan, 0, SEEK_SET);
        int count=0;
        int x;
        while(count<1)
        {

            fscanf(floan, "%50[^,], ",temp);
         
            if(strcmp(key,&temp[1])==0)
            {

                is_found=1;
                fscanf(floan,"%lf,%d,%lf",&famount,&fperiod,&finterestrate);
                printf("\nAmount : %lf\nPeriod: %d\nInterest Rate: %lf\n",famount,fperiod,finterestrate);
                count++;


            } else
            {
                fscanf(floan,"%*[^\n]");

            }

        }
        double installment=famount/fperiod;
       printf("\nTotal credit Value = %lf \n",famount);
        for(int a=1; a<=fperiod; a++)
        {
            printf("%d. Month Installment = %lf\n",a,installment);
        }
    }

    fclose(fp);
    fclose(floan);
}
