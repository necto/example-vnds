
verify:
	clang -DKLEE_VERIFICATION summator.c cell.model.c invariants.model.c net.model.c -I "$(KLEE_INCLUDE)" -c -g -emit-llvm
	llvm-link summator.bc cell.model.bc invariants.model.bc net.model.bc -o veri.bc
	klee --libc=uclibc --posix-runtime veri.bc

validate:
	mkdir -p v
	ln -fTs ../vnds/validator/ validator
	corebuild -lib dynlink -I validator cell_spec.cmo -no-hygiene
	cp _build/cell_spec.cmo ./
	cd validator && make validator.byte
	./validator/test_all.sh ./klee-out-0/ v . cell_spec.cmo

clean:
	rm -rf _build *.bc klee-* v validator cell_spec.cmo

