EE_BIN = PS2_PAD_LAB.elf

EE_OBJS = src/main.o

EE_LIBS = -lpad -ldebug

all: $(EE_BIN)

clean:
	rm -f $(EE_BIN) $(EE_OBJS)

include $(PS2SDK)/samples/Makefile.eeglobal
