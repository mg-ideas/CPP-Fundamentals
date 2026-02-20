CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17

# target program name
PROGRAM = palindrome.exe

# list .cpp files separated by space
CPPFILES = $(wildcard src/*.cpp)

# make all rule/default rule that'll be run when we run "make"
# first compile each file to object file
# then make a single binary/executable program
all: build clean

build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

# make clean rule
clean:
	rm $(PROGRAM) || true
	find . -name "*.o" -delete
	find . -name "*.dSYM" -type d -exec rm -rf {} + 2>/dev/null || true
	find . -name "*.exe" -delete
	find . -name "*.out" -delete
	

# FIXME
# add a rule to run the program

doctest:
	$(CXX) -std=c++17 tests/test_palindrome.cpp src/palindrome.cpp -o doctest_runner.exe
	./doctest_runner.exe
