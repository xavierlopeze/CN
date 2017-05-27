#include <math.h>
#include <stdio.h>
#include "rk78.h"

int flux(
  double *t, 
  double x[], 
  double *h, 
  double T,
  
  double pasmin,
  double pasmax,
  double tol,
  int npasmax,
  
  int n,
  
  int (*camp)(int n, double t, double x[], double f[], void *prm),
  void *prm)
  {
      
      int i=0;
      double gap;
      
      double tFinal = *t+T;
     

      while (i<npasmax){
	
	if(fabs(*t+*h)<fabs(tFinal)){ // si el seguent pas no sobrepassa el temps final
	  rk78(t,x,h,pasmin,pasmax,tol,n,camp,prm); // fem un pas mes
	}
	
	else{ // si fer un pas mes implica sobrepassar el temps final
	  
	  gap = tFinal - *t; // pas que cal fer
	  
	  if(fabs(gap)<pasmin){ // si el pas que cal fer (gap) es mes petit que pasmin
	   pasmin=gap; // canviem pasmin per gap
	  }
	  
	  rk78(t,x,&gap,pasmin,pasmax,tol,n,camp,prm); // conservem el pasmin i enviem gap per pas a fer
	  return 0;
	  }
	
		i++;
      }
      
      fprintf(stderr,"flux():: s'han superat %d passos d'integracio numerica\n",npasmax);
      return -1;
  }