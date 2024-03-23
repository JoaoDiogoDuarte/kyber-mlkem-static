CC ?= /usr/bin/cc
CFLAGS += -Wall -Wextra -Wpedantic -Wmissing-prototypes -Wredundant-decls \
  -Wshadow -Wpointer-arith -mavx2 -mbmi2 -mpopcnt \
  -march=native -mtune=native -O3 -fomit-frame-pointer -z noexecstack
NISTFLAGS += -Wno-unused-result -mavx2 -mbmi2 -mpopcnt \
  -march=native -mtune=native -O3 -fomit-frame-pointer
RM = /bin/rm

SOURCES = hash.c  KeccakSpongeWidth1600.c KeccakP-1600-AVX2.c

HEADERS = align.h hash.h api.h KeccakP-1600-SnP.h namespace.h  KeccakSponge-common.h KeccakSpongeWidth1600.h KeccakP-1600-AVX2.h KeccakSponge.inc

.PHONY: all clean

all: sha3.so

sha3.so: hash.c hash.h api.h
	$(CC) -shared -fPIC $(CFLAGS) -o $@ $<

clean:
	-$(RM) -rf *.o *.a *.so