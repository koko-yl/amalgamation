CFLAGS := 
LIBS := -lstdc++

all: cpp.o libs.txt
libs.txt:
	echo -n $(LIBS) > $@

cpp.o: source.cpp
	g++ -c -o $@ $^

.PHONY: clean
clean:
	rm -f cpp.o libs.txt