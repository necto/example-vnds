# App crash example
This example demonstrates a common mistake.
After 'recv' function called its result is implied
to be a valid pointer which it may be not.
Thanks to a detailed enought symbolic model,
the verifier will detect and report the possible
wrong memory access.
