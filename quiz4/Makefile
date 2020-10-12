#
# quiz4 makefile
# csc421 211
# author:
# last modified:
#
#

build:
	make quiz4

quiz4: quiz4.c quiz4-sub.o quiz4.h
	cc -o $@ quiz4-sub.o $<

quiz4-sub.o: quiz4-sub.c quiz4.h
	cc -c -o $@ $<

test: quiz4
	./quiz4 now is the time for all good people
	./quiz4
	./quiz4 -v

clean: 
	-rm quiz4 quiz4-sub.o 
