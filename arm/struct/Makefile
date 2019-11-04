
TARGET = struct.out
CSRC = struct.c
CSRC +=

COBJ = $(CSRC:.c=.o)

CC=gcc
CFLAGS=-ggdb3 -m32
LDFLAGS=-lm

all: $(TARGET)

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

