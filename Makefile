
CFG?=Makeconf

-include $(CFG)

ifndef MCU
$(error You need to specify the cpu type in MCU.)
endif

ifndef FCPU
$(error You need to specify a cpu frequency in FCPU.)
endif


SRC=src/tick.c src/urxtx.c


LD=avr-ld
CC=avr-gcc
SIZE=avr-size
CFLAGS=-Wall -Werror -Iinclude -DFCPU=$(FCPU) -mmcu=$(MCU)

OBJ=$(patsubst %.c,%.o,$(SRC))

default: libavril.a($(OBJ))

libavril.a($(OBJ)): $(OBJ)

clean:
	rm -f libavril.a $(OBJ)
.PHONY: clean

size:
	$(SIZE) libavril.a
.PHONY: size
