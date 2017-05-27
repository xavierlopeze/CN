% Codi solució de l'exercici (12) llista de problemes octave. 
% Aquest codi necessita usar els fitxers abm4.m i f.m
%
% Aquest fitxer no s'ha d'executar desde Octave, les línies s'han d'executar una a una. (chou).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Check numèric de l'ordre de convergència per al camp donat per f(y)=3*y: f(0)=y0=1

N=50; err1=(abm4(@f,0,1,1,N)(N+1)-exp(3*1)); err2=(abm4(@f,0,1,1,2*N)(2*N+1)-exp(3*1)); err1/err2

N=200; err1=(abm4(@f,0,1,1,N)(N+1)-exp(3*1)); err2=(abm4(@f,0,1,1,2*N)(2*N+1)-exp(3*1)); err1/err2

N=400; err1=(abm4(@f,0,1,1,N)(N+1)-exp(3*1)); err2=(abm4(@f,0,1,1,2*N)(2*N+1)-exp(3*1)); err1/err2

N=1000; err1=(abm4(@f,0,1,1,N)(N+1)-exp(3*1)); err2=(abm4(@f,0,1,1,2*N)(2*N+1)-exp(3*1)); err1/err2

%Nota que el quocient tendeix a 16 = 2^4, per tant tot indica que el mètode té ordre 4.