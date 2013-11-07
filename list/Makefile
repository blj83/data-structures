all:	test1 test2
	g++ -o test1 test1.cc
	g++ -o test2 test2.cc

test1:	list.h test1.cc
	g++ -o test1 test1.cc 

test2:	list.h test2.cc
	g++ -o test2 test2.cc 

run1:
	./test1

run2:
	./test2

clean:
	rm test1 test2
