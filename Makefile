all: bin/functional_test bin/unit_test bin/lib_vensim

# ---------------------------------------------------------------
# ---------------------------------------------------------------


bin/lib_vensim: bin/Flow.o bin/System.o bin/Model.o
	@g++ -shared -o bin/lib_vensim.so bin/Flow.o bin/System.o bin/Model.o


# ---------------------------------------------------------------
# ---------------------------------------------------------------

bin/Flow.o: src/FlowImpl.cpp src/FlowImpl.hpp
	@g++ -c -fPIC -o bin/Flow.o src/FlowImpl.cpp -Wall -g

bin/System.o: src/SystemImpl.cpp src/SystemImpl.hpp
	@g++ -c -fPIC -o bin/System.o src/SystemImpl.cpp -Wall -g

bin/Model.o: src/ModelImpl.cpp src/ModelImpl.hpp
	@g++ -c -fPIC -o bin/Model.o src/ModelImpl.cpp -Wall -g 

# ---------------------------------------------------------------
# ---------------------------------------------------------------

bin/functional_test: bin/mainFunctional.o bin/functional_tests.o bin/lib_vensim
	@g++ -o bin/functionalTests bin/mainFunctional.o bin/functional_tests.o bin/lib_vensim.so -Wall -lm -g

bin/functional_tests.o: test/func/functional_tests.cpp test/func/functional_tests.hpp
	@g++ -c -o bin/functional_tests.o test/func/functional_tests.cpp -Wall -lm -g

bin/mainFunctional.o: test/func/mainFunctional.cpp
	@g++ -c -o bin/mainFunctional.o test/func/mainFunctional.cpp -Wall -g


# ---------------------------------------------------------------
# ---------------------------------------------------------------
bin/unit_test: bin/unit_main.o bin/unit_System.o bin/unit_Flow.o bin/unit_Model.o bin/lib_vensim
	@g++ -o bin/unit_test bin/unit_main.o bin/unit_System.o bin/unit_Flow.o bin/unit_Model.o bin/lib_vensim.so -Wall

bin/unit_main.o: test/unit/main.cpp
	@g++ -c -o bin/unit_main.o test/unit/main.cpp -Wall 

bin/unit_System.o: test/unit/unit_System.cpp test/unit/unit_System.hpp
	@g++ -c -o bin/unit_System.o test/unit/unit_System.cpp -Wall

bin/unit_Flow.o: test/unit/unit_Flow.cpp test/unit/unit_Flow.hpp
	@g++ -c -o bin/unit_Flow.o test/unit/unit_Flow.cpp -Wall

bin/unit_Model.o: test/unit/unit_Model.cpp test/unit/unit_Model.hpp
	@g++ -c -o bin/unit_Model.o test/unit/unit_Model.cpp -Wall

# ---------------------------------------------------------------
# ---------------------------------------------------------------

clean:
	@rm bin/*
