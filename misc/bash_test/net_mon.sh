#!/bin/bash

while true; do \
	echo "$1"; \
	date; \
	ethtool $1 | grep -e "Speed" -e "Duplex"; \
	ifconfig $1 | grep -e "TX errors" -e "RX errors"; \
	sleep 1; \
done;
