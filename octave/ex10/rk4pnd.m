%
% function eta=rkpnd(x0,h,N)
%
% Per a f(x) el camp vectorial del pèndol, aplica el mètode Runge-Kutta
% clàssic per a aproximar la solució del PVI x'=f(x), x(0)=x0, amb
% pas h, des de temps 0 fins a temps N*h.
%
% Torna un vector fila de llargada N+1 amb les aproximacions de
% la solució a temps 0, h, 2*h, ..., N*h.
%
% Aquest codi és part de la resolució de l'(exercici 10) Octave
% Per a veure la resolució de l'exercici 10 obra ex10.m


function xi=rk4pnd(x0,h,N)
   xi=zeros(2,N+1);
   xi(:,1)=x0;
   for i=1:N
      
      k11=xi(2,i);
      k12=-sin(xi(1,i));
      
      k21=xi(2,i)+(1/2)*h*(k12);
      k22=-sin(xi(1,i)+(1/2)*h*k11);
      
      k31=xi(2,i)+(1/2)*h*(k22);
      k32=-sin(xi(1,i)+(1/2)*h*k21);
      
      k41=xi(2,i)+h*(k32);
      k42=-sin(xi(1,i)+h*k31);
      
      phi=[
	(1/6)*(k11+2*k21+2*k31+k41);
	(1/6)*(k12+2*k22+2*k32+k42)
      ];
      
      xi(:,i+1)=xi(:,i)+h*phi;
   end
end

%tf=4*pi; M=1000; MM=100000; xf=rkpnd([1;0],tf/MM,MM)(:,MM+1); N=M; err1=norm(rkpnd([1;0],tf/N,N)(:,N+1)-xf); N=2*M; err2=norm(rkpnd([1;0],tf/N,N)(:,N+1)-xf); err1/err2

