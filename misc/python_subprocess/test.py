#!/usr/bin/python3

import subprocess, re

def ping_test(ip):
    cmd = ['ping', '-c 3', ip]
    ret = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, encoding='utf-8')
    #print(ret.stdout)
    lines = re.split("[\r\n]+", ret.stdout)

    for line in lines:
        if line[0:3] == "rtt":
            #print(line)
            left, right = line.split("=")
            left = left[4:]
            right = right[:-3]
            #print(left, right)

            mn, av, mx, md = right.split("/")
            mn = float(mn)
            av = float(av)
            mx = float(mx)
            md = float(md)
            print(mn,av,mx,md)


def ifconfig_test(eth_dev):
    cmd = ['ifconfig', eth_dev]
    ret = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, encoding='utf-8')
    #print(ret.stdout)
    lines = re.split("[\r\n]+", ret.stdout)

    for line in lines:
        line = line.lstrip()
        print(line)

if __name__ == "__main__":
    ping_to_ip = "8.8.8.8"
#    ping_test(ping_to_ip)
    eth_dev = "enp0s3"
    ifconfig_test(eth_dev)
