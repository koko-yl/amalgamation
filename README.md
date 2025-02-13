# I was bored: Part 2 
This project builds a single executable out of **19** different languages:   
- C
- Crystal
- C++
- D
- Go
- Java
- Javascript
- Kotlin
- LLVM IR
- Nim
- Lua
- Perl
- Python
- Ruby
- Rust
- Swift
- Typescript
- V
- Zig  
The program (should) print `Hi from $LANG!`, in order
## Building
Besides language dependencies this project requires `xxd` for embedding code. Otherwise you should (???) be able to simply run `make`. If you're on Windows, Talos guide you
## Bugs
There are probably a lot of bugs with this but the main one I've noticed is piping the output of this to another command messes up the output; Crystal prints first and D prints 4 separate times for some reason (caused by `fork`, see below).
## Goals
- Add more (duh)
- Remove `fork()` call from js/ts/java/kt (Can seemingly only create one instance of jvm/node runtime)
- Make js/ts faster

