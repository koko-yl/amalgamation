CFLAGS := 
LIBS :=

all: rust.a libs.txt
libs.txt:
	echo -n $(LIBS) > $@

rust.a: source.rs
	rustc --crate-type=staticlib -o $@ $^


.PHONY: clean
clean:
	rm -f rust.a libs.txt
