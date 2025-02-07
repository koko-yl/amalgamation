CFLAGS := 
LIBS := -lphobos2

all: d.o libs.txt
libs.txt:
	echo -n $(LIBS) > $@

d.o: source.d
	dmd -c -of=$@ $^


.PHONY: clean
clean:
	rm -f d.o libs.txt