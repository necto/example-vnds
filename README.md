## API misuse example

This example demonstrates the forbidden call sequence for the cell API. 

It first calls "pop" without guarantee that it is legit i.e. that the cell is not empty.

The validator will complain on the corresponding call trace.
