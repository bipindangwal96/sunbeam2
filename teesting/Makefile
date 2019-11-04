
TARGET = 44_sin_cap_client
CSRC = $(TARGET).c
CSRC +=

COBJ = $(CSRC:.c=.o)

CC=gcc
CFLAGS=-ggdb3 -m32
LDFLAGS=

all: $(TARGET).out

$(TARGET).out: $(COBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(COBJ:%.o): %.c
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -f $(TARGET).out $(COBJ)

.PHONY: clean all

