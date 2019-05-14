#!/bin/bash
# This is a comment!

k = "\n"
for sp in 10 100 1000 10000 100000 1000000 10000000 100000000 1000000000 10000000000 100000000000
do
    for j in 1 2 3 4 5 6 7 8 9 10
    do
        for n in 100 1000 2000 3000 4000 5000 6000 7000 8000 9000 10000 20000 30000 40000 50000 60000 70000 80000 90000 100000 1000000 10000000
        do
            ./jps.o $n #>> prueba.csv
        done
        echo $k #>> prueba.csv
    done
    echo $k
    echo $k
    echo $k
done
