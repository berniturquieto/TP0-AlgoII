CXXARGS  = -g -Wall
CXXFLAGS = -I. $(CXXARGS)

all: image_transformer
	
image_transformer: main.cpp image.cpp complejo.cpp pgm_reader.cpp main.h image.h complejo.h pgm_reader.h
	$(CXX) $(CXXFLAGS) -o ../image_transformer pgm_reader.cpp complejo.cpp image.cpp main.cpp

clean:
	$(RM) -vf *.o *.exe *.t *.out *.err