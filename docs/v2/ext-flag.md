# LTHLv2 Extended Flag Support Extension

The base CPU for LTHLv2 does not support accessing and setting flags directly.

This extension is a dependency for some other extensions.

## Instructions

All of this extension's instructions are under EXT1, meaning that all instructions start with 110.

### GET_FLAGS
```
110 00001 UNDEF UNDEF outreg
```
Writes the values of all flags to the output register

### SETFLAG
```
110 00010 000 flag 00000000 000000 val
```
Sets a flag's value

110 - EXT1

00010 - Set flag

000 - ignored

flag - Flag number

0000000 - ignored

0000000 - ignored

val - 1 bit value of the flag.

Setting val to 0 will clear the flag, and a value of 1 will set it.