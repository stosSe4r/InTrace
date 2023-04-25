#ifndef InTrace_H
#define InTrace_H

#include<stack>
#include<string>
#include<chrono>

struct _it_func_call {
    std::string func; // function name
    std::chrono::time_point<std::chrono::steady_clock> prolog, epilog; // the time point entering and exiting the function
};

struct {
    std::stack<_it_func_call> cs; // call stack
} _InTrace_data;

#endif