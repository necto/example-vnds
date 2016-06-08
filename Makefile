
verify:
	clang -DKLEE_VERIFICATION summator.c cell.model.c invariants.model.c net.model.c -I "$(KLEE_INCLUDE)" -c -g -emit-llvm
	llvm-link summator.bc cell.model.bc invariants.model.bc net.model.bc -o veri.bc
	klee --libc=uclibc --posix-runtime veri.bc

clean:
  rm -r *.bc klee-*

