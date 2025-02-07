CFLAGS := $(shell perl -MExtUtils::Embed -e ccopts) 
LIBS := $(shell perl -MExtUtils::Embed -e ldopts) 

all: perl.o libs.txt
	rm perl.h 
libs.txt:
	echo -n $(LIBS) > $@

perl.o: bridge.c perl.h
	gcc $(CFLAGS) -D_HAS_H -c -o $@ bridge.c
perl.h: source.pl
	xxd -i $^ > $@


.PHONY: clean
clean:
	rm -f libs.txt perl.o perl.h