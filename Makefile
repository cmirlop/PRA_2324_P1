bin/TestListArray: TestListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/TestListArray TestListArray.cpp ListArray.h 
clean:
	rm -r *.o *gch bin
