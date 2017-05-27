#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "flux.h"
#include "campSINCOS.h"

//Compila
/*gcc -o prova_flux2 -g -Wall prova_flux2.c flux.c rk78.c campSINCOS.c -lm*/
//Executa
/*./prova_flux2*/
#define T0 0 

#define TF 3.14159265359
#define PAS_INICIAL 0.1
#define PASMIN 1E-6
#define PASMAX 0.5
#define TOL 1E-12
#define NPASMAX 100000


int main(){
  double t = T0, h=PAS_INICIAL;
  double x[2];
  x[0]=0; x[1]=1;
  int n=2;
  flux(&t, x, &h, (TF-T0),PASMIN,PASMAX,TOL,NPASMAX,n,campSINCOS,NULL);
  printf("La solució a temps: %.16G es: [%.16G,%.16G], té com error %.16G\n", t, x[0],x[1],sqrt(fabs(x[0]*x[0]+(x[1]-1)*(x[1]-1)))); 
  return 0;
}

  
