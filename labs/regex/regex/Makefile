CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = ssn.exe

# list .cpp files separated by space
FILES = $(wildcard src/*.cpp)
TEST_FILES = $(wildcard tests/*.cpp)

all: build doctest clean
	@printf "All good!\n"

# make build rule/default rule that'll be run when we run "make" or make build
# first compile each file to object file
# then make a single binary program
build:
	$(CXX) $(CXXFLAGS) $(FILES)
	$(CXX) -o $(PROGRAM) *.o

# FIXME - add a rule to run the program
	
# make clean rule
# delete object and binary files
clean:
	find . -name "*.o" -delete
	find . -name "*.dSYM" -type d -exec rm -rf {} + 2>/dev/null || true
	find . -name "*.exe" -delete
	find . -name "*.out" -delete

# run the test cases
doctest:
	@echo "FIXME"

