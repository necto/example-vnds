#ifndef INVARIANTS_H_INCLUDED
#define INVARIANTS_H_INCLUDED

#include "cell.h"

void invariant_consume(struct cell** cpp);
//@ requires *cpp |-> ?cp &*& cellp(cp, _);
//@ ensures true;

void invariant_produce(struct cell** cpp);
//@ requires *cpp |-> _;
//@ ensures *cpp |-> ?cp &*& cellp(cp, _);

#endif//INVARIANTS_H_INCLUDED
