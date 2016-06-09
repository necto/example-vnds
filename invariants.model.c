#include <klee/klee.h>
#include "invariants.h"

void invariant_consume(struct cell** cpp)
//@ requires *cpp |-> ?cp &*& cellp(cp, _);
//@ ensures true;
{
  klee_trace_ret();
  klee_trace_param_ptr(cpp, sizeof(struct cell*), "cpp");
  //do nothing
}

void invariant_produce(struct cell** cpp)
//@ requires *cpp |-> _;
//@ ensures *cpp |-> ?cp &*& cellp(cp, _);
{
  klee_trace_ret();
  klee_trace_param_ptr(cpp, sizeof(struct cell*), "cpp");
  //do nothing
}
