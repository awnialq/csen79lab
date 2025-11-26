# Makefile for building two targets: bagtest and bagexam (C++ sources)

CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2 -g
LDLIBS =

SRCS_BAGTEST = bagtest.cpp
OBJS_BAGTEST = $(SRCS_BAGTEST:.cpp=.o)

SRCS_BAGEXAM = bagexam.cpp
OBJS_BAGEXAM = $(SRCS_BAGEXAM:.cpp=.o)

.PHONY: all clean bagtest bagexam

all: bagtest bagexam

bagtest: $(OBJS_BAGTEST)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

bagexam: $(OBJS_BAGEXAM)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o bagtest bagexam