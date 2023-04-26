# InTrace
Intrusive runtime function call/dependency tracing lib, wip.

## Usage

Include `intrace.hpp`, add `InTraced;` at the beginning of functions to be traced, then the calling relations between those functions are all recorded.

Call `InTrace::print_trace()` to see what's going on.
