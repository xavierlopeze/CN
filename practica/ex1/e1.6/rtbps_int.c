#include <stdio.h>
#include "flux.h"
#include "rtbps.h"

#define PAS_INICIAL 0.001
#define dT tf/nt
#define PASMIN 1E-7
#define PASMAX 0.5
#define N 6
#define TOL 1E-12
#define NPASMAX 1000000
#define CAMP rtbps
#define PRM p

/*
 * Per compilar:
        gcc -o lorenz_int -g -Wall lorenz_int.c lorenz.c rk78.c flux.c -lm
 */


int main (int argc, char *argv[]) {
   double t, x[N], h,p[3];
   int i;
   double tf;
   int nt;
   
   
   if (argc!=2
         || sscanf(argv[1],"%lf",&p[0])!=1
      ) {
     // fprintf(stderr, "./lorenz_int hmin hmax tol\n");
      fprintf(stderr, "./rtbps_int mu\n");
      return -1;
   }
   
   while (scanf("%lf %lf %lf %lf %lf %lf %lf %d",&x[0],&x[1],&x[2],&x[3],&x[4],&x[5], &tf, &nt)==8) {
      
      t=0; h=PAS_INICIAL;
      printf("%22.15E %22.15E %22.15E %22.15E %22.15E %22.15E %22.15E\n",t ,x[0], x[1], x[2], x[3], x[4], x[5]);
      for (i=0; i<nt; i++) {
	 flux(&t, x, &h, dT,PASMIN,PASMAX,TOL,NPASMAX,N,CAMP,PRM);
         printf("%22.15E %22.15E %22.15E %22.15E %22.15E %22.15E %22.15E\n",t ,x[0], x[1], x[2], x[3], x[4], x[5]);
      }
      printf("\n\n");
      
   }
   
   return 0;
}
