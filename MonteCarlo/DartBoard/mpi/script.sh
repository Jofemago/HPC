#!/bin/bash
# This is a comment!



k="\n"
for l in 1 2 3 4 5 6 7 8 9 10
do
    for i in 100 1000 10000 100000 1000000 10000000 100000000 1000000000
    do
        mpiexec -n 8 -machinefile machines shsources/bin/outbravo $i #>> prueba.csv
    done
    echo $k #>> prueba.csv

done
