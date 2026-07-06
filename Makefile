CC=gcc
CFLAGS=-g -Wall -Wextra -std=c99 -Iinclude -fsanitize=address
LDFLAGS = -fsanitize=address
LIBS=-lm
TARGET=proc_node

SRC_DIR = src
OBJ_DIR = build
INC_DIR = include
# you may need to put your extra files here
_DEPS = message.h requests.h memory.h
_OBJS = main.o

_SRCFILES = main.c memory.c req_latest_temp.c req_latest_seis.c req_max_seis.c req_avg_temp.c req_del.c
_OBJS = $(patsubst %.c,%.o,$(_SRCFILES))

DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) 

