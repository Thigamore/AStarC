FILES := main.c tree.c

main.o tree.o: $(FILES)
	gcc $(FILES) -o main