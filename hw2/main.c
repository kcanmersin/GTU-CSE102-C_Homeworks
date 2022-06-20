#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "math.h"


int main() {
     int option;
    //inputs for first problem
    float pl,pw,sl,sw;
    char flowerb;
    char flowera;
  
     //inputs for second problem
    double ans1,ans2;
    double x1,x2,x3;
    int x4,x5,sum;

    //inputs for third problem
    double physic, shooting;
    int moral,potential,foot;
    int is_enougha,is_enoughb;
  
    
       printf("1-Problem 1\n2-Problem 2\n3-Selection of young players from the infrastructure for ace team\nSelect one option : ");
       scanf("%d",&option);
       switch (option)
       {
       case 1:
           //this block takes input from user for first problem
            printf("Enter inputs:\nPL: ");
            scanf("%fl",&pl);
            printf("\nPW: ");
            scanf("%fl",&pw);
            printf("\nSL: ");
            scanf("%fl",&sl);
            printf("\nSW: ");
            scanf("%fl",&sw);
            
            flowera=dt1a(pl,pw,sl,sw);
        
            flowerb=dt1b(pl,pw,sl,sw);
            //this block call function to print flower type. if both answer is same call once
       
            if(flowera==flowerb)
            {
                flower_type(flowera,0);  
            }else
            {
                  //second variable  is for determine which tree the result came from
                  flower_type(flowera,1);
                  flower_type(flowerb,2);        
            }
           break;
       
       case 2:
         //this block takes input from user for second problem
        printf("Enter inputs:\nx1: ");
        scanf("%lf",&x1);
        printf("\nx2: ");
        scanf("%lf",&x2);
        printf("\nx3: ");
        scanf("%lf",&x3);
        printf("\n(0 or 1)x4: ");
        scanf("%d",&x4);
        printf("\n(0 or 1)x5: ");
        scanf("%d",&x5);
        if((x5!=0 && x5!=1) || (x4!=0 && x4!=1)  )
        {
            printf("You entered unwanted input!!");
            return 0;
        }
        ans1= dt2a( x1,x2,x3,x4,x5);
        ans2= dt2b( x1,x2,x3,x4,x5);

        //this block ensures that the sum is not negative
        if(ans1>ans2)
        {
            sum=ans1-ans2;
        }else
        {
            sum=ans2-ans1;
        }
        if(sum>CLOSE_ENOUGH)
        {
            printf("First tree's answer: %lf \nSecond tree's answer: %lf",ans1,ans2);
        }else
        {
            printf("Average result:%lf",(ans1+ans2)/2);
        }
           break;
        case 3:
      
         //this block takes input from user for third problem
        printf("Enter inputs:\n(0.0-10.0)Physic: ");
        scanf("%lf",&physic);
        printf("\n(0.0-10.0)Shooting: ");
        scanf("%lf",&shooting);
        printf("Choose player morale;\n1-Excellent\n2-Good\n3-Okey\n4-Bad\n5-Poor\n");
        scanf("%d",&moral);
        printf("Choose player potential;\n1-Has Special Abilities\n2-Has Great Potential\n3-Show Great Effort\n4-At the highest point of its potential\n5-He does not have a good future\n");
        scanf("%d",&potential);       
        printf("\nPreffered foot(0 for left, 1 for rigt foot): ");
        scanf("%d",&foot);
        is_enougha=dt3a(physic, shooting,  moral,  potential,  foot);
        is_enoughb=dt3b(physic, shooting,  moral,  potential,  foot);
        //this block prevents unwanted values from being entered
        if((foot!=0 && foot!=1) || physic<0.0 || physic>10.0 || shooting<0.0 || shooting>10.0 || moral<1 || moral>5 || potential<1 || potential>5 )
        {
            printf("You entered unwanted input!!");
            return 0;
        }
         //this block call function to print player whether can play. if both answer is same call once
       
         if(is_enougha==is_enoughb)
        {
       
          player_type(is_enougha);

        }else
        {
         player_type(is_enougha);
         printf("\n");
         player_type(is_enoughb);
        } 
            
         break;
         }
    return 0;
}
