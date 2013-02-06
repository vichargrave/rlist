#
# Makefile for the reverse singly linked list test application.
#
# http://vichargrave.com
#

CC		= gcc
CFLAGS		= -c -Wall
LDFLAGS		=
SOURCES		= rlist.c
INCLUDES	= -I.
OBJECTS		= $(SOURCES:.c=.o)
TARGET		= rlist

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET)

