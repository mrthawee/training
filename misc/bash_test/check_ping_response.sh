#!/bin/bash
echo "Enter an IP address:"
read ip

if [ ! -z $ip ]
then
	ping -c 1 $ip
	if [ $? -eq 0 ] ; then
		echo "Go ping response"
	else
		echo "No ping response"
  fi
else
	echo "IP address is empty"
fi
