#include <stdio.h>
#include <math.h>
#define HALF_PI 1.57079632
#include "qrres.h"
#include "pendol.h"
#include "cmani.h"



#define PAS_INICIAL 0.001
#define PASMIN 1E-4
#define PASMAX 1
#define TOL 1E-6
#define NPASMAX 10000
#define CAMP pendol
#define PRM NULL

//gcc -o verificacio_cmani -g -Wall verificacio_cmani.c cmani.c flux.c rk78.c qrres.c pendol.c -lm 

//opcio amb nomes un flux//


int main(){ 
  int m=1;
  double x0[2*m], xf[2*m];
  
  x0[0] = 1, x0[1] = 0;
  xf[0] = 0, xf[1] = -0.95885108;
  
  double dt = HALF_PI;
  
  double dv[2*m];
  dv[0]=0; dv[1] = 0;
  
  cmani(m, x0, xf, dt, dv, 
	   1E-12, 1000,
	   PAS_INICIAL, PASMIN, PASMAX, TOL, NPASMAX, //parametres per passar a flux()
	   CAMP,//apunta a una funcio que implementa el camp vectorial
	   PRM);
  
  return 0;
}
