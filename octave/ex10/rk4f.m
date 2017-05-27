%
% function eta=rk4f(y0,h,N)
%
% Per a f(y)=3*y, aplica el mètode Runge-Kutta clàssic per a
% aproximar la solució del PVI y'=f(y), y(0)=y0 amb pas h, des de
% temps 0 fins a temps N*h.
%
% Torna un vector fila de llargada N+1 amb les aproximacions de la
% solució a temps 0, h, 2*h, ..., N*h
%
% Aquest codi és part de la resolució de l'(exercici 10) Octave
% Per a veure la resolució de l'exercici 10 obra ex10.m

function eta=rk4f(y0,h,N)
   eta=zeros(1,N+1);
   eta(1)=y0;
   for i=1:N
   
      k1=3*eta(i);
      k2=3*(eta(i) +(1/2)*h*k1);
      k3=3*(eta(i) +(1/2)*h*k2);
      k4=3*(eta(i)+h*k3);
      
      phi= (1/6)*(k1+2*k2+2*k3+k4);
      eta(i+1)=eta(i)+h*phi;
   end
end
