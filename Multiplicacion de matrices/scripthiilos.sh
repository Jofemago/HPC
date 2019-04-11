#!/bin/sh
# This is a comment!

k = "\n"

for j in 1 2 3 4 5 6 7 8 9 10
do
    for i in 50 100 200 300 400 500 600 700 800 900 1000 1200 1400 1600
    do
        ./hil $i #>> prueba.csv 
    done
    echo $k #>> prueba.csv
done
