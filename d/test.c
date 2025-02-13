#include <stdio.h>
extern void d();
void c() { printf("C\n"); }
int main() { 
    c();
    c();
    c();
    d(); 
    c();
    c();
    c();
    c();
    c();
    c();
}
