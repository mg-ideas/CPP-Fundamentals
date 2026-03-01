# compiler name
CXX = g++
# c++ compiler flags
# -g: adds debugging information to the executable file
# - Wall turns on most, but not  all, compiler warnings
# -std=C++17 uses c++17 standard
# add all the required flags separated by space
CXXFLAGS = -c -g -Wall -std=c++17

# the build target executable file; .exe is not required
PROGRAM = simonsays.exe

# list .cpp files separated by space
CPPFILES = $(wildcard src/*.cpp)
TEST_FILES = $(wildcard tests/*.cpp)

all: build doctest clean
	@printf "All good!\n"

build:
	@$(CXX) $(CXXFLAGS) $(CPPFILES)
	@$(CXX) -o $(PROGRAM) *.o

run:
	@./$(PROGRAM)
	

doctest: clean
	$(CXX) -std=c++17 $(TEST_FILES) src/util.cpp -o doctest_runner.exe
	./doctest_runner.exe
	

clean:
	find . -name "*.o" -delete
	find . -name "*.dSYM" -type d -exec rm -rf {} + 2>/dev/null || true
	find . -name "*.exe" -delete
	find . -name "*.out" -delete
	find . -name "*.pch" -delete

