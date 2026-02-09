CXX = g++
CXXFLAGS = -c -g -Wall -std=gnu++17

# the build target executable file; .exe is not required
PROGRAM = foxsays.exe

# list .cpp files separated by space
CPPFILES = $(wildcard src/*.cpp)
TEST_FILES = $(wildcard tests/*.cpp)

all: build doctest sampletest clean
	@printf "All good!\n"

build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

# make clean rule
# delete object and binary files
clean:
	find . -name "*.o" -delete
	find . -name "*.dSYM" -type d -exec rm -rf {} + 2>/dev/null || true
	find . -name "*.exe" -delete
	find . -name "*.out" -delete
	find . -name "*.pch" -delete

# run the test cases
doctest: clean
	$(CXX) -std=c++17 $(TEST_FILES) src/util.cpp -o doctest_runner.exe
	./doctest_runner.exe

# test the kattis provided samples
sampletest:
	kattis test