#!/bin/bash



k="\n"

aux = 0
for q in 1 2 3 4 5 6 7 8 9 10
do
	for i in 1000 10000 100000 #1000000 10000000 100000000 10000000
	do
      ./o.o $i #100 10000 1000000 100000000   #>> ./data/prueba$j.csv 
	done
	echo $k #>> prueba$aux.csv

done