#!/bin/bash
# This is a comment!

g++ -std=c++11 -o secuencial.o dartboard.cpp

k = "\n"
for l in 1 2 3 4 5 6 7 8 9 10
do
	for j in 1 2 3 4 5 6 7 8 9 10
	do
	    for i in 100 1000 10000 100000 1000000 10000000 100000000 100000000
	    do
	        ./secuencial.o $i #>> prueba.csv 
	    done
	    echo $k #>> prueba.csv
	    
	done
done