CXXFLAGS := -I/usr/include/node -std=c++20 
LIBS := -lnode -lstdc++

all: javascript.o libs.txt
	rm javascript.h 
libs.txt:
	echo -n $(LIBS) > $@

javascript.o: bridge.cpp javascript.h
	g++ $(CXXFLAGS) -D_HAS_H -c -o $@ bridge.cpp
javascript.h: source.js
	xxd -i $^ > $@


.PHONY: clean
clean:
	rm -f libs.txt javascript.o javascript.h