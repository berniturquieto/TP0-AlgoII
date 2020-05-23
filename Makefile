CXXARGS  = -g -Wall
CXXFLAGS = -I. $(CXXARGS)

all: function_image.exe
	
function_image.exe: main.cpp image.cpp complejo.cpp main.h image.h complejo.h
	$(CXX) $(CXXFLAGS) -o function_image.exe complejo.cpp image.cpp main.cpp

clean:
	$(RM) -vf *.o *.exe *.t *.out *.err