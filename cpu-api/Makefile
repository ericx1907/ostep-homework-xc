CC = gcc
CFLAGS = -Wall -Wextra
BUILD_DIR = build
SRCS = $(wildcard *.c)
# See https://www.gnu.org/software/make/manual/make.html#Substitution-Refs
#+and https://www.reddit.com/r/C_Programming/comments/u83pdl/how_to_write_a_simple_makefile_that_compiles_all/
BINS = $(patsubst %.c,%,$(SRCS))

all: $(BINS)

$(BINS):
	$(CC) $(CFLAGS) $@.c -o $(BUILD_DIR)/$@

clean:
	rm -rf $(BUILD_DIR)/*
