#include<stdio.h>
int write_file(int a, int b , int c);
void draw_graph();
void draw_graph_to_file();
int find_disc(int a, int b , int c);
int loc(int x, int y, int a, int b, int c);
int find_digit(int value);
int main()
{
    int option=1,operation;
    int a,b,c;
    int is_wrote;
    
    while(option!=3)
    {
        printf("Select an operation.. \n0 -> Enter the coefficients\n1 -> Draw the graph\n2 -> Print the graph into a.txt file\n3 -> Exit\nChoice: ");
        scanf("%d",&operation);
     
        switch (operation)
        {
        case 0:
            printf("Please enter the coefficient for the following equation: x=a*(y*y) + b*y + c\n\n");
            printf("a: ");
            scanf("%d",&a);
            printf("b: ");
            scanf("%d",&b);
            printf("c: ");
            scanf("%d",&c);
            is_wrote=write_file( a,  b ,  c);
            if(is_wrote==1)
            {
                 printf("\ncoefficients.txt file has been created.\n");
            }else
            {
                printf("\ncoefficients.txt file not created\n");
            }
            break;
        case 1:
            draw_graph();
            break;
        case 2:
            draw_graph_to_file();
            break;
        case 3:
            option=3;
        break;
        }

    } 


    return 0;
}
//this function checks point(x,y) does it provide. If it is return 1
int loc(int x, int y, int a, int b, int c)
{
   
    if( x==(a*y*y+b*y+c))
    {
        return 1;
    }else
    {
        return 0;
    }
}

void draw_graph_to_file()
{
     int coef,a,b,c;
     int draw;
    FILE *graph=fopen("graph.txt","w+");
    FILE *fp=fopen("coefficients.txt","r");
    if(fp==NULL)
    {
        printf("\ncoefficients.txt cannot be open!!\n");
    }else
    {
        printf("\nCoefficients has been read from the coefficient.txt file\n");
        fscanf(fp, "%d\n%d\n%d", &a,&b,&c);
        printf("\nPrinting the graph of x=%d*(y*y)+%d*y+%d\n",a,b,c);

    }
    fclose(fp);    
    int digit=0;
    
    for(int p=0;p<55;p++)
    {
        fprintf(graph," ");
    }
    fprintf(graph,"^");
    fprintf(graph,"\n");
 
    for(int y=20;y>=-20;y--)
    {
        for(int x=-55;x<=55;x++)
        {
        draw=loc( x,  y,  a,  b,  c);
        if(draw==1)
        {
            fprintf(graph,"#");
            x+=1;
        }
        if(x==0)
        {
            fprintf(graph,"|");
        }else if(x==55 && y==0)
        {
            fprintf(graph,">");
        }else if(x==-55 && y==0)
        {
            fprintf(graph,"<");        
        }else if(y==0 && x!=0 && x!=55 )
        {
            fprintf(graph,"-"); 
        }else 
        {
            fprintf(graph," ");
        }   
        }fprintf(graph,"\n");
 
    }
    fclose(graph);  
}
//This function find digit of number, if it is negative add one because of "-" character
int find_digit(int value)
{   
    int  digit=1;
    if(value<0)
    {
        digit++;
        value=-1*value;
    }
       
    while (value>=10)
    {
        value=value/10;
        digit++;
    }
     
    return digit;
}
void draw_graph()
{
    int coef,a,b,c;
    int draw;
    int digit=0;
    FILE *fp=fopen("coefficients.txt","r");
    if(fp==NULL)
    {
        printf("\ncoefficients.txt cannot be open!!\n");
    }else
    {
        printf("\nCoefficients has been read from the coefficient.txt file\n");
        fscanf(fp, "%d\n%d\n%d", &a,&b,&c);
        printf("\nPrinting the graph of x=%d*(y*y)+%d*y+%d\n",a,b,c);

    }
    
    fclose(fp);    
    for(int p=0;p<55;p++)
    {
        printf(" ");
    }
    printf("^");
    printf("\n");
    for(int y=20;y>=-20;y--)
    {
        for(int x=-55;x<=55;x++)
        {
        
            draw=loc( x,  y,  a,  b,  c);
            int xflag=0;
            int yflag=0;
         
        
            if(draw==1)
            {
                printf("\033[0;36m");
                printf("#");
                printf("\033[0m");
                x+=1;
            }
            if(x==0)
            {
                printf("|");
            } else if(x==55 && y==0)
            {
                printf(">");
            }else if(x==-55 && y==0)
            {
       
                printf("<");
        
            }else if(y==0 && x!=0 && x!=55 )
            {
                printf("-"); 
            }else 
            {
                printf(" ");
            }
  
            if(x==-2)
            {
                //does not print the x values if the graph coincides with the x values
                for(int t=-1;t<=1;t++)
                {   
                    for(int k=-2;k<=0;k++)
                    {
                        draw=loc( x+k,  y+t,  a,  b,  c);
                        if(draw==1)
                        {
                            yflag=1;
                        }
                    }
                     
                }
                if(yflag==0)
                {
                    if(y!=0 && y%5==0)
                    {
                        digit=find_digit(y);
                    for(int a=0;a<digit;a++)
                    {
                            printf("\b");
                    }
                        printf("\033[0;33m");
                        printf("%d",y);
                        printf("\033[0m");
                    }

                }       
                    

                
               
                
 
            }
            if(y==-1)
            {
                int border;      
                digit=find_digit(x);
                border=-1*(digit-1);
                ////does not print the x values if the graph coincides with the x values
                for(;border<0;border++)
                {
                    draw=loc( x+border,  y,  a,  b,  c);
                    if(draw==1)
                    {
                        xflag=1;
                        
                    }
                }
                if(xflag==0)
                {
                    if(x%10==0 && x!=0 )
                    {
                    digit=find_digit(x);
                    for(int a=0;a<digit;a++)
                    {
                            printf("\b");
                    
                    }
                    printf("\033[0;33m");
                    if(draw)
                    {
                        printf("%d",x);  
                    }else
                    {
                        printf("%d",x);
                    }
                    printf("\033[0m");
                    }else if(x==-1)
                    {
                        printf("\b");
                        printf("\033[0;33m");
                        printf("%d",x+1);
                        printf("\033[0m");
                    }
                }
           
            }
     }printf("\n");

    }


}
int write_file(int a, int b , int c)
{
    FILE *fp=fopen("coefficients.txt","w");
    if(fp==NULL)
    {
		printf("\nFile cannot open\n");
        fclose(fp);
        return 0;
	
	}else
    {
        fprintf(fp,"%d\n%d\n%d",a,b,c);
        fclose(fp);
        return 1;
       
    }
    

}