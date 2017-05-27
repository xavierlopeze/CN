#include <math.h>

#define X1 x[0]
#define X2 x[1]
#define X1D f[0]
#define X2D f[1]
#define N 2
#define A(i,j) x[N+(j)*N+(i)]

int pendol (int n, double t, double *x, double *f, void *prm) {
  /*Equivalent a fer:*/
  /*
  * f[0]=x[1];
  * f[1]=-sin(x[0]);
  */
   X1D=X2;
   X2D=-sin(X1);
   
   /*Variacionals*/
	//(note that other files named 'pendol.c' from other exercices do not need, and therefore don't have the variationals implementation
	
   if(n==N) return 0;	//the answer my friend, is blowing in the variationals (dont miss them):
     
     double df[4]; // t'agrada derivar?:
     df[0] = 0; //df f_0(t,x) / dx_0
     df[1] = 1; //df f_0(t,x) / dx_1
     df[2] = -cos(x[0]); //df f_1(t,x) / dx_0
     df[3] = 0; //df f_1(t,x) / dx_1
     
    //F_i,j = 
    f[2]= df[0]*A(0,0) + df[1] * A(1,0); //i=0,j=0
    f[3]= df[2]*A(0,0) + df[3] * A(1,0); //i=1,j=0
    f[4]= df[0]*A(0,1) + df[1] * A(1,1); //i=0, j=1
    f[5]= df[2]*A(0,1) + df[3] * A(1,1); //i=1, j=1
    
    /*Equivalent a fer:*/
    /*
     * f[2]=x[3];
     * f[3]=-x[2]*cos(x[0]);
     * f[4]=x[5];
     * f[5]=-x[4]*cos(x[0]);
     */
   return 0;
}

#undef X1
#undef X2
#undef X1D
#undef X2D

