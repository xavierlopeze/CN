#include <math.h>

#define X1 x[0]
#define X2 x[1]
#define X3 x[2]

#define X1D f[0]
#define X2D f[1]
#define X3D f[2]



int lorenz (int n, double t, double *x, double *f, void *prm) {
/*
 * f[0]=x[1];
 * f[1]=-sin(x[0]);
 */

/*
 * prm conte els parametres sgm, rho, bet
 */
   double *p = prm;
   double sigma = p[0], rho = p[1], beta = p[2];
   
   X1D=sigma*(X2-X1);
   X2D=-X1*X3+rho*X1-X2;
   X3D=X1*X2-beta*X3;
   return 0;
}

#undef X1
#undef X2
#undef X1D
#undef X2D

