CXX ?= g++
AR = ar cr
RM = rm -f

LIB = digidrum.o Ymload.o Ym2149Ex.o YmMusic.o YmUserInterface.o

CFLAGS ?= -Wall

libym.a: $(LIB)
	$(AR) libym.a $(LIB)

digidrum.o: digidrum.cpp YmTypes.h
	$(CXX) $(CXXFLAGS) -c digidrum.cpp

Ym2149Ex.o: Ym2149Ex.cpp Ym2149Ex.h YmTypes.h
	$(CXX) $(CXXFLAGS) -c Ym2149Ex.cpp

Ymload.o: Ymload.cpp YmMusic.h lzh/lzh.h
	$(CXX) $(CXXFLAGS) -c Ymload.cpp

YmMusic.o: YmMusic.cpp YmMusic.h
	$(CXX) $(CXXFLAGS) -c YmMusic.cpp

YmUserInterface.o: YmUserInterface.cpp StSoundLibrary.h YmMusic.h
	$(CXX) $(CXXFLAGS) -c YmUserInterface.cpp

clean:
	$(RM) *~ *.o *.a

dist:
