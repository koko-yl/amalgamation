CFLAGS := 
LIBS :=

all: nim.o libs.txt
libs.txt:
	echo -n $(LIBS) > $@

nim.o: source.nim
	rm -rf _$@
	nim c --hints:off --nimcache:_$@ --noMain --noLinking $^
	ld -r _$@/*.o -o $@
	rm -rf _$@

.PHONY: clean
clean:
	rm -f nim.o libs.txt _nim.o
