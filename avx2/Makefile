CC ?= /usr/bin/cc
CFLAGS += -Wall -Wextra -Wpedantic -Wmissing-prototypes -Wredundant-decls \
  -Wshadow -Wpointer-arith -mavx2 -mbmi2 -mpopcnt \
  -march=native -mtune=native -O3 -fomit-frame-pointer -z noexecstack
NISTFLAGS += -Wno-unused-result -mavx2 -mbmi2 -mpopcnt \
  -march=native -mtune=native -O3 -fomit-frame-pointer
RM = /bin/rm

SOURCES = kem.c indcpa.c polyvec.c poly.c fq.S shuffle.S ntt.S invntt.S \
  basemul.S consts.c rejsample.c cbd.c verify.c
SOURCESKECCAK   = $(SOURCES) fips202.c fips202x4.c symmetric-shake.c symmetric-shake.c 
HEADERS = params.h align.h kem.h indcpa.h polyvec.h poly.h reduce.h fq.inc shuffle.inc \
  ntt.h consts.h rejsample.h cbd.h verify.h symmetric.h superrandombytes.h
HEADERSKECCAK   = $(HEADERS) fips202.h fips202x4.h keccak4x/KeccakP-1600-times4-SnP.h keccak4x/KeccakP-1600-unrolling.macros keccak4x/KeccakP-SIMD256-config.h keccak4x/KeccakP-align.h keccak4x/KeccakP-brg_endian.h

.PHONY: all

all: static

static: libpqcrystals_mlkem768_avx2.a

#--
_OBJECTS = $(SOURCESKECCAK:%.c=%.o)
OBJECTS = $(_OBJECTS:%.S=%.o)
libpqcrystals_mlkem768_avx2.a: $(SOURCESKECCAK) $(HEADERSKECCAK) superrandombytes.h symmetric-shake.c
	rm -f *.o
	rm -f *.a
	$(CC) -fPIC $(CFLAGS) -DKYBER_K=3 -c $(SOURCESKECCAK) keccak4x/KeccakP-1600-times4-SIMD256.c symmetric-shake.c 
	ar -rc $@ $(OBJECTS) KeccakP-1600-times4-SIMD256.o
#--

clean:
	-$(RM) -rf *.o *.a *.so
	-$(RM) -rf keccak4x/KeccakP-1600-times4-SIMD256.o
