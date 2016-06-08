struct cell;
//@ predicate cellp(struct cell* c, option<int> x);

int alloc(struct cell** c_out);
//@ requires *c_out |-> ?x;
//@ ensures result == 0 ? *c_out |-> x : (*c_out |-> ?c &*& cellp(c, none));

int full(struct cell* c);
//@ requires cellp(c, ?x);
//@ ensures (x != none ? result == 1 : result == 0) &*& cellp(c, x);

int push(struct cell* c, int x);
//@ requires cellp(c, none);
//@ ensures result == 1 ? cellp(c, some(x)) : cellp(c, none);

int pop(struct cell* c);
//@ requires cellp(c, some(?v));
//@ ensures cellp(c, none) &*& result == v;
