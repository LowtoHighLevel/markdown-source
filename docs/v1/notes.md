# Notes.txt
This file was originally a text file in an old repository.

Its source is copied here.

```
ALU Functions: - 2 Arguments
ADD
SUB
AND
XOR
OR
NOT
ROR
ROL

Registers: 8-bit Input, Select, Output, Clock
a
b
c
d
e
f
sp

4 bits for instruction, 4 bits for first register, 4 bits for second register, 4 bits for 3rd register
16-bit instruction set, 4 bit data bus.

set a,8 ; set a specfic value from input into a.
mov b,a ; move value of b into a.

alu commands:
add, b a c ; add value of b into a, and store in c.
rol, a c ; rotate left a and store in c.

instruction
0x00 - add
0x01 - subtract
0x02 - and
0x03 - or
0x04 - xor
0x05 - NOT
0x06 - rol
0x07 - ror
0x08 - set
0x09 - move
0x10 - print register
0x11 - push
0x12 - pop
0x13 - jmp
0x14 - jn



register
0x1 - a
0x2 - b
0x3 - c
0x4 - d
0x5 - e
0x6 - f
0x7 - g

129 16
set 1 16
130 15
set 2 15
19 18
sub 3 1 2
163 0
print 3
179 0
push 3
129 0
set 1 0
146 16
move 2 1
147 16
move 3 1
163 0
print 3
195 0
pop 3
163 0
print 3
115 48
ror 3 3
163 0
print 3
99 48
rol 3 3
163 0
print 3
131 15
set 3 15
130 7
set 2 7
67 50
xor 3 3 2
163 0
print 3

129 16 130 15 19 18 163 0 179 0 129 0 146 16 147 16 163 0 195 0 163 0 115 48 163 0 99 48 163 0 131 15 130 7 67 50 163 0

0b00000001
0b10000000
```

### [Back To v1](%WEBPATH%/docs/v1/)