#include <klee/klee.h>

struct cell {}* stub;
//@ predicate cellp(struct cell* c, option<int> x);

void alloc(struct cell** c_out)
{
  klee_trace_ret();
  klee_trace_param_ptr(c_out, sizeof (struct cell*), "c_out");
  klee_make_symbolic(&stub, sizeof (struct cell *),
                     "allocated_cell_do_not_dereference");
  *c_out = stub;
  return;//may also enforce initialization,
  //but it will be caught in validator anyway
}

int full(struct cell* c)
{
  klee_trace_ret();
  klee_trace_param_i32((uint32_t)c, "c");
  if (klee_int("full")) return 1;
  return 0;
}

int push(struct cell* c, int x)
{
  klee_trace_ret();
  klee_trace_param_i32((uint32_t)c, "c");
  klee_trace_param_i32(x, "x");
  if (klee_int("push_success")) return 1;
  return 0;
}

int pop(struct cell* c)
{
  klee_trace_ret();
  klee_trace_param_i32((uint32_t)c, "c");
  return klee_int("pop_val");
}
