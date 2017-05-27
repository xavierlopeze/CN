
#include <math.h>

#define X x[0] //x_0
#define Y x[1] //x_1

#define XD f[0] //x'_0
#define YD f[1] //x'_1

#define N 2

#define A(i,j) x[N+(j)*N+(i)]

#define ALPHA 0.5


int camp21 (int n, double t, double *x, double *f, void *prm) {
  
  
// Equacions 

   f[0]=ALPHA*(X-X*X*X-Y*Y*X)-Y; //x_0=f_0(t,x)
   f[1]=X+ALPHA*(Y-X*X*Y-Y*Y*Y); //x_1 =f_1(t,x) 
      

   if (n==2) return 0;

// Variacionals 
  double df[4];
   
   df[0]= ALPHA*(1-3*X*X-Y*Y);//df f_0(t,x) / dx_0
   df[1]= ALPHA*(-2*Y*X)-1;//df f_0(t,x) / dx_1
   df[2]= 1+ALPHA*(-2*X*Y);//df f_1(t,x) / dx_0
   df[3]= ALPHA*(1-X*X-3*Y*Y);//df f_1(t,x) / dx_1
   
   //F_i,j = 
   f[2]= df[0]*A(0,0) + df[1] * A(1,0); //i=0,j=0
   f[3]= df[2]*A(0,0) + df[3] * A(1,0); //i=1,j=0
   f[4]= df[0]*A(0,1) + df[1] * A(1,1); //i=0, j=1
   f[5]= df[2]*A(0,1) + df[3] * A(1,1); //i=1, j=1
 
  
   return 0;
}

#undef W
#undef V
#undef U


#undef X  //x_0
#undef Y  //x_1

#undef XD  //x'_0
#undef YD 

#undef A

#undef ALPHA


