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
	else
		echo "checker test fail!"
		echo $ARG > checker_fail.log
	fi
	if [ $l -gt $max ];then
		max=$l
		if [ $l -gt 5500 ];then
			echo $ARG > outofrange.log
		fi
	fi
	total=$(($total + $l))
	avg=`echo "scale=2;$total/$n" | bc`
	#echo $avg
	n=$(($n + 1))
done

echo $avg
echo $max