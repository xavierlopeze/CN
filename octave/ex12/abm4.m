% functió y = abm4(f,a,b,y0,n)
%
% Implementa Adams-Bashforth-Moulton mètode predictor-corrector
%  
% Consisteix en:
% Runge-Kutta method of order 4 per inicialitzar
% Adams-Bashforth 4-step method com a predictor
% Adams-Moulton 3-step method com a corrector
%
%
% (Input):
% -f: funció matlab f(t,y) (implementa el camp)
% - a,b: extrems de l'interval [a,b]
% - y0: condició inicial
% - n: nombre de punts en la discretització
%
% (Output):
% y - solució discretitzada
%
% (Remark): Aquesta funció és part de la resolució de l'(exercici 12), 
% per a executar la resolució de l'exercici usa ex12.m on hi ha el 'chou'




%N=200; (abm4(@f2,0,1,1,N)(N+1)-exp(1))/(abm4(@f2,0,1,1,2*N)(2*N+1)-exp(1))
function y = abm4(f,a,b,y0,n)
h = (b - a) / n;
h24 = h / 24;

y(1,:) = y0;
t(1) = a;

q=2;

for i = 1 : (q+1) % fase inicial, usem Runge-Kutta d'ordre 4
    t(i+1) = t(i) + h;
    ff(i,:) = f(t(i), y(i,:));
    k2 = f(t(i) + h / 2, y(i,:) + ff(i,:) * h /2);
    k3 = f(t(i) + h / 2, y(i,:) + k2 * h /2);
    k4 = f(t(i+1), y(i,:) + k3 * h);
    y(i+1,:) = y(i,:) + (ff(i,:) + k2+k2 + k3+k3 + k4) * h / 6;
end;

for i = q+2 : n % fase principal
    ff(i,:) = f(t(i), y(i,:));
    y(i+1,:) = y(i,:) + (55 * ff(i,:) - 59 * ff(i-1,:) + 37 * ff(i-2,:) - 9 * ff(i-3,:)) * h24; % predictor
    t(i+1) = t(i) + h;
    y(i+1,:) = y(i,:) + (9 * f(t(i+1), y(i+1,:)) + 19 * ff(i,:) - 5 * ff(i-1,:) + ff(i-2,:)) * h24; % corrector
end;
