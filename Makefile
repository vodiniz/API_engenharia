all : testSystem testFlow




testSystem: testSystem.o System.o
	@g++ -o testSystem System.o testSystem.o -Wall -lm

testSystem.o: test/unit/testSystem.cpp
	@g++ -c test/unit/testSystem.cpp -Wall

System.o: src/System.cpp
	@g++ -c src/System.cpp -Wall



testFlow: testFlow.o Flow.o System.o
	@g++ -o testFlow Flow.o testFlow.o System.o -Wall -lm

testFlow.o: test/unit/testFlow.cpp 
	@g++ -c test/unit/testFlow.cpp -Wall -lm

Flow.o: src/Flow.cpp
	@g++ -c src/Flow.cpp -Wall

