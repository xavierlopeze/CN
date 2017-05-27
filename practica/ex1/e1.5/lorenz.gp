set term x11 size 700,700
set view equal xyz
set ticslevel 0.1

set term png
set output "lorenz.png"
splot 'lorenz.txt' u 2:3:4 w l
set term x11
set out
splot 'lorenz.txt' u 2:3:4 w l
pause mouse close
exit
