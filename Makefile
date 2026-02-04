.PHONY: clean run
.SILENT:

lib/libkr.so: obj/brb.o obj/lelinha.o | lib
	gcc -Wall -Werror -fPIC -shared $^ -o $@

obj/%.o: %.c %.h | obj
	gcc -Wall -Werror -fPIC -o $@ -c $<
	echo ctags --append -e $<

obj/%.o: %.c | obj
	gcc -Wall -Werror -fPIC -o $@ -c $<
	echo ctags --append -e $<

run: bin/brbcat
	echo "--- 8< ---"
	$<         < texto.ascii | tee          texto.debug
	echo "--- >8 ---"
	echo "--- 8< -d ---"
	$< -d      < texto.ascii | tee --append texto.debug
	echo "--- >8 ---"
	echo "--- 8< --debug ---"
	$< --debug < texto.ascii | tee --append texto.debug
	echo "--- >8 ---"

bin/%: obj/brbcat.o lib/libkr.so | bin
	gcc -Wall -Werror -fPIC -L$$(pwd)/lib -Wl,-rpath=$$(pwd)/lib -o $@ $< -lkr

clean: bin lib obj out
	rm -rf   $?
	mkdir -p $?

bin lib obj out:
	mkdir -p $@
