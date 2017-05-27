#include <stdio.h>
#include "cmani.h"
#include "rtbps.h"

#define N 6
#define M 3
#define PRM prm

#define PAS0 0.001
#define PASMIN 1e-6
#define PASMAX 0.5
#define TOL 1e-14
#define NPASMX 1000000
#define CAMP rtbps



//gcc -o cmani_rtbp -g -Wall cmani_rtbp.c cmani.c flux.c rk78.c qrres.c rtbps.c -lm 
// ./cmani_rtbp 1.215058560962404e-2 1e-12=tolnwt 10=maxitnwt < cmani_rtbp.inp

int main (int argc, char *argv[]) {

    double prm[1], prmNWT[2];
    double x[2*N], x0[N],xf[N];
    double dv[N]; 
    double dt;
    int i;

    /* PRIMERA LECTURA DE PARÀMETRES: Llegim arguments (camp i Newton) */
    if (argc != 4 // si no llegim bé els parametres
            || sscanf(argv[1],"%lf",&prm[0])!=1
            || sscanf(argv[2],"%lf",&prmNWT[0])!=1
            || sscanf(argv[3],"%lf",&prmNWT[1])!=1
       ) {
        //tornem missatge error demanant parametres correctes
        fprintf(stderr,"%s mu tolwnt maxitnwt\n",argv[0]); 
        return -1;
    }

     /* SEGONA LECTURA DE PARÀMETRES: posicions i velocitats (inicials i finals) */
    if(scanf("%lf",&dt)!=1){//llegim argument dt i si no tornem error
      //tornem missatge error demanant parametres correctes
      fprintf(stderr, "%s: dt x0[0] x0[1] x0[2] x0[3] x0[4] x0[5] xf[0] xf[1] xf[2] xf[3] xf[4] xf[5]\n",argv[0]);    
      return -1;
    }
	
    for (i=0; i<2*N; i++) { // llegim posicions i si no tornem error
	if (scanf("%lf",&x[i])!=1) {
	    //tornem missatge error demanant parametres correctes
	    fprintf(stderr, "%s: dt x0[0] x0[1] x0[2] x0[3] x0[4] x0[5] xf[0] xf[1] xf[2] xf[3] xf[4] xf[5]\n",argv[0]); 
	    return -1;
	}
    }

    /* Inicialitzem condicions inicials per a la posició x0,xf i dv = 0 */
    for (i=0; i<N; i++) {
	x0[i] = x[i]; //posicions i velocitats inicials
	xf[i] = x[i+N];//posicions i velocitats finals
	dv[i] = 0; //correcció a la velocitat
    }

    cmani(M,x0,xf,dt,dv,prmNWT[0],(int)prmNWT[1],PAS0,PASMIN,PASMAX,TOL,NPASMX,CAMP,prm);

    for (i=0; i<N; i++) printf("%22.15E ",dv[i]);
    
    printf("\n");

    return 0;
}