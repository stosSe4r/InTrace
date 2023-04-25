#ifndef InTrace_H
#define InTrace_H

#include<deque>
#include<string>
#include<sstream>
#include<chrono>
//#include<source_location>
#include<iomanip>
#include<ctime>


namespace InTrace {
struct _it_func_call {
    std::string fn; // function name
    std::chrono::time_point<std::chrono::system_clock> prolog, epilog; // the time point entering and exiting the function
    // epilog might be useless, to be removed
    // note that instead of steady_clock, system_clock is used; problems might exist

    _it_func_call(std::string func_name, std::chrono::time_point<std::chrono::system_clock> entr_time) {
        fn = func_name;
        prolog = entr_time;
    }
};

// TODO: support multi-thread environment
struct {
    bool display_timestamp = true;
    std::deque<_it_func_call> cs; // call relation, should be a stack
} _InTrace_data;

class _InTracer {

public:
    _InTracer(std::string func_name) {
        auto entr_time = std::chrono::system_clock::now();
        _InTrace_data.cs.push_back(_it_func_call(func_name, entr_time));
    }
    ~_InTracer() {
        _InTrace_data.cs.pop_back();
    }
};


// TODO: add configuration for not displaying timestamp
std::string print_trace() {
    std::stringstream result;
    result << "Trace from " << _InTrace_data.cs.back().fn << "\n";
    std::string nest_level = "";
    for(auto trace : _InTrace_data.cs) {
        auto fn_time = std::chrono::system_clock::to_time_t(trace.prolog);
        if (_InTrace_data.display_timestamp)
            result << "[" << std::put_time(std::localtime(&fn_time), "%Y/%m/%d %T") << "] " << nest_level << trace.fn << '\n';
        else
            result << nest_level << trace.fn << '\n';
        if (nest_level.length() < 10)
            nest_level += "-";
    }
    result << "\n";
    return result.str();
}

}

// given source_location not available in clang14, have to use __FUNCTION__ here
// #define InTraced auto _in_tracer = InTrace::_InTracer(std::source_location::current().function_name());
#define InTraced auto _in_tracer = InTrace::_InTracer(__FUNCTION__);

#endif