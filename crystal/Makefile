CFLAGS := 
LIBS := -lgc -levent

all: crystal.a libs.txt
libs.txt:
	echo -n $(LIBS) > $@

crystal.a: bridge.o crystal.o
	ar rcs $@ $^

bridge.o: bridge.c
	gcc -c -o $@ $^
crystal.o: source.cr
	crystal build --emit obj -o $(subst .o, , $@) $^
	rm $(subst .o, , $@)
	strip -N main $@
	objcopy $@ --redefine-sym crystal=_crystal
	 

.PHONY: clean
clean:
	rm -f crystal.o bridge.o crystal.a libs.txt

