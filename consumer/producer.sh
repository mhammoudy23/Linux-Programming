#!/bin/bash
#
val=$( < storage)
max=100
if [ $val -lt $max ]
then
	let num=$val+8
fi
if[ $num -ge $max ]
then
		echo "from producer: Now i will take a rest!"
		exit

	echo "from ptoducer: current total is $num"
	echo $num > storage
	./consumer.c

else
	echo "from producer: Now i will take a rest!"
fi
