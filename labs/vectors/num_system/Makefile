CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = numberSystem.exe

# list .cpp files separated by space
SRC_FILES = $(wildcard src/*.cpp)
TEST_FILES = $(wildcard tests/*.cpp)

all: build doctest clean
	@echo "All done..."

build:
	$(CXX) $(CXXFLAGS) $(SRC_FILES)
	$(CXX) -o $(PROGRAM) *.o

doctest:
	$(CXX) -std=c++17 $(TEST_FILES) src/num_system.cpp -o doctest_runner.exe
	./doctest_runner.exe

clean:
	find . -name "*.o" -delete
	find . -name "*.dSYM" -type d -exec rm -rf {} + 2>/dev/null || true
	find . -name "*.exe" -delete
	find . -name "*.out" -delete
	find . -name "*.pch" -delete
