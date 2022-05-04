#!/bin/bash

DIR="push_swap"
CHECKER="checker"
total=0
l=0
n=1
max=0
avg=0
gcc r.c -o r


while [ $n -lt 100 ];do
	ARG=$(./r $1)
	str=$(../${DIR}/push_swap $ARG | ../${DIR}/${CHECKER} $ARG)
	if [ $str == "OK" ]; then
		l=$(../${DIR}/push_swap $ARG | wc -l)
	fi
	if [ $l -gt $max ];then
		max=$l
	fi
	total=$(($total + $l))
	avg=`echo "scale=2;$total/$n" | bc`
	#echo $avg
	n=$(($n + 1))
done

echo $avg
echo $max