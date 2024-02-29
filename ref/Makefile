CC ?= /usr/bin/cc
CFLAGS += -Wall -Wextra -Wpedantic -Wmissing-prototypes -Wredundant-decls \
  -Wshadow -Wpointer-arith -O3 -fomit-frame-pointer -z noexecstack
NISTFLAGS += -Wno-unused-result -O3 -fomit-frame-pointer
RM = /bin/rm

SOURCES = kem.c indcpa.c polyvec.c poly.c ntt.c cbd.c reduce.c verify.c superrandombytes.c
SOURCESKECCAK = $(SOURCES) fips202.c symmetric-shake.c
HEADERS = params.h kem.h indcpa.h polyvec.h poly.h ntt.h cbd.h reduce.c verify.h symmetric.h superrandombytes.h
HEADERSKECCAK = $(HEADERS) fips202.h

.PHONY: all static

all: static

static: libpqcrystals_mlkem768_ref.a

#--
_OBJECTS = $(SOURCESKECCAK:%.c=%.o)
OBJECTS = $(_OBJECTS:%.S=%.o)
libpqcrystals_mlkem768_ref.a: $(SOURCESKECCAK) $(HEADERSKECCAK) superrandombytes.c symmetric-shake.c
	rm -f *.a
	rm -f *.o
	$(CC) -fPIC $(CFLAGS) -DKYBER_K=3 -c $(SOURCESKECCAK) symmetric-shake.c
	ar -rc $@ $(OBJECTS)
#--

clean:
	-$(RM) -f *.gcno *.gcda *.lcov *.o *.so *.a

