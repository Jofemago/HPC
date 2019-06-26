#!/bin/bash

g++ -std=c++11 -o o.o -fopenmp buffonNedleeOmp.cpp

k="\n"
j=100
f=99

for w in 2 3 4 5
do
	for h in 2 3 4 5
	do
		for l in 1 2 3 4 5 6 7 8 9 10
		do
		    for i in 100 1000 10000 100000 1000000 10000000 100000000 1000000000
		    do
		        ./o.o $i $j $f $w $h #>> prueba.csv
		    done
		    echo $k #>> prueba.csv
		done
		echo $k #>> prueba.csv
	done
	echo $k
done
