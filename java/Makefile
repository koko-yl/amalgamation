CFLAGS := -I/usr/lib/jvm/default/include/ -I/usr/lib/jvm/default/include/linux
LIBS := -Wl,-rpath=/usr/lib/jvm/default/lib/server/ -L/usr/lib/jvm/default/lib/server/ -ljvm 

all: java.o libs.txt
	rm source.class java.h
libs.txt:
	echo -n $(LIBS) > $@

java.o: bridge.c java.h
	gcc $(CFLAGS) -D_HAS_H -c -o $@ bridge.c
java.h: source.class
	xxd -i $^ > $@
source.class: source.java
	javac $^

.PHONY: clean
clean:
	rm -f source.class libs.txt java.o java.h