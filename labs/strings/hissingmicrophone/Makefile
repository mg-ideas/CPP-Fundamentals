CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = hissing.exe

# list .cpp files separated by space
CPPFILES = $(wildcard src/*.cpp)
TEST_FILES = $(wildcard tests/*.cpp)

all: build doctest sampletest clean
	@printf "All good!\n"

# make build rule/default rule that'll be run when we run "make" or make build
# first compile each file to object file
# then make a single binary program
build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

run:
	./$(PROGRAM)
	
# make clean rule
# delete object and binary files
clean:
	find . -name "*.o" -delete
	find . -name "*.dSYM" -type d -exec rm -rf {} + 2>/dev/null || true
	find . -name "*.exe" -delete
	find . -name "*.out" -delete

# run the test cases
doctest:
	$(CXX) -std=c++17 $(TEST_FILES) src/util.cpp -o doctest_runner.exe
	./doctest_runner.exe

# test the kattis provided samples
sampletest:
	katis test
