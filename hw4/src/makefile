OBJS = pdremove.o pdentity.o Date.o pdadd.o pdlist.o pdshow.o

pdremove: pdremove.o pdentity.o Date.o
	g++ -o $@ pdremove.o pdentity.o Date.o

pdentity.o: pdentity.h
	g++ -c pdentity.cpp -std=c++11

pdremove.o:  Date.h pdentity.h
	g++ -c pdremove.cpp -std=c++11

Date.o: Date.h
	g++ -c Date.cpp -std=c++11

pdadd: pdadd.o pdentity.o Date.o
	g++ -o $@ pdadd.o pdentity.o Date.o

pdadd.o: pdentity.h
	g++ -c pdadd.cpp -std=c++11

pdlist: pdlist.o pdentity.o Date.o
	g++ -o $@ pdlist.o pdentity.o Date.o

pdlist.o: pdlist.h
	g++ -c pdlist.cpp -std=c++11

pdshow: pdshow.o pdentity.o Date.o
	g++ -o $@ pdentity.o Date.o pdshow.o
	
pdshow.o: Date.h pdentity.h
	g++ -c pdshow.cpp -std=c++11

clean: 
	del -f *~ $(OBJS)

	