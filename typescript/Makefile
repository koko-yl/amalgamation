CXXFLAGS := -I/usr/include/node -std=c++20 
LIBS := -lnode -lstdc++

all: typescript.o libs.txt
	rm typescript.h 
	rm source.js
libs.txt:
	echo -n $(LIBS) > $@

typescript.o: bridge.cpp typescript.h
	g++ $(CXXFLAGS) -D_HAS_H -c -o $@ bridge.cpp
typescript.h: source.js
	xxd -n source_ts -i $^ > $@
source.js: source.ts
	tsc --outFile $@ $^

.PHONY: clean
clean:
	rm -f libs.txt typescript.o typescript.h source.js