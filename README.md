# Model over approximaiton example
This example demonstrates a possible deficiency in a model. This model leaves out too much semantics of the specification, so it won't be able witness that the cell is not 'full' after 'pop' is performed.

The assertion will fail during verification, while
it must not according to the contract.
this is due to overapproximation of the model in use.
it does not remember the latest 'pop' call, and permits
'full' to return true after it.

The user will see the false positive. Currently there is
not detection built in the framework for such cases, although,
it should be possible to automate.
