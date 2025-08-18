# LTHL CPU Operations

The CPU writeout has a series of commands that can be run. Each one has a number of arguments.

Each output is a maximum of two bytes, with each byte being capable of being split in half.

## Operation Table
| Opcode | ASM   | Arg 1 | Arg 2  | Arg 3  | Usage |
|--------|-------|-------|--------|--------|-------|
| 0x0    | add   | w reg | r reg1 | r reg2 | Adds two numbers together |
| 0x1    | sub   | w reg | r reg1 | r reg2 | Subtracts two numbers |
| 0x2    | and   | w reg | r reg1 | r reg2 | runs a bitwise AND on two numbers |
| 0x3    | or    | w reg | r reg1 | r reg2 | runs a bitwise OR on two numbers |
| 0x4    | xor   | w reg | r reg1 | r reg2 | runs a bitwise XOR on two numbers |
| 0x5    | not   | w reg | r reg  |        | runs a bitwise NOT on two numbers |
| 0x6    | rol   | w reg | r reg  |        | rotates bits Left |
| 0x7    | ror   | w reg | r reg  |        | rotates bits right |
| 0x8    | set   | w reg | value  |        | Sets a value into a register |
| 0x9    | move  | w reg | r reg  |        | Moves a value between two registers |
| 0xA    | print | r reg | mode   |        | **DEBUG ONLY (for emulation)** Prints the values in a register, mode is a number |
| 0xB    | push  | r reg |        |        | Pushes the values of a register to the stack |
| 0xC    | pop   | w reg |        |        | Pops a value from the stack into a register |
| 0xD    | jfp   | flag  | value  |        | jumps if a flag is set to memory location value. |
| 0xE    | jfn   | flag  | value  |        | jumps if a flag is not set to memory location value. |
| 0xF    | sptr  | idx   | value  |        | Sets a specific pointer to a value. |

## Print Notes
The Screen Debug Printer, is a command-line printer for debugging the CPU.

The first argument is the register the value needs to be at to print it.

The second argument is the mode of printing.
### Modes
| Number | Description |
|--------|-------------|
| 0      | Default, Prints The regiser number, as well as its decimal value. |
| 1      | Prints a character                                                |

### [Back To v1](%WEBPATH%/docs/v1/)