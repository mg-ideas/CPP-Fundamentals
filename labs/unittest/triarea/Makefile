CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17

PROGRAM = triangle_area.exe

# list .cpp files separated by space
SRC = $(wildcard src/*.cpp)
TEST_FILES = $(wildcard tests/*.cpp)

all: build doctest

build:
	$(CXX) $(CXXFLAGS) $(SRC)
	$(CXX) -o $(PROGRAM) *.o

run:
	./$(PROGRAM)
	
doctest: clean
	$(CXX) -std=c++17 $(TEST_FILES) src/triarea.cpp -o doctest_runner.exe
	./doctest_runner.exe
	
clean:
	find . -name "*.o" -delete
	find . -name "*.dSYM" -type d -exec rm -rf {} + 2>/dev/null || true
	find . -name "*.exe" -delete
	find . -name "*.out" -delete
	find . -name "*.pch" -delete
