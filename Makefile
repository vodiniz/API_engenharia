all: bin/unit_tests bin/libSimulation.so

# --------------------------------------------------

bin/libSimulation.so:
	@g++ -fPIC -shared -o bin/libSimulation.so src/*.cpp -Wall -g

# --------------------------------------------------

bin/functionalTests: bin/libSimulation.so
	@g++ test/func/*.cpp bin/libSimulation.so -o bin/functionalTests -Wall

# --------------------------------------------------

bin/unit_tests: bin/libSimulation.so
	@g++ test/unit/*.cpp bin/libSimulation.so -o bin/unit_tests -Wall

# --------------------------------------------------

clean:
	@rm bin/*
