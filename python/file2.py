#!/usr/bin/python

# open a file 
fi = open("config.txt", "r+")
"""
print "Name of the file: ", fi.name
print "Closed or not: ", fi.closed
print "Opening mode: ", fi.mode
print "Softspace flag: ", fi.softspace

str = fi.readline();
print str

pos = fi.tell();
print "current file position: ", pos
"""

str = fi.readlines();
print str

for line in str:
   print line

# close opened file
fi.close()
