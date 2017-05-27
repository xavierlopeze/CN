#include <stdio.h>
#include "camp21.h"

#include "flux.h"
#include "camp21.h"

#define PAS_INICIAL 0.001
#define PASMIN 1E-7
#define PASMAX 0.5

#define N 2
#define NVAR N*N
#define NTOTAL  N + NVAR

#define TOL 1E-12
#define NPASMAX 1000000
#define CAMP camp21
#define PRM p

#define DPHI(i,j) dphi[N*(j)+(i)]

/*
 * Per compilar:
        gcc -o exercici21_int -g -Wall exercici21_int.c camp21.c rk78.c flux.c -lm
 */

/*
*  echo ".5 .5 .5 "| ./exercici21_int .5
*/



int main (int argc, char *argv[]) {
   double t, x[6], h;
   double p[1]; // vector de parametres del camp (en el nostre cas nomes un, alpha)
   double tf;
   double x0,x1;
    
   /*Llegim paramtre del camp: alpha*/
   if (argc!=2
         || sscanf(argv[1],"%lf",&p[0])!=1
      ) {
      fprintf(stderr, "./exercici21_int alpha\n");
      return -1;
   }
   
    /*Llegim posicio inicial i temps final a calcular la nova posicio*/
    scanf("%lf %lf %lf",&x0,&x1, &tf); //.5 .5 .5 
     
    /*
    *Aproximacio de les variacionals a traves de flux 
    */
    
	/*Inicialitzem x */
	//posicio inicial
	x[0]= x0;
	x[1]= x1;
	
	//A(t_0) = Id_N (variacionals primeres)
	x[2]=1; x[3]=0;
	x[4]=0; x[5]=1;
	
	/*Calculem el fux amb variacionals primeres (n=NTOTAL)*/
	t=0; h=PAS_INICIAL; 
	flux(&t, x, &h, tf, PASMIN,PASMAX,TOL,NPASMAX,NTOTAL,CAMP,PRM);
	
	/*Imprimim*/
	//Imprimim temps i posicio inicial*/
	printf("\nt=%.16G x=%.16G y=%.16G\n",t ,x[0], x[1]);
	//Imprimim Variacionals primeres
	  printf("%.16G %.16G\n",x[2],x[4]);
	  printf("%.16G %.16G\n",x[3],x[5]);
	  

     /*
      *Aproximacio de les variacionals per diferencia finita centrada de primer ordre 
      */
     
	/*Inicialitzem x*/
	//Només cal uxar posicio (x0,x1) (no usem variacionals x[2],x[3],x[4],x[5]) 
	x[0]= x0;
	x[1]= x1;
	  
	int i, k;
	double xp[2],xm[2];
	double dphi[NVAR]; //guardarem el valor de les variacionals primeres
	double epsilon = 0.001;
	
	
	for(i=0; i<N; i++){
	  
	    /*Inicialitzem xp i xm*/
	  for(k=0; k<N; k++){
	      xp[k] = x[k];
	      xm[k] = x[k];
	      if(k==i){
		xp[k]+=epsilon;
		xm[k]-=epsilon;
	      }
	    }
	    
	    /*Calculem el flux de xm i xp (sense variacionals (n=2))*/
	    
	    t=0; h=PAS_INICIAL;
	    flux(&t,xm,&h,tf,PASMIN,PASMAX,TOL,NPASMAX,2,CAMP,PRM); //Calcul xm (flux x+epsion)
	    
	    t=0; h=PAS_INICIAL;
	    flux(&t,xp,&h,tf,PASMIN,PASMAX,TOL,NPASMAX,2,CAMP,PRM); //Calcul xp (flux x-epsilon)
	    
	    
	    /*Aproximem flux*/
	    for(k=0; k<N; k++){
		DPHI(i,k) = (xp[k]-xm[k])/(2*epsilon);
	      }
	}
	
	  printf("\nComprovació Variacionas\n");
	  printf("%.16G %.16G\n",DPHI(0,0),DPHI(1,0));
	  printf("%.16G %.16G\n",DPHI(0,1),DPHI(1,1));
   return 0;
}
