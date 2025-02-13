CFLAGS := 
LIBS := -lgc

all: v.o libs.txt
libs.txt:
	echo -n $(LIBS) > $@

v.o: source.v
	v -o $@ $^ -c 

.PHONY: clean
clean:
	rm -f v.o libs.txt
