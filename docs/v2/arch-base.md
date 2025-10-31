# Architecture Notes

The LTHLv2 Architecure is a 32-bit system that is relatively bare-bones in terms of implementation. The current goal with the architecture is to have a few bare-bones instructions that can be handled, with more to come much later.

In terms of how the data is handled, there is a 32-bit data bus, with all data being 32-bits. This takes inspiration from both the RISC-V and MIPS architectures.


This page determines the base instruction set. for LTHLv2.


## Instruction Types

There are multiple types of instructions that each have different use-cases Some are absolute, and others are somewhat up to interpretation.

the first 3 bits of every instruction determine the instruction's type.

For example, an *r-type* instruction starts with `000`.

### R-Type
```
000 NEGB CARRYIN aluop outreg areg breg
```

000 - Determines that it is an R-type instruction, and will use the ALU.

NEGB - 1 bit, says whether we do a NOT on the B input

CARRYIN - 1 bit sets the ALU's Carry in to 1 or 0.

aluop - ALU operation. 3 bits.

#### ALU Operations
| Number | Name | Description |
| - | - | - |
| 000 | Adder | Adds a and b. can use CARRYIN and NEGB to subtract. |
| 001 | AND | Does a Bitwise AND on A and B |
| 010 | OR | Does a Bitwise OR on A and B |
| 011 | XOR | Does a bitwise XOR on A and B |
| 100 | ROR | Shifts all bits to the right, with the lowest bit going into the Carry flag, and the carry flag going into the highest bit |
| 101 | ROL | Shifts all bits to the left, with the carry flag going into the lowest bit and the highest bit going into the carry flag |

outreg - 8 bits, output register number

areg - 8 bits, register number for input A.

breg - 8 bits, register number for Input B.


### IMM_TYPE
```
001 reg data
```

IMM_TYPE instructions only have one purpose, which is to load an immeditate value into a register.

001 - Determines that it is an IMM_TYPE

reg - 5 bits, Register to load into

data - 24 bits (3 bytes) data to immediately load into register.


### MEMREAD
```
010 00000 IN 00000000 STORE
```
this reads the value at register IN and stores it into register STORE.

010 - Determines that we are doing a memory read

00000 - All zeroes, unused

IN - 8 bit register that has the address we are reading from

STORE - 8 bit register in which we write the data to.

### MEMWRITE
```
011 00000 ADDR-REG DATA-REG 00000000
```

This writes the value DATA-REG to address ADDR-REG

011 - Determines that it is a MEMWRITE

any 0s are undefined

ADDR-REG - 8 bit register with address to write to

DATA-REG - 8 bit register with data that is being written

### JMPREL
```
100 CONDITION 00000000 SHORT-REL
```

Jumps relative to the current location based on a condition

100 - determines that this is a jumprel

CONDITION - 5 bytes, is a number between 0 and 4.

SHORT-REL 2-byte signed integer of where to jump relative to current address.

### JMPREG
```
101 CONDITION ADDRREG 00000000 00000000
```

Jumps absolutely to a memory address at register ADDRREG

101 - determines that this is a jumpreg

condition - see below

addrreg - 8 bits, address that stores the location to jump to.

### EXT1
```
110 CMD
```

110 - Determines that this is part of the extension set

CMD - the extension instruction, determined by the extensions

#### GET_SUPPORTED
```
110 00000 IGNORE(16bit) outreg
```
110 - Determines that its an extension command in EXT1
00000 - Determines that this is a GET_SUPPORTED function

IGNORE - 16 bits in the instruction that are ignored.

outreg - 8 bit register to write the supported features to

This instruction will return a Bitset of what extensions are available.

A value of 0, means that this is just the base set.

### EXT2
```
111 CMD
```
Also a part of the extension featureset.

No extensions support this instruction as of yet.


## Conditions

0 - Absolute
1 - Zero
2 - Carry
3 - Overflow
4 - Neg

## Registers

r0 - Always zero

r1-29 - General Purpose

r30 - Stack pointer (by convention, with some extensions requiring this to be the case)

r31 - Instruction Pointer

## Flags
0 - Carry
1 - Zero
2 - Overflow
3 - Negative
4-31 (up to implentation and extensions)


# Startup
The current development emulator takes a raw binary program of instructions, loads it at 0x0, and starts executing there. This is definitely a possible solution, but it would be nice to have RAM at the bottom of the memory addresses to make things easier.

## Current Functionality on init
1.) Set all flags to 0.
2.) Set all register's values to 0.
3.) Read startup vector from last 4 bytes of memory and set it to the instruction pointer (r31) 
4.) ready to execute!

### [Back To v1](%WEBPATH%/docs/v2/)