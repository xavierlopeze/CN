#include <stdio.h>
#include "qrres.h"

#define A(i,j) a[i+j*3]

//gcc -o verificacio_qrres -g -Wall verificacio_qrres.c qrres.c -lm


int main(){
  double a[6], b[3], x[2], dr[3];
  
  A(0,0)=0; A(0,1)=-4; 
  A(1,0)=0; A(1,1)=0;
  A(2,0)=5; A(2,1)=-2;  

  b[0]=1; b[1]=3; b[2]=2;;
  
  x[0]=0; x[1]=0;
  
  qrres(3,2,a,dr,b,x);
  printf("\n%.16G %.16G\n",x[0],x[1]);
  
}
