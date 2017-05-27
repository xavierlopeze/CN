/*
 * compila'm: gcc -o random_qrres -g -Wall random_qrres.c qrres.c -lm
 */

#include <stdio.h>
#include <stdlib.h> //rand(), srand()
#include <math.h> //fabs()
#include <time.h> //time()
#include "qrres.h"

#define A(i,j) a[(i)+(j)*n]

/*donat un vector i el nombre de components, torna el valor de la component del vector amb valor absolut més gran */
double max(double *v, int n){ 
  
  int i;
  double max = 0;
  
  for(i=0; i<n; i++)
    if(fabs(v[i])>fabs(max))
      max=v[i];
    
  return max;
}

int main(int argc, char *argv[]){
  
  int n;
  int i,j;
  
  /*Llegim dimensió del sistema (n)*/
   if (argc!=2
         || sscanf(argv[1],"%d",&n)!=1
      ) {
      fprintf(stderr, "./random_qrres n\n");
      return -1;
   }
   
  /*Declarem Variables del sistema*/
  //double a[n*n], b[n], x[n], dr[n];
  double* a = malloc((n*n)*sizeof(double));
  double* b = malloc(n*sizeof(double));
  double* x = malloc(n*sizeof(double));
  double* dr = malloc(n*sizeof(double));
  
  /*Assignem valors aleatorils a la matriu*/
  srand(1234); // inicialitzem la llavor del generador de nombres aleatoris
  //srand(time(NULL));
  for(i=0; i<(n*n); i++){
    a[i] = ((double)rand())/RAND_MAX; // valor aleatori entre (0,1)
  }
  
  /*Assignem el valor a b tal que la solucio de Ax=b sigui x=(1,1,...1)*/
  
  for(i=0; i<n; i++){
    b[i]=0; //inicialitzem a zero
    for(j=0; j<n; j++){    
      b[i] += A(i,j); //sumem termes
    }
  }
  /*Calculem i contem el temps d'execucio*/
  time_t t0, t1; //variables temps
  t0=clock(); // vull mesurar el temps des d'aqui
  
  qrres(n,n,a,dr,b,x);
  
  t1=clock(); // mesuro temps fins aqui
  
  
  /*Calculem error*/
  double error[n];
  for(i=0; i<n; i++){
    error[i] = x[i] - 1;
  }
  /*Imprimim*/
  printf("temps: %.3f error màxim %.16G\n", (double)(t1-t0)/CLOCKS_PER_SEC, max(error,n) );
  return 1;
}