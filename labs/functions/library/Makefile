# compiler name
CXX = g++
# c++ compiler flags
# -g : adds debugging information to the executable file
# -Wall : turns on most, but not  all, compiler warnings
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = library.exe

# list all the cpp source files here
CPPFILES = $(wildcard src/*.cpp) $(wildcard tests/*.cpp)

.PHONY: all build run asserttest clean

# make build rule/default rule that'll be run when we run "make"
all: build run clean

# first compile each file to object file
# then make a single binary program
build:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

run: build
	./$(PROGRAM)

asserttest: build
	./$(PROGRAM) test
	@echo "All tests executed successfully!"
	
# make clean rule
# delete object and binary files
clean:
	find . -name "*.o" -delete
	find . -name "*.dSYM" -type d -exec rm -rf {} + 2>/dev/null || true
	find . -name "*.exe" -delete
	find . -name "*.out" -delete
	