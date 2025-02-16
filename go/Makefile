CFLAGS := 
LIBS :=

all: go.a libs.txt
libs.txt:
	echo -n $(LIBS) > $@

go.a: source.go
	go build -buildmode=c-archive -o $@ $^
	rm go.h
	objcopy $@ --redefine-sym _go=go

.PHONY: clean
clean:
	rm -f go.a libs.txt
