#!/bin/bash
# This is a comment!

g++ -std=c++11 -fopenmp -o omp.o dartboardomp.cpp

k="\n"
for h in 2 3 4 5
do
	for j in {1..10}
	do
	    for i in 100 1000 10000 100000 1000000 10000000 100000000 1000000000
	    do
	        ./omp.o $i $h #>> prueba.csv
	    done
	    echo $k #>> prueba.csv
	done
	echo $k #>> prueba.csv
done
