RM = rm -f
CXX ?= $(CXX)

LZH = stsoundlib/lzh
STLIB = stsoundlib

INCLUDE = -L$(LZH) -L$(STLIB)

INSTALL = /usr/bin/install -c

all: libs ymplayer ym2wav

libs:
	@for subdir in $(STLIB) $(LZH); do \
	(cd $$subdir && make) || exit 1; \
	done

ymplayer: ymplayer.o sound.o ui.o
	$(CXX) $(CXXFLAGS) -o ymplayer $(INCLUDE) ymplayer.o sound.o ui.o -lym -llzh $(LDFLAGS) -lncurses

ym2wav: ym2wav.o
	$(CXX) $(CXXFLAGS) -o ym2wav $(INCLUDE) ym2wav.o -lym -llzh	

ymplayer.o: ymplayer.cpp $(STLIB)/StSoundLibrary.h ui.h sound.h
	$(CXX) $(CXXFLAGS) $(INLCUDE) -c ymplayer.cpp

ym2wav.o: ym2wav.cpp $(STLIB)/StSoundLibrary.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c ym2wav.cpp

sound.o: sound.cpp sound.h
	$(CXX) $(CXXFLAGS) -c sound.cpp

ui.o: ui.c ui.h $(STLIB)/StSoundLibrary.h
	$(CXX) $(CXXFLAGS) -c ui.c

install: all
	$(INSTALL) ymplayer /usr/bin
	$(INSTALL) ym2wav /usr/bin

clean:

	@for subdir in $(LZH) $(STLIB); do \
	(cd $$subdir && make $@) || exit 1; \
	done

	$(RM)  *.o ymplayer ym2wav *~
	
