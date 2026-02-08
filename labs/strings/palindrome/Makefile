# compiler name
CXX = g++
# g++ compiler flags
# -g: adds debugging information to the executable file
# -Wall: turns on most, but not  all, compiler warnings
# -std=c++17: uses c++17 standard
# put all the required flags separated by space
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = #FIXME

# list .cpp files separated by space
CPPFILES = #FIXME

# make all rule/default rule that'll be run when we run "make"
# first compile each file to object file
# then make a single binary/executable program
all: build clean

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

# FIXME
# add a rule to run the program
