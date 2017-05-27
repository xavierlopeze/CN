int campt2 (int n, double t, double *x, double *f, void *prm) {
  
   f[0]=2*x[0]/t;  //y'=2*y/t camp vectorial
		   // te per solucio y=t^2+t0 (en aquestes condicions inicials t0=0)
   return 0;
}
