//opcio amb nomes un flux//
#include "cmani.h"
#include "qrres.h"
#include "flux.h"
#include <stdio.h>
#include <math.h>

#define X(i,j) x[(j)*(2*m)+(i)] // ara la mida de la matriu de variacionals es 2m * 2m

#define DG(i,j) dg[(j)*(2*m)+(i)]
#define DGv0(i,j) dgv0[(j)*(2*m)+(i)]
#define DGv1(i,j) dgv1[(j)*(2*m)+(i)]

//#define DG(i,j) Dg[(j)*m+(i)]

int cmani_gdg (	int m,
		double x0[],	// (entrada) apunta a un vector de llargada 2*m que conte r0, v0
		double xf[],	// (entrada) apunta a un vector de llargada 2*m que conte rf, vf
		double dt,	// (entrada) \Delta t
		double dv[],	// (entrada) apunta a un vector de llargada m que conte \Delta v0 /////// xv:  millor fem-ho de llargada 2m
		double g[],	// (sortida) apunta a un vector de llargada 2*m on s'ha de guardar G(\Delta v)
		double dg[],	// (sortida) dg apunta a un vector de llargada (2*m)*(2*m) on s'ha de guardar la matriu DG(\Delta v) per columnes.
		double pas0,	double pasmin, double pasmax, double tolfl, int npasmx,//parametres per passar a flux()
		int (*camp)(int n, double t, double x[], double f[], void *prm),void *prm){ //apunta a una funcio que implementa el camp vectorial
		
		  int i,j;
		  int n = 2*m*(1+2*m); // tenim 2m equacions, mes les variacionals corresponents a una matriu 2m*2m 
		  double x[n];
		  double dgv0[2*m*2*m];
		  double dgv1[2*m*2*m];
		  int k;
		  double t=0, h = pas0;

		  /* + \Delta v_0*/
		  for(i=0; i<m; i++){
		      x[i]=x0[i]; // r0
		      x[i+m] = x0[i+m] + dv[i]; // v0 + dv0
		  }
		  
		  //A(t_0) = Id_N (variacionals primeres), en aquest cas N = 2m*2m
		     for (i=0; i<2*m; i++) {
			for (j=0; j<2*m; j++) {
			    if (i==j)
				X(i,j+1) = 1;
			    else
				X(i,j+1) = 0;
			}
		    }
		  
		  flux(&t,x,&h,dt/2,pasmin,pasmax,tolfl, npasmx,n,camp,prm); 
		  
		  /*Guardem primera matriu de variacionals*/
		  for(i=0; i<2*m; i++){
		    for(j=0; j<2*m; j++){
		      DGv0(i,j) = X(i,j+1); 
		    }
		  }
		  
		  h = pas0;
		  
		  /* + \Delta v_1*/
		  for(i=0; i<m; i++){
		      x[i+m]+= dv[i+m]; // v0 + dv1
		  }
		  
		  //A(t_0) = Id_N (variacionals primeres), en aquest cas N = 2m*2m
		     for (i=0; i<2*m; i++) {
			for (j=0; j<2*m; j++) {
			    if (i==j)
				X(i,j+1) = 1;
			    else
				X(i,j+1) = 0;
			}
		    }
		  
		  flux(&t,x,&h,dt/2,pasmin,pasmax,tolfl, npasmx,n,camp,prm);
		  
		  /*Guardem segona matriu de variacionals*/
		  for(i=0; i<2*m; i++){
		    for(j=0; j<2*m; j++){
		      DGv1(i,j) = X(i,j+1);
		    }
		  }
		  
		  for(i=0; i<2*m; i++){
		    g[i] = x[i] - xf[i];
		  }
		  
		  
		  for(i=0; i<2*m; i++){
		    for(j=0; j<m; j++){
		      DG(i,j) = 0;
		      for(k=0; k<2*m; k++){
			DG(i,j)+=DGv1(i,k)*DGv0(k,m+j);
		      }
		      DG(i,j+m) = DGv1(i,j+m);
		    }
		  }
		  
		  
		  return 0;
		}
int cmani (int m, double x0[], double xf[], double dt, //mateixos parametres que a cmani_gdg
	   double dv[],//(entrada/sortida) apunta a un vector de llargada 2m que conte \deta v
	   double tol, int maxit, // tolerancia i num maxim de iterats per al metode de Newton
	   double pas0, double pasmin, double pasmax, double tolfl, int npasmx, //parametres per passar a flux()
	   int (*camp)(int n, double t, double x[], double f[], void *prm),//apunta a una funcio que implementa el camp vectorial
	   void *prm){
  
	   /*Newton method*/
	    int i,k;
	    
	    double g[2*m];
	    double dg[2*m*2*m];
	    double dr[2*m];
	    double s[2*m];
	    
	    double normg=0;
	    double norms=0;
	    
	    
	   
	    for(k=0; k<maxit; k++){
	      
	      cmani_gdg(m,x0,xf,dt,dv,g,dg,pas0,pasmin,pasmax,tolfl,npasmx,camp,prm);
	      
	      normg=0;
	      for(i=0; i<2*m; i++){
		normg+=g[i]*g[i];
	      }
	      normg=sqrt(normg);
	      
	       fprintf(stderr,"cmani():: it %d ng %g ",k,normg);
	      
	       /*soluciona DG * s = g*/
	       qrres(2*m,2*m,dg,dr,g,s); // dg matriu del sistema, dr no el usem pero qrres el requereix, g = vector b del sistema, s = solucio del sistema
	       
	      
	      norms=0;
	      for(i=0; i<2*m; i++){
		norms+=s[i]*s[i];
	      }
	      norms=sqrt(norms);
	      if(norms<tol)	break;
	      
	      
	      fprintf(stderr,"nc %g\n", norms);
	      
	      // fem un pas del metode de newton
		for(i=0; i<2*m; i++){
		  dv[i]-=s[i];
		}
		
	    

	      if(k==maxit-1) fprintf(stderr,"cmani():: El metode de Newton ha assolit el seu nombre maxim d'iteracions\n");
	      
	      
	    }
	    fprintf(stderr,"\ndv[] ");
	    for(i=0; i<2*m; i++){
	      fprintf(stderr,"%.16G ",dv[i]);
	    }
	    fprintf(stderr,"\n");
	    return 0;
	  }
