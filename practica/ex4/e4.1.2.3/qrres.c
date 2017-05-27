/*
* Donada la matriu A m x n, fa la seva descomposici ́o QR i,
* opcionalment, resolt un sistema sobredeterminat associat.
*
* Arguments:
* - m,n (e) : nombre de files i columnes de la matriu A.
*   Restricci ́o: m>=n.
* - a (e/s) : En entrar, a[i+j*m], i=0..m-1, j=0..n-1 han de ser els
*   coeficients de la matriu a (per files). En sortir:
*   + Dins a[i+j*m], j>i, hi ha la part de sobre la diagonal de la R
*     de la descomposici ́o QR.
*   + Dins a[i+k*m], i=k..m-1, hi ha les coordenades de la
*     k-`esima reflexi ́o de Householder que s’ha aplicat, k=0..n-1.
* - dr (s) : en sortir cont ́e la diagonal de R (dr[j]  ́es el coeficient
*   de la fila j, columna j de R, j=0..n-1).
* - b (e/s) : En entrar: terme independent del sistema lineal14
*   sobredeterminat que es vol resoldre. En sortir:
*         P(n-1) P(n-2) ... P(0) b
*   on P(k) es la k-`esima reflexi ́o de Householder.
*   Si b==NULL, no es fa servir.
* - x (s) : Soluci ́o del sistema sobredeterminat Ax=b.
*   Si b==NULL, no es fa servir.
*/
#include <math.h>
#include <stdio.h>
#define A(i,j) a[i+j*m]
#define SIG(x) (x<0?-1:1)

void qrres (int m, int n, double *a, double *dr, double *b, double *x){
  
  int i,j,k;
  double s,alpha,beta;
  double u[m];
  double aux;
  
  for(k=0; k<n; k++){
    
    /*Calculem s*/
    s=0;
    for(i=k; i<m; i++){
	s+=A(i,k)*A(i,k);
    }
    s=SIG(A(k,k))*sqrt(s);
    
    
    /*Calculem beta*/
    beta = 1/(s*s+s*A(k,k));
    
    /*Calculem u*/
    for(i=k; i<m;i++){
      u[i]=A(i,k);
    }
    u[k]+=s;
    

    /*Calculem t*/
    dr[k]=-s;
    
   
    for(j=k+1; j<n; j++){
      
      /*Calculem alpha*/
      alpha = 0;
      for(i=k; i<m; i++){
	alpha += u[i]*A(i,j);
      }
      
      alpha *= beta;
      
      /*Calculem a*/
      for(i=k; i<m; i++){
	A(i,j) -= alpha*u[i];
      }
      
    }
    
    /*Actualitzem A*/
    
    for(i=k; i<m; i++){
      A(i,k) = u[i];
    }
    
     if(b==NULL) continue; 
     
    /*Calculem alpha*/
   
    alpha = 0;
    for(i=k; i<m; i++){
      alpha += u[i]*b[i];
    }
    alpha *= beta;
    
   
    /*Calculem d*/
    for(i=k; i<m; i++){
      b[i] -= alpha * u[i];
    }
    
     
  }
  
  if(b==NULL) return;
  
  /*Teniem el sistema Ax=b, tenim un nou sistema equivalent al original Rx=b
   *aquest nou sistema es equivalent al original, pero es triangular superior
   *al set tirangular superior podem fer substitucio enrera per a determinar x:
   * 
   * Fem substitucio enrera per a determinar x
   */
  
  for(i=n-1; i>=0; i--){
    aux = 0;
    for(j=i+1; j<n; j++){
      aux += x[j]*A(i,j);
    }
    
    x[i]=(b[i]-aux)/dr[i];
  }
  
  
}