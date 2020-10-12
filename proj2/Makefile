#
# Name: bjr
# Date: 5 sep 2016
# 
# Note: Makefiles begin with a captal M
#   Indentation MUST be with a tab
#
# tagets build, test, clean and submit are required.
# 

RED= \033[0;31m
GREEN= \033[0;32m
NC= \033[0m
M= Makefile

COPTS=

build:
	make ringbuf

ringbuf: ringbuf.c ringbuf-sub.o ringbuf.h
	cc ${COPTS} -o $@ ringbuf-sub.o $<

ringbuf-sub.o: ringbuf-sub.c ringbuf.h
	cc ${COPTS} -c -o $@ $<
	
test: ringbuf
	-rm ringbuf.out
	./ringbuf +abcdefghijklmno+pq-rs--tuv+ > ringbuf.out
	diff ringbuf.out ringbuf.ref
	@echo "*** ${GREEN}PASSED the test ${NC}***"

mytest: ringbuf
	@echo "testing: * ringbuf when empty" 
	-rm test.txt
	./ringbuf abc----+-hello > test.txt
	diff test.txt test.ref	 

#the final + should have 10 as the RB Count
mytest2: ringbuf
	@echo "testing: * ringbuf RB Count when head < tail"
	-rm rbcount.fout
	./ringbuf +abcdefghijklmnopqrs+------+ > rbcount.fout
	diff rbcount.fout rbcount.ref

mytest3: ringbuf
	@echo  "testing: * ringbuf with the -v option"
	./ringbuf -v mynameisKalpit--+

mytest4: ringbuf
	@echo "testing: * ringbuf without any arguments"
	./ringbuf

clean:
	-rm ringbuf ringbuf-sub.o ringbuf.out test.txt rbcount.fout

submit:
	@echo svn add your work
	svn commit -m "submitted for grading"


