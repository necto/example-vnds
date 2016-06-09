#include <klee/klee.h>

struct cell {}* stub;

int allocate_successful;

int alloc(struct cell** c_out)
{
  klee_trace_ret();
  klee_trace_param_ptr(c_out, sizeof (struct cell*), "c_out");
  klee_make_symbolic(&stub, sizeof (struct cell *),
                     "allocated_cell_do_not_dereference");
  allocate_successful = klee_int("cell_allocate_successfull");
  if (allocate_successful) {
    *c_out = stub;
    return 1;
  }
  return 0;
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
  //Attention here: omiting these directives
  // will cause validator to miss this bug.
  klee_trace_ret();
  klee_trace_param_i32((uint32_t)c, "c");
  klee_trace_param_i32(x, "x");
  return 1;
}

int pop(struct cell* c)
{
  klee_trace_ret();
  klee_trace_param_i32((uint32_t)c, "c");
  return klee_int("pop_val");
}
