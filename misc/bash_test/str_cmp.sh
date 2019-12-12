#!/bin/bash
echo "Enter a string:"
read str1
echo "Enter another string:"
read str2

if [[ $str1 == $str2 ]]
then
	echo "Both strings are the same"
else
	echo "The two strings are different"
fi

if [[ $str1 == *condition* ]]
then
	echo "String "$str1 has the word \"condition\"
fi
