CFLAGS=-Wall -Werror -std=gnu99 -pedantic -ggdb3
MY_OBJS=cards.o deck.o eval.o test-c4deck.o

test-c4deck: $(MY_OBJS)
	gcc $(CFLAG) -o $@ $(MY_OBJS)
clean:
	rm -f $(MY_OBJS) test-c4deck.o *~
