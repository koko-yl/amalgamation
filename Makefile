PATHS := $(dir $(wildcard */Makefile)) 
_ := $(shell python3 helper.py targets > targets.txt)
main: main.o $(shell python3 helper.py objects)
	gcc -o $@ $^ $(shell python3 helper.py libs)
main.o: main.c
	gcc -c -o $@ $^

-include targets.txt
clean:
	rm -f $(shell python3 helper.py clean) targets.txt main main.o $(wildcard */*.o)
clean_temps:
	rm -rf $(wildcard */compile_commands.json)