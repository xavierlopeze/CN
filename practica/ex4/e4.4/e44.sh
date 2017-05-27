# Executable per exercici 2

#Compilem
 gcc -o cmani_rtbp -g -Wall cmani_rtbp.c cmani.c flux.c rk78.c qrres.c rtbps.c -lm 

#Executem
./cmani_rtbp 1.215058560962404e-2 1e-12=tolnwt 10=maxitnwt < cmani_rtbp.inp


