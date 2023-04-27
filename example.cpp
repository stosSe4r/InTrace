#include<iostream>
#include "intrace.hpp"

void f();
void g();

void g() {
    InTraced;
    std::cout << InTrace::get_trace();
    //f();
}

void f() {
    InTraced;
    g();
}


int main() {
    InTraced;
    f();
    std::cout << InTrace::get_trace();
}