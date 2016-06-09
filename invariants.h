#include "cell.h"

void invariant_consume(struct cell** cpp);
//@ requires cellp(cp, _);
//@ ensures true;

void invariant_produce(struct cell** cpp);
//@ requires *cpp |-> _;
//@ ensures *cpp |-> ?cp &*& cellp(cp, _);
