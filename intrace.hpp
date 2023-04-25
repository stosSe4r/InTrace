#ifndef InTrace_H
#define InTrace_H

#include<deque>
#include<string>
#include<chrono>

struct _it_func_call {
    std::string fn; // function name
    std::chrono::time_point<std::chrono::steady_clock> prolog, epilog; // the time point entering and exiting the function
};

struct {
    std::deque<_it_func_call> cs; // call stack
} _InTrace_data;

class _InTracer {
    std::string fn;
public:
    _InTracer(std::string);
    ~_InTracer();
};

#endif