CC = gcc
SRCS = main.c String.c StringInfo.c menu.c
CFLAGS = -c -Wall -std=c99
LDFLAGS = -std=c99
OBJS = $(SRCS: .c = .o)
EXE = lab1

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf $(OBJS) $(EXE)