CC = gcc
CFLAGS = -Wall -Wextra
BUILD_DIR = build
PROGS = p1_2

all: $(PROGS)

$(PROGS):
	$(CC) $(CFLAGS) $@.c -o $(BUILD_DIR)/$@

clean:
	rm -r $(BUILD_DIR)/$(PROGS)
	
