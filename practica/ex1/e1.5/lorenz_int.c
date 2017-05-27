#include <stdio.h>
#include "flux.h"
#include "lorenz.h"

#define PAS_INICIAL 0.0001
#define dT tf/nt
#define PASMIN 1E-6
#define PASMAX 0.5
#define N 3
#define TOL 1E-12
#define NPASMAX 10000000
#define CAMP lorenz
#define PRM p

/*
 * Per compilar:
        gcc -o lorenz_int -g -Wall lorenz_int.c lorenz.c rk78.c flux.c -lm
 */

#define N 3

int main (int argc, char *argv[]) {
   double t, x[N], h,p[3];
   int i;
   double tf;
   int nt;
   
   
   if (argc!=6
         || sscanf(argv[1],"%lf",&p[0])!=1
         || sscanf(argv[2],"%lf",&p[1])!=1
         || sscanf(argv[3],"%lf",&p[2])!=1
         || sscanf(argv[4],"%lf",&tf)!=1
         || sscanf(argv[5],"%d",&nt)!=1
      ) {
     // fprintf(stderr, "./lorenz_int hmin hmax tol\n");
      fprintf(stderr, "./lorenz_int sgm rho bet tf nt\n");
      return -1;
   }
   
   while (scanf("%lf %lf %lf",&x[0],&x[1],&x[2])==3) {
      
      t=0; h=PAS_INICIAL;
      printf("%22.15E %22.15E %22.15E %22.15E\n",t ,x[0], x[1], x[2]);
      for (i=0; i<nt; i++) {
	 flux(&t, x, &h, dT,PASMIN,PASMAX,TOL,NPASMAX,N,CAMP,PRM);
         printf("%22.15E %22.15E %22.15E %22.15Ea\n",t ,x[0], x[1], x[2]);
      }
      printf("\n\n");
      
   }
   
   return 0;
}
