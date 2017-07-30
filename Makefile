SHELL := /bin/bash
# SHELL:= /bin/sh  # default

lib= /home/kevin/Documents/mysqlStuff/data/BMWCars/
CC= g++
CFLAGS= -c -Wall
sqlInclude= /usr/include/
sqlCppconn= /usr/include/cppconn/
mysqlLocal= /usr/local/include/
#all: bmwimport_json.x

# This works on command line:
# g++ -c -Wall bmwimport_json.cpp -I./BMWCars/
# g++ bmwimport_json.o -obmwimport_json.x

# .o files depend on the .c files of header file, so re-make.
# $@ represents the label; $< is the first item in dependency list.
# $^ right side of semicolon.
#%.o: %.c $(lib)Car.hpp 
#	$(CC) -c -o $@ 

bmwimport_json.x:  bmwimport_json.o
	$(CC) bmwimport_json.o -obmwimport_json.x -lmysqlcppconn 

bmwimport_json.o:  ./bmwimport_json.cpp $(lib)Car.hpp $(mysqlLocal)_mysql.h
	$(CC) $(CFLAGS) bmwimport_json.cpp -I$(lib) -I$(sqlInclude) -I$(sqlCppconn) -lmysqlcppconn 

clean:
	rm -rf *.o
