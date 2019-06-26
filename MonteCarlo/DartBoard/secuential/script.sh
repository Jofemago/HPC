#!/bin/bash
# This is a comment!

g++ -std=c++11 -o secuencial.o dartboard.cpp

k="\n"

for j in {1..10}
do
    for i in 100 1000 10000 100000 1000000 10000000 100000000 1000000000
    do
        ./secuencial.o $i #>> prueba.csv
    done
    echo $k #>> prueba.csv
done

