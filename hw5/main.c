#include<stdio.h>
#include "math.h"
#include <stdlib.h>
#include <string.h>
#define PI 3.14
//Initialize enum types variable
enum Shapes{Triangle=1,Quadrilateral,Circle,Pyramid,Cylinder};
enum Calculators{Area=1,Perimeter,Volume};
int select_shape ();
int select_calc ();
int calculate (int (*s_shape)(), int (*s_calc)());
int calc_triangle(int calculator);
int calc_quadrilateral(int calculator);
int calc_circle(int calculator);
int calc_pyramid(int calculator);
int calc_cylinder(int calculator);
//this function print error message and clean buffer for scanf 
void clean_buffer()
{
    printf("ERROR! Please enter a valid entry\n");
    while(getchar()!='\n');
}

int main()
{   
    printf("Welcome to the geometric calculator\n");
    int option=1;
    while(option!=0)
    {
        option=calculate (select_shape,select_calc);
    }

}

int calculate (int (*s_shape)(), int (*s_calc)())
{
    int control=1;
    enum Shapes shape;
    enum Calculators calculator;
    do
    {   
        int control=1;
        int return_control=0;
        //calls the necessary function for the user to select a shape
        //if the function sends -999, it runs the program again without stopping
        do{
            shape=s_shape();
            //if user select exit program instantly stop
            if(shape==0) return 0;

        }while(shape==-999);
         /////////////////////////////////////////////////////////////////////////////////////////////////
      
        
        //calls the necessary function for the user to select a calculator type
        //if the function sends -999, it runs the program again without stopping
        do{
           
            calculator=s_calc();
             //if user select exit program instantly stop
            if(calculator==0) return 0;

        }while(calculator==-999);
         /////////////////////////////////////////////////////////////////////////////////////////////////
      
        //some values of some shapes cannot be calculated, so this block prevent that
        if(shape==1 && calculator==3)
        {
            printf("ERROR! You cannot calculate the volume of a triangle. Please try again.\n");
            control=0;
        }else if(shape==2 && calculator==3)
        {
            printf("ERROR! You cannot calculate the volume of a Quadrilateral. Please try again.\n");
            control=0;

        }else if(shape==3  && calculator==3  )
        {
            printf("ERROR! You cannot calculate the volume of a Circle. Please try again.\n");
            control=0;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////
        //if there is no problem with the selection, this loop will start 
        while(control!=0 && return_control==0)
        {
            switch(shape)
            {
                case Triangle:
                //return_controls for prevents the program's flow from stopping if the user enters an invalid value
                    return_control=calc_triangle(calculator);  
                    break;
                case Quadrilateral:
                    return_control= calc_quadrilateral( calculator);
                    break;
                case Circle:
                    return_control=calc_circle( calculator);
                    break;
                case Pyramid:
                    return_control= calc_pyramid( calculator );
                    break;
                case Cylinder:
                    return_control= calc_cylinder( calculator);
                    break;
            }
        }
    }while(control!=1);
    return 1;
}


int select_shape ()
{
    int shape;
   
    printf("\nSelect shape;\n1. Triangle\n2. Quadrilateral\n3. Circle\n4. Pyramid\n5. Cylinder\n0. Exit\nInput: ");
    //if the user enters a value other than the float type, an error message will  given and the buffer will cleared
    if (scanf( "%d", &shape)!=1 || shape<0 || shape >5)
        {   
            clean_buffer();
            return -999;
        }
    //the control variable prevents the program from running incorrectly
    // in cases where the user enters values such as 4f
    char control;
    //in this case, scanf gets the number, but f remains in the buffer
    //getchar detects the remaining letter in the buffer and sends an error message

    control=getchar();
    if(control!='\n')
    {
        
        clean_buffer();
        return -999;

    }

    return shape;
}
int select_calc ()
{   
    int calculator;
    char control;
    printf("\nSelect calculator;\n1. Area\n2. Perimeter\n3. Volume\n0. Exit\nInput: ");
    if (scanf( "%d", &calculator)!=1 || calculator<0 || calculator >3)
    {   
        clean_buffer();
        return -999;
    }
    //the control variable prevents the program from running incorrectly
    // in cases where the user enters values such as 4f
  
    control=getchar();
    //in this case, scanf gets the number, but f remains in the buffer
    //getchar detects the remaining letter in the buffer and sends an error message
    if(control!='\n')
    {
        
        clean_buffer();
        return -999;

    }
    
    return calculator;
}
int calc_triangle(int  calculator)
{
        float n1,n2,n3;
        float result;
        char a;
        int control;
        printf("Please enter three sides of Triangle :\n");
         //if the user enters a value other than the float type, an error message will  given and the buffer will cleared
        if ( scanf( "%f %f %f", &n1, &n2, &n3 ) != 3  )
        { 
            clean_buffer();
            return 0;
        }
        //if a triangle cannot be created with the entered values, an error message is given
        if(n1+n2<n3 || n1+n3<n2 || n3+n2<n1 || n1<=0 || n2<=0 || n3<=0 )
        {   
            printf("\nERROR! Please enter a valid Triangle!\n");
            return 0;
        }
        float s=(n1+n2+n3)/2;
        switch (calculator)
        {
            case Area:
                result=sqrt(s*(s-n1)*(s-n2)*(s-n3));
                printf("Area of Triangle: %.2f\n",result);
                break;
            
            case Perimeter:
                result=n1+n2+n3;
                printf("Perimeter of Triangle: %.2f\n",result);
                break;
        }       
        return 1;
}
int calc_quadrilateral(int calculator)
{
    float n1,n2,n3,n4;
    float result;
    printf("Please enter four sides of Quadrilateral :\n");

    if ( scanf( "%f %f %f %f", &n1, &n2, &n3,&n4 ) != 4 || n1<=0 || n2<=0 || n3<=0 || n4<=0 )
        { 
            clean_buffer();
            return 0;
        }
   
    float s=(n1+n2+n3+n4)/2;
    switch (calculator)
    {
        case Area:
            result=sqrt((s-n1)*(s-n2)*(s-n3)*(s-n4));
            printf("Area of Quadrilateral: %.2f\n",result);
            break;
            
        case Perimeter:
            result=n1+n2+n3+n4;
            printf("Perimeter of Quadrilateral: %.2f\n",result);
            break;
    }       
    return 1;

}
int calc_circle(int calculator)
{
    float radius,result;
    printf("\nPlease enter the radius of Circle : ");
    if ( scanf( "%f", &radius)!=1 || radius<=0 )
    {
        clean_buffer();
        return 0;
    }
   
    switch (calculator)
    {
        case Area:
            result=PI*radius*radius;
            printf("Area of Circle: %.2f\n",result);
            break;
        
        case Perimeter:
            result=2*PI*radius;
            printf("Perimeter of Circle: %.2f\n",result);
            break;
    }       
    return 1;
}
int calc_pyramid(int calculator )
{
    float base,height,result,B,L;
    if(calculator==Area)
    {
        printf("Please enter the base side and slant height of a Pyramid\n");

    }else
    {
        printf("Please enter the base side and  height of a Pyramid\n");
 
    }
    
    if ( scanf( "%f %f", &base,&height ) != 2 || base<=0 || height<=0 )
    { 
        clean_buffer();
        return 0;
    }
    
    switch (calculator)
    {
        case Volume:
            result=base*base*height/3;
            printf("Volume of Pyramid: %.2f\n",result);
            break;
        
        case Area:
            B=base*base;
            printf("Base Surface Area of a Pyramid : %.2f\n",B);
            L=2*base*height;
            printf("Lateral Surface Area of a Pyramid : %.2f\n",L);
            printf("Surface Area of a Pyramid: %.2f\n",B+L);
            break;
        case Perimeter:
            printf("Base Perimeter of a Pyramid : %.2f\n",base*4);
            break;
    }
    return 1;

}
int calc_cylinder(int calculator)
{
    float radius,height,result,B,L,S;
    printf("Please enter the radius  and height of a Cylinder\n");
    if  (scanf( "%f %f", &radius,&height ) != 2 || radius<=0 || height<=0 )
    { 
        clean_buffer();
        return 0;
    }
    switch (calculator)
    {
        case Volume:
            result=PI*radius*radius*height;
            printf("Volume of Cylinder: %.2f\n",result);
            break;
        
        case Area:
            B=PI*radius*radius;
            printf("Base Surface Area of a Cylinder : %.2f\n",B);
            L=2*PI*radius*height;
            printf("Lateral Surface Area of a Cylinder : %.2f\n",L);
            S=2*PI*radius*(radius+height);
            printf("Surface Area of a Cylinder: %.2f\n",S);

            break;
        case Perimeter:
            printf("Base Surface Perimeter of a Cylinder : %.2f\n",2*PI*radius);
            break;

    }
        return 1;

}


