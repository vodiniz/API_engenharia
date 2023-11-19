all: bin/functional_test


bin/functional_test: bin/mainFunctional.o bin/functional_tests.o bin/Flow.o bin/System.o bin/Model.o
	@g++ -o bin/functionalTests bin/mainFunctional.o bin/functional_tests.o bin/System.o bin/Flow.o bin/Model.o -Wall -lm -g




# ---------------------------------------------------------------
bin/Flow.o: src/FlowImpl.cpp src/FlowImpl.hpp
	@g++ -c -o bin/Flow.o src/FlowImpl.cpp -Wall -g

bin/System.o: src/SystemImpl.cpp src/SystemImpl.hpp
	@g++ -c -o bin/System.o src/SystemImpl.cpp -Wall -g

bin/Model.o: src/ModelImpl.cpp src/ModelImpl.hpp
	@g++ -c -o bin/Model.o src/ModelImpl.cpp -Wall -g

# ---------------------------------------------------------------

bin/functional_tests.o: test/func/functional_tests.cpp test/func/functional_tests.hpp
	@g++ -c -o bin/functional_tests.o test/func/functional_tests.cpp -Wall -lm -g

bin/mainFunctional.o: test/func/mainFunctional.cpp
	@g++ -c -o bin/mainFunctional.o test/func/mainFunctional.cpp -Wall -g


# all : bin/functional_tests 

# # ----------------------------------------------------------

# # bin/unitTests: bin/main.o bin/testSystem.o bin/SystemImpl.o bin/testFlow.o bin/FlowImpl.o bin/testModel.o bin/ModelImpl.o 
# # 	@g++ -Wall -lm -o bin/unitTests bin/main.o bin/testSystem.o bin/SystemImpl.o bin/testFlow.o bin/FlowImpl.o bin/testModel.o bin/ModelImpl.o 

# bin/main.o: test/unit/main.cpp
# 	@g++ -c -g -o bin/main.o test/unit/main.cpp -Wall

# bin/testSystem.o: test/unit/testSystem.cpp
# 	@g++ -c -g -o bin/testSystem.o test/unit/testSystem.cpp -Wall


# bin/SystemImpl.o: src/SystemImpl.cpp
# 	@g++ -c -g -o bin/SystemImpl.o src/SystemImpl.cpp -Wall

# bin/testFlow.o: test/unit/testFlow.cpp 
# 	@g++ -c -g -o bin/testFlow.o test/unit/testFlow.cpp -Wall -lm

# bin/FlowImpl.o: src/FlowImpl.cpp
# 	@g++ -c -g -o bin/FlowImpl.o src/FlowImpl.cpp -Wall


# bin/testModel.o: test/unit/testModel.cpp
# 	@g++ -c -g -o bin/testModel.o test/unit/testModel.cpp -Wall -lm

# bin/ModelImpl.o: src/ModelImpl.cpp src/ModelImpl.hpp
# 	@g++ -c -g -o bin/ModelImpl.o src/ModelImpl.cpp -Wall


# # ----------------------------------------------------------

# bin/functional_tests: bin/mainFunctional.o bin/functional_tests.o bin/SystemImpl.o bin/FlowImpl.o bin/ModelImpl.o
# 	@g++ -Wall -lm -g -o bin/functionalTests bin/mainFunctional.o bin/functional_tests.o bin/SystemImpl.o bin/FlowImpl.o bin/ModelImpl.o

# bin/mainFunctional.o: test/func/mainFunctional.cpp
# 	@g++ -c -g -o bin/mainFunctional.o test/func/mainFunctional.cpp -Wall

# bin/functional_tests.o: test/func/functional_tests.cpp
# 	@g++ -c -g -o bin/functional_tests.o test/func/functional_tests.cpp -Wall

