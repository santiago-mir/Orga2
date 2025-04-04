CC = gcc
CFLAGS = -Wall -Wextra -pedantic
T = hola

all: $(T)

$(T): ${T}.o
		$(CC) $(CFLAGS) $^ -o $@

${T}.o: ${T}.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o $(T)

.PHONY: all clean