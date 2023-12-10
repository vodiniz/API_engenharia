all: bin/unit_tests bin/libSimulation.so bin/functionalTests

# --------------------------------------------------

bin/libSimulation.so:
	@g++ -fPIC -shared -o bin/libSimulation.so src/*.cpp -Wall -g

# --------------------------------------------------

bin/functionalTests: bin/libSimulation.so
	@g++ test/func/*.cpp bin/libSimulation.so -o bin/functionalTests -Wall -g

# --------------------------------------------------

bin/unit_tests: bin/libSimulation.so
	@g++ test/unit/*.cpp bin/libSimulation.so -o bin/unit_tests -Wall -g

# --------------------------------------------------

clean:
	@rm bin/*
