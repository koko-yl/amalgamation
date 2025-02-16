CFLAGS := 
LIBS := 

all: llvm.o libs.txt
libs.txt:
	echo -n $(LIBS) > $@

llvm.o: source.ll
	clang -c -o $@ $^


.PHONY: clean
clean:
	rm -f llvm.o libs.txt