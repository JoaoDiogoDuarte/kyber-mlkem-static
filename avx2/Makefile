CC ?= /usr/bin/cc
CFLAGS += -mavx2 -mbmi2 -mpopcnt \
  -march=native -mtune=native -O3 -fomit-frame-pointer -z noexecstack
NISTFLAGS += -Wno-unused-result -mavx2 -mbmi2 -mpopcnt \
  -march=native -mtune=native -O3 -fomit-frame-pointer
RM = /bin/rm

SOURCES = hash.c KeccakSpongeWidth1600.c KeccakP-1600-AVX2.c

HEADERS = align.h hash.h api.h KeccakP-1600-AVX2.h  KeccakP-1600-SnP.h  KeccakSponge-common.h KeccakSpongeWidth1600.h namespace.h 

.PHONY: all clean

all: static

static: ${SOURCES} ${HEADERS}
	$(CC) $(CFLAGS) -c $(SOURCES) 

clean:
	-$(RM) -rf *.o *.a *.so