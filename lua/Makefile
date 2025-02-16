CFLAGS :=
LIBS := -llua

all: lua.o libs.txt
	rm lua.h 
libs.txt:
	echo -n $(LIBS) > $@

lua.o: bridge.c lua.h
	gcc $(CFLAGS) -D_HAS_H -c -o $@ bridge.c
lua.h: source.lua
	xxd -i $^ > $@


.PHONY: clean
clean:
	rm -f libs.txt lua.o lua.h