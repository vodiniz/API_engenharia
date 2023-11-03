all : unitTests #testSystem testFlow


unitTests: main.o testSystem.o System.o testFlow.o Flow.o testModel.o Model.o 
	@g++ -Wall -lm -o unitTests main.o testSystem.o System.o testFlow.o Flow.o testModel.o Model.o 

# testSystem: testSystem.o System.o
# 	@g++ -o testSystem System.o testSystem.o -Wall -lm

main.o: test/unit/main.cpp
	@g++ -c test/unit/main.cpp -Wall

testSystem.o: test/unit/testSystem.cpp
	@g++ -c test/unit/testSystem.cpp -Wall

System.o: src/System.cpp
	@g++ -c src/System.cpp -Wall



# testFlow: testFlow.o Flow.o System.o
# 	@g++ -o testFlow Flow.o testFlow.o System.o -Wall -lm

testFlow.o: test/unit/testFlow.cpp 
	@g++ -c test/unit/testFlow.cpp -Wall -lm

Flow.o: src/Flow.cpp
	@g++ -c src/Flow.cpp -Wall


testModel.o: test/unit/testModel.cpp
	@g++ -c test/unit/testModel.cpp -Wall -lm

Model.o: src/Model.cpp
	@g++ -c src/Model.cpp -Wall
