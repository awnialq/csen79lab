CXX = g++
CXXFLAGS = -std=c++20

HEADERS = bag_bst.h bintree.h

all: bagexam bagtest

bagexam: bagexam.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o bagexam bagexam.cpp

bagtest: bagtest.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o bagtest bagtest.cpp

clean:
	rm -f bagexam bagtest

.PHONY: all clean
