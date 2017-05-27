% Codi solució de l'exercici (10) llista de problemes octave. 
% Aquest codi necessita usar els fitxers rk4f.m i rk4pnd.m
%
% Aquest fitxer no s'ha d'executar desde Octave, les línies s'han d'executar una a una. (chou).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Check numèric de l'ordre de convergència per al camp donat per f(y)=3*y: f(0)=y0=1

% Proveu amb: N= 10, 20, 50, 100, 200, ...
M=10; N=M; err1=rk4f(1,1/N,N)(N+1)-exp(3); N=2*M; err2=rk4f(1,1/N,N)(N+1)-exp(3); err1/err2
M=20; N=M; err1=rk4f(1,1/N,N)(N+1)-exp(3); N=2*M; err2=rk4f(1,1/N,N)(N+1)-exp(3); err1/err2
M=50; N=M; err1=rk4f(1,1/N,N)(N+1)-exp(3); N=2*M; err2=rk4f(1,1/N,N)(N+1)-exp(3); err1/err2
M=100; N=M; err1=rk4f(1,1/N,N)(N+1)-exp(3); N=2*M; err2=rk4f(1,1/N,N)(N+1)-exp(3); err1/err2
M=200; N=M; err1=rk4f(1,1/N,N)(N+1)-exp(3); N=2*M; err2=rk4f(1,1/N,N)(N+1)-exp(3); err1/err2

%Nota que el quocient tendeix a 16 = 2^4, per tant tot indica que el mètode té ordre 4.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Check numèric de l'ordre de convergència per el camp vectorial del pèndol.
tf=4*pi; M=100; MM=10000; xf=rk4pnd([1;0],tf/MM,MM)(:,MM+1); N=M; err1=norm(rk4pnd([1;0],tf/N,N)(:,N+1)-xf); N=2*M; err2=norm(rk4pnd([1;0],tf/N,N)(:,N+1)-xf); err1/err2
%nota que la "solució exacta" que usem, en aquest cas senzillament és una aproximació més acurada. Si canviem MM podem millorar la precisió
tf=4*pi; M=1000; MM=100000; xf=rk4pnd([1;0],tf/MM,MM)(:,MM+1); N=M; err1=norm(rk4pnd([1;0],tf/N,N)(:,N+1)-xf); N=2*M; err2=norm(rk4pnd([1;0],tf/N,N)(:,N+1)-xf); err1/err2

%Nota de nou que el quocient tendeix a 16 = 2^4, per tant tot indica que el mètode té ordre 4.