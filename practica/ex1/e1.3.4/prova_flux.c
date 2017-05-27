#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "flux.h"
#include "campt2.h"

//Compila
/*gcc -o prova_flux -g -Wall prova_flux.c flux.c rk78.c campt2.c -lm*/
//Executa
/*./prova_flux*/
//condicions inicials del camp vectorial: y(1)=1
#define T0 1 
#define X0 1

#define TF 10
#define PAS_INICIAL 0.1
#define PASMIN 1E-6
#define PASMAX 0.5
#define TOL 1E-12
#define NPASMAX 100000


int main(){
  double t = T0, x=X0, h=PAS_INICIAL;
  int n=1;
  flux(&t, &x, &h, (TF-T0),PASMIN,PASMAX,TOL,NPASMAX,n,campt2,NULL);
  printf("La solució a temps: %.16G es: %.16G, té com error %.16G\n", t, x,fabs(x-TF*TF)); 
  return 0;
}

  
