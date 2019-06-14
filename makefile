CC:=g++
SRCS:=main.c

exe = main.exe
main: main.o lib.a
	@$(CC) $< lib/lib.a -o $(exe)
main.o: $(SRCS)
	@$(CC) -c $(SRCS)
lib.a:
	$(MAKE) -C lib
clean:
	rm -f *.o $(exe)
	$(MAKE) -C lib clean
