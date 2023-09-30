bin/TestListArray: TestListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/TestListArray TestListArray.cpp ListArray.h

bin/testnode: TestNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/TestNode TestNode.cpp Node.h


clean:
	rm -r *.o *gch bin
