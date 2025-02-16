CFLAGS := -I/usr/lib/jvm/default/include/ -I/usr/lib/jvm/default/include/linux
LIBS := -Wl,-rpath=/usr/lib/jvm/default/lib/server/ -L/usr/lib/jvm/default/lib/server/ -ljvm 

all: kotlin.o libs.txt
	rm -f source.class kotlin.h
	rm -rf META-INF
libs.txt:
	echo -n $(LIBS) > $@

kotlin.o: bridge.c kotlin.h
	gcc $(CFLAGS) -D_HAS_H -c -o $@ bridge.c
kotlin.h: SourceKt.class
	xxd -n sourcekt_class -i $^ > $@
SourceKt.class: source.kt
	kotlinc $^

.PHONY: clean
clean:
	rm -f source.class libs.txt kotlin.o kotlin.h