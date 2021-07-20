src = $(wildcard src/*.c)
obj = $(src:.c=.o)
INC = -I. -Iinclude
CFLAGS = $(INC)
#LDFLAGS = -lGL -lglut -lpng -lz -lm

prog: $(obj)
	$(CC) $(INC) -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj) prog