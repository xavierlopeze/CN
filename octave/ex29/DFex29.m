% Aquest codi és la funció fonamental per a resoldre l'exercici (29) Llista de problemes en Octave.
%
% (Ex 29): Considerem el problema de valors a la forntera:
%		-y''+(2/x^2)y=0
%		y(1)=1; y(2)=1/2;
%  	   que té per solució y(x)=1/x.
%
%	-Aproximeu la solució per diferències finites d'acord amb el problema
% 	anterior, per diversos valors del pas h.
%
%	-Determineu l'ordre d'aproximació en h
%
% (INPUT): La funció DFex29(n)reb per input 'n', que és el número de punts en que es calcularà l'aproximació en diferències finites de la solució de l'equació diferencial discretitzada sobre l'interval [a,b]=[1,2].
%
% (OUTPUT): La funció DFex29(n) torna: [x_full, u_full, exact_full, meanError]:
%	-x_full: x_i=a+ih, i=0..n+1, h=(b-a)/(n+1)
%	-u_full aproximació en diferències finites de la solució de l'equacio diferencial discretitzada en n punts sobre l'interval [a,b]=[1,2]
%	-exact_full:solució exacta de l'equacio diferencial discretitzada en n punts sobre l'interval [a,b]=[1,2]
%	-meanError: la mitjana de l'error que s'ha comes en l'aproximació en diferències finites de la solució de l'equacio diferencial discretitzada en n punts sobre l'interval [a,b]=[1,2]
%
% (REMARK): La h usada en el mètode en diferències finites és inversmanet proporcional a 'n' (input).
%
% (UASAGE Example): errorDifFinitesEx29(20)
%
% El 'chou' està al fitxer 'ex29.m'

function [x_full, u_full, exact_full, meanError] = DFex29(n)

	x=zeros(1,n); q=zeros(1,n);
	a=1; b=2; h=(b-a)/(n+1); %(remark)
	for i=1:n
		x(i)=a+i*h;
		q(i)=2./(x(i)^2);
		exact(i) = 1/x(i);
	end

	%Definim el sistema matricial, revisa (ex 28) (a):
	A=zeros(n,n); k=zeros(1,n);
	alpha=1; beta=1/2; %y(1)=1; y(2)=1/2;
	for i=2:n-1
		A(i,i)=2+(h^2)*q(i); A(i,i+1)=-1; A(i,i-1)=-1;
	end
	A(1,1)=2; A(1,2)=-1; A(n,n)=2+(h^2)*q(1); A(n,n-1)=-1+(h^2)*q(n); k(1)=alpha; k(n)=beta;
	u=transpose(pinv(A)*(k.')); %Solució del sistema i aproximació de la solució

	u_full=[alpha, u(1:n), beta]; exact_full=[alpha, exact(1:n), beta]; x_full=[a, x(1:n), b]; %Afegim termes als extrems

	meanError=mean(u-exact);%mitjana de l'error
end


