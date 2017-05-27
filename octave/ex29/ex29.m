% Codi solució de l'exercici (29) llista de problemes octave. Aquest codi necessita usar el fitxer DFex29.m
%
% Aquest fitxer no s'ha d'executar desde Octave, les línies s'han d'executar una a una. (chou).
%
%
%%%%%%%%%%%%%%%%%(APROXIMACIÓ DE LA SOLUCIÓ):%%%%%%%%%%%%%%%%%
%
% Aproximem la solució en N=10 punts:
N=10; [x,u, u_exact, meanError] = DFex29(N);
% Fem el plot de la solució exacta vs la aproximada 
plot(x,u,x,u_exact) 
%printem la mitjana de l'error:
meanError
%printem la apoximació calculada:
u
%
%
%Aproximem la solució en N=20 punts: (mateix codi diferent N)
N=20; [x,u, u_exact, meanError] = DFex29(N);
% Fem el plot de la solució exacta vs la aproximada 
plot(x,u,x,u_exact) 
%printem la mitjana de l'error:
meanError
%printem la apoximació calculada:
u
%
%
%(REMARK): 'h' és inversament proporcional al número de punts N per tant canviar N equival a canviar h, nota a més que al aumentar N (disminuir h) la mitjana d'error disminueix.
%

%%%%%%%%(Check numèric de l'ordre de convergència):%%%%%%%%
N=10; 
[xN,uN, uN_exact, meanErrorN] = DFex29(N);  
[x2N,u2N, u2N_exact, meanError2N] = DFex29(2*N);
meanErrorN/meanError2N

%mateix check incrementant número de passos
N=50; 
[xN,uN, uN_exact, meanErrorN] = DFex29(N);  
[x2N,u2N, u2N_exact, meanError2N] = DFex29(2*N);
meanErrorN/meanError2N

%mateix check incrementant número de passos
N=100; 
[xN,uN, uN_exact, meanErrorN] = DFex29(N);  
[x2N,u2N, u2N_exact, meanError2N] = DFex29(2*N);
meanErrorN/meanError2N

%mateix check incrementant número de passos
N=400; 
[xN,uN, uN_exact, meanErrorN] = DFex29(N);  
[x2N,u2N, u2N_exact, meanError2N] = DFex29(2*N);
meanErrorN/meanError2N
%
%
%(REMARK): nota que el quocient d'errors al doblar N (dividir h per 2) tendeix a 4, per tant és raonable pensar que el mètoe és d'ordre 2 en h.
