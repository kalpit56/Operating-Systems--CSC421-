# 
# makefile for csc421-211 project 1
# compiles and runs a basic test.
# last modified: 21 aug 2020
# last-update: 
#    21 aug 2020
#    22 aug 2020 bjr: added test3
#


RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m
M= Makefile

all:
	make mytee
	
test: mytee
	make test1
	make test2
	make clean
	@echo "*** ${GREEN}PASSED the test ${NC}***"

mytee: mytee.c
	gcc -o mytee mytee.c

test1: mytee
	./mytee -v 
	
test2: mytee
	cat mytee.c | ./mytee mytee.fout > mytee.out
	diff mytee.fout mytee.c
	diff mytee.c mytee.out

test3: mytee
	dd if=/dev/urandom bs=1 count=4096 of=random.bin
	cat random.bin | ./mytee mytee.fout > mytee.out 
	diff random.bin mytee.fout 
	diff random.bin mytee.out


mytest: mytee
	@echo "* testing: * mytee called without argument"
	./mytee

mytest2: mytee 
	@echo "testing: * mytee called with -a option"
	cat mytee.c | ./mytee mytee.fout > mytee.out
	cat mytee.c | ./mytee -a mytee.fout > mytee.out
	cat mytee.fout | ./mytee mytee.fout > mytee.out
	diff mytee.fout mytee.out

mytest3: mytee
	@echo "testing: * mytee on an empty file"
	touch empty.txt | ./mytee empty.fout	
	diff empty.fout empty.txt

clean:
	-rm mytee.fout mytee.out mytee random.bin empty.txt empty.fout empty.out


