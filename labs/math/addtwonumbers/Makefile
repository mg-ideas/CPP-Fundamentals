CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17

PROGRAM = addtwo.exe

# list .cpp files separated by space
SRC = $(wildcard src/*.cpp)
TEST_FILES = $(wildcard tests/*.cpp)
all: build run

build:
	$(CXX) $(CXXFLAGS) $(SRC)
	$(CXX) -o $(PROGRAM) *.o

run: build
	./$(PROGRAM)
	
# make clean rule
# delete object and binary files
clean:
	find . -name "*.o" -delete
	find . -name "*.dSYM" -type d -exec rm -rf {} + 2>/dev/null || true
	

assert_test: build
	./$(PROGRAM) test
	@echo "Assert tests passed!"

doctest:
	$(CXX) -std=c++17 -Iinclude $(TEST_FILES) src/addtwo.cpp -o doctest_runner.exe
	./doctest_runner.exe
	