CFLAGS := $(shell pkg-config --cflags python3)
LIBS := $(shell python3-config --ldflags --embed)

all: python.o libs.txt
	rm python.h 
libs.txt:
	echo -n $(LIBS) > $@

python.o: bridge.c python.h
	gcc $(CFLAGS) -D_HAS_H -c -o $@ bridge.c
python.h: source.py
	xxd -i $^ > $@


.PHONY: clean
clean:
	rm -f libs.txt python.o python.h