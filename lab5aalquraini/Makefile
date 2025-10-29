#Lab 5 Makefile

STD=-std=c++20
OPT=-g
CXXFLAGS=${STD} ${OPT}
CFLAGS=${OPT}

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

ALL=test_string

all: $(ALL)

test_string:	mystring.o test_string.o
	$(CXX) -o $@ $(CXXFLAGS) $+

clean:
	/bin/rm -f mystring.o test_string.o $(ALL)
	/bin/rm -rf $(ALL:=.dSYM)


mystring.o: mystring.cpp mystring.h
test_string.o: test_string.cpp mystring.h