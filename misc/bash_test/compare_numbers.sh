#!/bin/bash
echo "Please enter first number:"
read first
echo "Please enther second number:"
read second

if [ $file -eq 0 ] && [ $second -eq 0 ]
then
	echo "Num1 and Num2 are zero"
elif [ $first -eq $second ]
then
	echo "Both Num1 and Num2 are equal"
elif [ $first -gt $second ]
then
	echo "$first is greater than $second"
else
	echo "$first is less than $second"
fi
