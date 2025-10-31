# LTHLv2 Extensions
The LTHLv2 CPU architecture supports different CPU extensions.

Built in to the CPU is a single extension instruction.

It goes like this:

```
110 00000 IGNORE(16bit) outreg
```

This will return an integer into outreg of what extensions are supported. This is a bitfield that depends on the native length.

Our default implementation is a 32-bit system.

Because it is a 32-bit system, then we support 32 different extensions.

## Table of Extensions

| Bit Number | Name |
| - | - |
| 0 | [Flag](%WEBPATH%/docs/v2/ext-flag) |
| 1 | [Interrupt](%WEBPATH%/docs/v2/ext-interrupt) |

