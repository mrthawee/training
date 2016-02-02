#!/usr/bin/python

# open a file 
fo = open("foo.txt", "r+")
print "Name of the file: ", fo.name
print "Closed or not: ", fo.closed
print "Opening mode: ", fo.mode
print "Softspace flag: ", fo.softspace

str = fo.readline();
print str

pos = fo.tell();
print "current file position: ", pos

str = fo.readlines();
print str

# close opened file
fo.close()
