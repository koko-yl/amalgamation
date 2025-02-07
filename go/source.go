package main
import "C"
import "fmt"
//export _go
func _go() { // go is a keyword
	fmt.Println("Hi from Go!")
}
func main() {}
