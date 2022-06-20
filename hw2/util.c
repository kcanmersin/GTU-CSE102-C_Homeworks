#include <stdio.h>
#include "util.h"

#include "math.h"

     
char dt1a(float pl,float pw,float sl,float sw)
{
    if(pl<2.45)
    {
        return 's';
    }else
    {
        if(pw>=1.75)
        {
            return 'v';
        }else
        {
            if(pl>=4.95)
            {
                return 'v';
            }else
            {
                if(pw<1.65)
                {
                    return 'e';
                }else
                {
                    return 'v';
                }
            }
        }
    }

}
// s 1 v 2 e 3
char dt1b(float pl,float pw,float sl,float sw)
{
    if(pl<2.55)
    {
        return 's';
    }else
    {
        if(pw>=1.69)
        {
            return 'v';
        }else
        {
            if(pl<4.85)
            {
                return 'e';
            }else
            {
                return 'v';
            }
        }
    }
}
//this block prints tpye of flower according to first decision tree
void flower_type(char flower, int tree)
{
    switch (tree)
    {
    case 0:
        printf("Both tree's answer : ");
        break;
    
    case 1:
     printf("First tree's answer : ");
        break;
    
    case 2:
    printf("Second tree's answer : ");
    break;
    }
   
    if(flower=='s')
    {
        printf("Setosa\n");
    }else if(flower=='v')
    {
        printf("Virginica\n");
    }else if(flower=='e')
    {
        printf("Versicolor\n");
    }
    
}
double dt2a(double x1, double x2, double x3 ,int x4, int x5)
{
    if(x1<31.5)
    {
        if(x2>-2.5)
        {
            return 5.0;
        }else
        {
            if(x1>=x2-0.1)
            {
                return 2.1;
            }else
            {
                return -1.1;
            }
        }
    }else
    {
        if(x3>=-1 && x3<=2)
        {
            return 1.4;
        }else{
            
            if(x4 && x5)
            {
                return -2.33;
            }else
            {
                return 11.0;
            }
        }
    }
}
double dt2b(double x1, double x2, double x3 ,int x4,  int x5)
{
    if(x1>12 && x1<22)
    {
        if(x3>5/3)
        {
            return -2.0;
        }else
        {
            if(x3>=x1-0.1 && x3<=x1+0.1)
            {
                return 1.01;
            }else
            {
                return -8;
            }
        }
    }else
    {
       
        if(x4 && x5)
        {
            return -1;
        }else
        {
            if(x2>=-1 && x2<=2)
            {
                return -0.14285714285;
            }else
            {
                double ans=sqrt(2)/3;
                return ans;
            }
        }
    }
}
   //phys i1 shoot i2 pass i3 speed i4 leg i5
int dt3a(double physic,double shooting, int moral, int potential, int foot)
{
    if(physic<6.0)
    {
        if(potential>=3)
        {
            if(shooting<5.5)
            {
                return 0;
            }else
            {
                if(potential>2)
                {
                    return 1;
                }else
                {
                    return 2;
                }
            }
        }else
        {
            if(moral>3)
            {
                if(foot&&0)
                {
                    return 1;
                }else
                {
                    return 0;
                }
            }else
            {
                return 1;
            }
        }
    }else
    {
        if(shooting>7)
        {
            if(potential<3.5)
            {
                return 2;
            }else
            {
                if(foot&&1)
                {
                    return 1;
                }else
                {
                    return 2;
                }
            }
        }else
        {
            if(moral<3)
            {
                return 1;
            }else
            {
                if(potential>3)
                {
                    return 0;
                }else
                {
                    return 1;
                }
            }

        }
    }
}
int dt3b(double physic,double shooting, int moral, int potential, int foot)
{
    if(potential>=3)
    {
        if(physic<6)
        {
            if(moral>=2)
            {
                if(foot&&0)
                {
                    return 1;
                }else
                {
                    return 0;
                }
            }else
            {
                return 1;
            }
        }else
        {
            if(shooting<6)
            {
                if(moral>3)
                {
                    return 0;
                }else
                {
                    return 1;
                }
            }else
            {
                return 1;
            }
        }
    }else
    {
        if(shooting<5.5)
        {
            if(foot&&0)
            {
                return 1;
            }else
            {
                return 0;
            }
        }else
        {
            if(physic<6 && moral >3)
            {
                return 1;
            }else
            {
                return 2;
            }
        }
    }
}
//this block print player whether play as ace team member
void player_type(int is_enough)
{
    if(is_enough==0)
    {
        printf("Player may not be play as ace team player");
    }else if(is_enough==1)
    {
        printf("Player may be play as rotation player");
    }else if(is_enough==2)
    {
        printf("Player may be play as ace team player");
    }
 
}
/* Provide your implementations for all the requested functions here */