set terminal pngcairo size 1800,600 enhanced font 'Verdana,20'
set output 'pendol.png'

set title "Retrat-Fase del Pèndol"

set key bottom center outside

set grid

set xrange[-10:10]
set yrange[-3:3]
set cbrange [0.06:0.16]

plot 'pendol.txt' u 2:3:4 w l palette lw 1.5