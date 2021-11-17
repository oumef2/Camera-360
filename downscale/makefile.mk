CC =gcc
CFLAGS= -O3 -Wall

test: downscale.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<