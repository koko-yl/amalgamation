CFLAGS := 
LIBS := 

all: swift.o libs.txt
libs.txt: tmp
	ldd tmp | python3 swift_libs.py > $@

swift.o: source.swift
	swiftc -c -o $@ -parse-as-library -emit-object $^
tmp:
	echo | swiftc -o $@ - 


.PHONY: clean
clean:
	rm -f swift.o libs.txt tmp