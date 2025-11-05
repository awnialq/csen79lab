# Sin-Yaw Wang <swang24@scu.edu>
TMPMAKE=tmpMake
CXX=c++
OPT=-g
STD=-std=c++20
CXXFLAGS=$(OPT) $(STD)

%.o:	%.cxx
	$(CXX) -c $(CXXFLAGS) $<

SRCS=main.cxx record.cxx recordops.cxx
OBJS=$(SRCS:.cxx=.o)
ALL=stl stldemo

all: $(ALL)

stl:	$(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

stldemo:	stldemo.cxx
	$(CXX) -o $@ $(CXXFLAGS) $+

clean:
	/bin/rm -f $(ALL) $(OBJS)
	/bin/rm -rf $(ALL:=.dSYM)

depend: $(SRCS) stldemo.cxx
	TMP=`mktemp -p .`; export TMP; \
	sed -e '/^# DEPENDENTS/,$$d' Makefile > $$TMP; \
	echo '# DEPENDENTS' >> $$TMP; \
	$(CXX) -MM $+ >> $$TMP; \
	/bin/mv -f $$TMP Makefile

# DEPENDENTS
main.o: main.cxx record.h
record.o: record.cxx record.h
recordops.o: recordops.cxx record.h
stldemo.o: stldemo.cxx
