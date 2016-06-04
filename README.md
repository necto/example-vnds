# Wrong arguments example

This version does not check the faulure
to allocate the cell, so it may pass an
uninitialized pointer to the function 'full', which
does not anticipate this.

The symbolic execution itself will not caught it,
because it does not use the cell pointer argument,
but the validator will notice the abscence of the
corresponding predicate.
