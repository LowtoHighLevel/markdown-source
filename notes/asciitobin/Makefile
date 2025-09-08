CC=zig cc

OUTPUT=asciitobin
ifeq ($(OS),Windows_NT)
    OUTPUT = asciitobin.exe
endif

.PHONY: all clean mian target

all: clean $(OUTPUT)


asciitobin.exe: asciitobin
	@cp asciitobin asciitobin.exe

asciitobin: main.c
	$(CC) -o asciitobin main.c

clean:
	rm -f *.exe asciitobin *.pdb