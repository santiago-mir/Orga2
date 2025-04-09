CC = gcc
CFLAGS = -Wall -Wextra -pedantic -MMD -MP
T ?= binario
T_SRC := $(T).c

# Verificar que el archivo principal existe
ifeq ($(wildcard $(T_SRC)),)
$(error El archivo "$(T_SRC)" no existe)
endif

# Todos los .c excepto el principal
SRCS := $(filter-out $(T_SRC), $(wildcard *.c))
OBJS := $(SRCS:.c=.o)
T_OBJ := $(T_SRC:.c=.o)

all: $(T)

$(T): $(OBJS) $(T_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJS:.o=.d) $(T_OBJ:.o=.d)

clean:
	rm -f *.o *.d $(T)

.PHONY: all clean
