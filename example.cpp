#include<iostream>
#include "intrace.hpp"

void f();
void g();

void g() {
    InTraced;
    std::cout << InTrace::print_trace();
    //f();
}

void f() {
    InTraced;
    g();
}


int main() {
    InTraced;
    f();
    std::cout << InTrace::print_trace();
}