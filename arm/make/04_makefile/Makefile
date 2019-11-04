
TARGET = main.out
CSRC = main.c
CSRC += add.c subtract.c multiply.c divide.c

COBJ = $(CSRC:.c=.o)

CC=gcc
CFLAGS=-ggdb3 -m32
LDFLAGS=-lm

all: main.out

#print:
#	@echo  "Source Files:" $(CSRC)
#	@echo  "Object Files:" $(COBJ)

$(TARGET): $(COBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(COBJ:%.o): %.c
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -f $(TARGET) $(COBJ)

.PHONY: clean all

