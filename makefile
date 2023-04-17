vector:
	g++ -o programa mainVector.cpp alternative.cpp generator.cpp header.h && ./programa
list:
	g++ -o programa mainList.cpp alternative.cpp generator.cpp header.h && ./programa
deque:
	g++ -o programa mainDeque.cpp alternative.cpp generator.cpp header.h && ./programa
clean:
	rm *.txt *.exe
