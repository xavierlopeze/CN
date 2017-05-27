gcc -o lorenz_int -g -Wall lorenz_int.c lorenz.c rk78.c flux.c -lm

rm lorenz.txt
echo "-0.4164607449115608 -0.9089362634520914 0.01438311162938695" | ./lorenz_int 3=sigma 26.5=rho 1=beta 150=tf 25000=nt > lorenz.txt
gnuplot lorenz.gp
echo "Fet"

replot