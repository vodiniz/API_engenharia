all : unitTests functional_tests

# ----------------------------------------------------------

unitTests: main.o testSystem.o System.o testFlow.o Flow.o testModel.o Model.o 
	@g++ -Wall -lm -o unitTests main.o testSystem.o System.o testFlow.o Flow.o testModel.o Model.o 

main.o: test/unit/main.cpp
	@g++ -c test/unit/main.cpp -Wall

testSystem.o: test/unit/testSystem.cpp
	@g++ -c test/unit/testSystem.cpp -Wall

System.o: src/System.cpp
	@g++ -c src/System.cpp -Wall

testFlow.o: test/unit/testFlow.cpp 
	@g++ -c test/unit/testFlow.cpp -Wall -lm

Flow.o: src/Flow.cpp
	@g++ -c src/Flow.cpp -Wall


testModel.o: test/unit/testModel.cpp
	@g++ -c test/unit/testModel.cpp -Wall -lm

Model.o: src/Model.cpp
	@g++ -c src/Model.cpp -Wall


# ----------------------------------------------------------

functional_tests: mainFunctional.o functional_tests.o System.o Flow.o Model.o
	@g++ -Wall -lm -o functionalTests mainFunctional.o functional_tests.o System.o Flow.o Model.o

mainFunctional.o: test/func/mainFunctional.cpp
	@g++ -c test/func/mainFunctional.cpp -Wall

functional_tests.o: test/func/functional_tests.cpp
	@g++ -c test/func/functional_tests.cpp -Wall

