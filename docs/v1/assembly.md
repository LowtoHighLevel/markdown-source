# Assembly Notes.

## Comments
Comments are started in the with the characters: `/*` and end with a `*/`.
They can not be used in the middle of an instruction.

## End of instruction
You can end an instruction in three ways:

 1. The end of a file.
 2. With a new line: `\n`.
 3. With a semicolon: `;`.

## Instructions

Instructions follow a single format:

They start with an opcode, followed by their arguments.

For example, to add two numbers, you can run:
`add 3 1 2`. It will add the values in registers 1 and 2, and write it into register 3.

All op codes and their flags, can be seen in the opcodes assembly file.

### [Back To v1](%WEBPATH%/docs/v1/)