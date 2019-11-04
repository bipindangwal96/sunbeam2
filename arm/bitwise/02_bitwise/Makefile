
TARGET = main
CSRC = $(TARGET).c
CSRC += 

COBJ = $(CSRC:.c=.o)

CC=gcc
CFLAGS=-ggdb3
LDFLAGS=

all: main.out

#print:
#	@echo  "Source Files:" $(CSRC)
#	@echo  "Object Files:" $(COBJ)

$(TARGET).out: $(COBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(COBJ:%.o): %.c
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -f $(TARGET).out $(COBJ)

.PHONY: clean all

