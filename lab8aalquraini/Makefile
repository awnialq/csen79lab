# CSEN 79
# Lab 8 Makefile

STD=-std=c++20
OPT=-g
CXXFLAGS=${STD} ${OPT}
CFLAGS=${OPT}
TARFLAGS=--no-mac-metadata

%: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $<

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

SRCS=deque_test.cpp
OBJS=$(SRCS:.cpp=.o)
ALL=deque

all: $(ALL)

deque:	$(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

clean:
	/bin/rm -f $(OBJS) $(ALL)
	/bin/rm -rf $(ALL:=.dSYM)

depend: $(SRCS)
	TMP=`mktemp -p .`; export TMP; \
	sed -e '/^# DEPENDENTS/,$$d' Makefile > $$TMP; \
	echo '# DEPENDENTS' >> $$TMP; \
	$(CXX) -MM $+ >> $$TMP; \
	/bin/mv -f $$TMP Makefile


# DEPENDENTS
deque_test.o: deque_test.cpp deque_iterator.h deque_iter.impl deque.h \
  deque.impl
