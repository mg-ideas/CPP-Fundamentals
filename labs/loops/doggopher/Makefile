CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17

PROGRAM = doggopher.exe

SOURCEFILES = $(wildcard src/*.cpp)
TESTFILES = $(wildcard tests/*.cpp)


all: build doctest clean

build:
	$(CXX) $(CXXFLAGS) $(SOURCEFILES)
	$(CXX) -o $(PROGRAM) *.o

run: build
	./$(PROGRAM)

doctest:
	$(CXX) $(TESTFILES) src/doggopher.cpp -o test_doggopher.exe
	./test_doggopher.exe
	@echo "All tests executed successfully!"


clean:
	find . -name "*.o" -delete
	find . -name "*.dSYM" -type d -exec rm -rf {} + 2>/dev/null || true
	find . -name "*.exe" -delete
	find . -name "*.out" -delete
	find . -name "*.pch" -delete
	
	