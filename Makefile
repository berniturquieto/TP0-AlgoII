CXXARGS  = -g -Wall
CXXFLAGS = -I. $(CXXARGS)

all: cmdline.exe
	

cmdline.exe: main.cc cmdline.cc cmdline.h
	$(CXX) $(CXXFLAGS) -o cmdline.exe cmdline.cc main.cc

runtest.exe: runtest.cc
	$(CXX) $(CXXFLAGS) -o runtest.exe runtest.cc

test tests: cmdline.exe runtest.exe
	runtest.exe cmdline.tests

clean:
	$(RM) -vf *.o *.exe *.t *.out *.err
