bin/TestListArray: TestListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/TestListArray TestListArray.cpp ListArray.h

bin/testnode: TestNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/TestNode TestNode.cpp Node.h

bin/testlinked: testListLinked.cpp ListLinked.h List.h Node.h
	mkdir -p bin
	g++ -o bin/testlinked testListLinked.cpp ListLinked.h Node.h
clean:
	rm -r *.o *gch bin
