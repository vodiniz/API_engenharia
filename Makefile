all : bin/unitTests bin/functional_tests

# ----------------------------------------------------------

bin/unitTests: bin/main.o bin/testSystem.o bin/System.o bin/testFlow.o bin/Flow.o bin/testModel.o bin/Model.o 
	@g++ -Wall -lm -o bin/unitTests bin/main.o bin/testSystem.o bin/System.o bin/testFlow.o bin/Flow.o bin/testModel.o bin/Model.o 

bin/main.o: test/unit/main.cpp
	@g++ -c -o bin/main.o test/unit/main.cpp -Wall

bin/testSystem.o: test/unit/testSystem.cpp
	@g++ -c -o bin/testSystem.o test/unit/testSystem.cpp -Wall

bin/System.o: src/System.cpp
	@g++ -c -o bin/System.o src/System.cpp -Wall

bin/testFlow.o: test/unit/testFlow.cpp 
	@g++ -c -o bin/testFlow.o test/unit/testFlow.cpp -Wall -lm

bin/Flow.o: src/Flow.cpp
	@g++ -c -o bin/Flow.o src/Flow.cpp -Wall


bin/testModel.o: test/unit/testModel.cpp
	@g++ -c -o bin/testModel.o test/unit/testModel.cpp -Wall -lm

bin/Model.o: src/Model.cpp
	@g++ -c -o bin/Model.o src/Model.cpp -Wall


# ----------------------------------------------------------

bin/functional_tests: bin/mainFunctional.o bin/functional_tests.o bin/System.o bin/Flow.o bin/Model.o
	@g++ -Wall -lm -o bin/functionalTests bin/mainFunctional.o bin/functional_tests.o bin/System.o bin/Flow.o bin/Model.o

bin/mainFunctional.o: test/func/mainFunctional.cpp
	@g++ -c -o bin/mainFunctional.o test/func/mainFunctional.cpp -Wall

bin/functional_tests.o: test/func/functional_tests.cpp
	@g++ -c -o bin/functional_tests.o test/func/functional_tests.cpp -Wall

