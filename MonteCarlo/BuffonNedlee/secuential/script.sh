#!/bin/bash

g++ -std=c++11 -o o.o buffonNedlee.cpp

k="\n"
j=100
f=99

for q in 1 2 3 4 5 6 7 8 9 10
do
	for i in 100 1000 10000 100000 1000000 10000000 100000000 100000000
	do
	    ./omp.o $i $j $f #>> prueba.csv 
	done
	echo $k #>> prueba.csv	    
done
