#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001


char dt1a(float pl,float pw,float sl,float sw);
char dt1b(float pl,float pw,float sl,float sw);
void flower_type(char flower, int tree);


double dt2a(double x1, double x2, double x3 ,int  x4, int x5);
double dt2b(double x1, double x2, double x3 ,int x4, int x5);

/* Write the prototype of the functions implementing the decision trees for the third problem */
int dt3a(double physic,double shooting, int moral, int potential, int foot);
int dt3b(double physic,double shooting, int moral, int potential, int foot);
void player_type(int is_enough);
#endif /* _UTIL_H_ */