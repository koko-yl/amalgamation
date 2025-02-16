RUBY_PATH := $(wildcard /usr/include/ruby-3*)
CFLAGS := -I$(RUBY_PATH) -I$(RUBY_PATH)/x86_64-linux
LIBS := -lruby

all: ruby.o libs.txt
	rm ruby.h 
libs.txt:
	echo -n $(LIBS) > $@

ruby.o: bridge.c ruby.h
	gcc $(CFLAGS) -D_HAS_H -c -o $@ bridge.c
ruby.h: source.rb
	xxd -i $^ > $@


.PHONY: clean
clean:
	rm -f libs.txt ruby.o ruby.h