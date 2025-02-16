CFLAGS := 
LIBS := 

all: zig.a libs.txt
libs.txt:
	echo -n $(LIBS) > $@

zig.a: zig.o zps.o
	ar rcs $@ $^
zig.o: source.zig
	zig build-obj source.zig -fPIC --name $(subst .o,,$@)
	rm zig.o.o
zps.o:
	gcc -c -o $@ -xc - <<< 'void __zig_probe_stack() {}'

.PHONY: clean
clean:
	rm -f zig.a zps.o zig.o libs.txt
