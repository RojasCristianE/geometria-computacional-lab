# ──────────────────────────────────────────────────────────────
# Makefile – Geometría Computacional (SDL_BGI)
# ──────────────────────────────────────────────────────────────
CC      := gcc
CFLAGS  := -Wall -Wextra -g
LDFLAGS := -lSDL_bgi -lSDL2 -lm

# Detect all .c source files in project root
SRCS := $(wildcard *.c)
BINS := $(SRCS:.c=)

# ── Targets ──────────────────────────────────────────────────

.PHONY: all clean run

all: $(BINS)

# Pattern rule: compile any .c → binary
%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

run: main
	./main

clean:
	rm -f $(BINS)
