# Episode 8 planning
Previously on Low to High Level, we used logic gates to create an 8 bit computer, that could theoretically run anything.

Last episode, we designed a 32-bit CPU, and executed some basic programs.

For Episode 8, I want to look at and design a quick program that runs.

Before we had compilers and assemblers, programs had to be written purely in machine code, and hand-compiled on punch cards, or via plug boards to get the correct output.

These often were massive piles, that would be a big hassle if they were misplaced or dropped.

Today, I want to create a very simple program that runs on our CPU.

A Very basic program that people may often write, is Hello World.

It would be rather complex to write this in machine code, so instead we will print "Hi" to the screen.

I haven't touched this computer in a minute, as I have had to focus on some other major projects, but this one is important.

In order to print to the screen with our emulator, we will use the memory-mapped I/O.

Our very hacky and basic emulator only has two bits of I/O.

Most of our memory is RAM, and one byte is a character buffer that prints to the console!

It is at memory address 16384. or hex 4000.

Note this down as this will help.

To help with the manual machine code writing, developers would write assembly code and manually parse it to machine code. This was common.

To make our program work, Let's write some pseudo-code to get an idea of what we have to do.

We have no functions, or utility scripts, so we will have to break it down.

```
method hi_program:
    Load 'H'
    Print 'H'
    Load 'I'
    Print 'I'
    Load '!'
    Print '!'
    Exit.
```

That should be what we need to do for this program.

We theoretically could do some sort of recursion, but that would be a little complicated for our use case.

Let's simplify this closer to some assembly now:

```

ld r2 16386 # Load the write address
ld r1 'H' # Load the character
write r2 r1
ld r1 'I'
write r2 r1
ld r1 '!'
write r2 r1
exit
```

This is a little closer to some assembly, and can more easily be understood by our computer.

Now let's look at some of our instructions and see what matches it the best.

For the loads, we'll want to do an immediate load.
To do that, we use the IMM_TYPE opcode

It goes something like this: 

```
001 5-bitreg 29-bitdata
```

Let's try loading our address into the register.

First, we'll want the binary equivilent of 16386, as mentioned before, it is equal to hex 4000.

We can break each hex number into four binary digits, and it applies directly.

So it will be `0100 0000 0000 0000`.

Our five bit register directly translates to our register number.

So our instruction will look like `00100010 00000000 01000000 00000000`

We can do something similar for loading the first character, replaceing the last three bytes with the ASCII value for each character.

H is 0x48, I is 0x49, and ! is 0x21

So our other load instructions are:

`00100001 00000000 00000000 01001000` - Load H

`00100001 00000000 00000000 01001001` - Load I

`00100001 00000000 00000000 00100001` - Load !

We will also have to write to memory.

A MEMWRITE OPcode looks like this:
```
011 00000 ADDR-REG DATA-REG 00000000
```

For all of our writes, we will be using the same parameters, being address register 2, and data register 1.

So we will write 
`01100000 00000010 00000001 00000000`

That will be our main math.

Our emulator, as it is not a fully functional computer, with on/off capabilities will need a way to exit. Normally this would be done by jumping to a return address, but we aren't ready for that.

We also may migrate the emulator to something more advanced in the future, so we will use this feature temporarily, but be aware it is more of a hack than a feature.

If we write 36000 to register 30, we will exit.

That is equal to hex 8CA0.

We can do that by loading immediate.

`00111110 00000000 10001100 10100000`

That will exit our program.

Now, let's put it all together.

```
00100010 00000000 01000000 00000000 # Load 0x4000 into r2
00100001 00000000 00000000 01001000 # Load H into r1
01100000 00000010 00000001 00000000 # Write the character in r1 to address at r2
00100001 00000000 00000000 01001001 # Load I
01100000 00000010 00000001 00000000 # Write I
00100001 00000000 00000000 00100001 # Load !
01100000 00000010 00000001 00000000 # Write !
00111110 00000000 10001100 10100000 # Hacky program exit.
```

That should be our program in binary, for the most part.

When I run this program, and due to some quirks with the emulator, all instructions are in a little-endian format.

This means that for every instruction, we need to write each byte backwards. When I initially wrote the program, I wrote it and broke it up by bytes. This will help with this process.

Our code should now look like this:
```
00000000 01000000 00000000 00100010 # Load 0x4000 into r2
01001000 00000000 00000000 00100001 # Load H into r1
00000000 00000001 00000010 01100000 # Write the character in r1 to address at r2
01001001 00000000 00000000 00100001 # Load I
00000000 00000001 00000010 01100000 # Write I
00100001 00000000 00000000 00100001 # Load !
00000000 00000001 00000010 01100000 # Write !
10100000 10001100 00000000 00111110 # Hacky program exit.
```

That should be our final binary program.

Now we will want this program in a binary format that we can actually run.

We could theoretically make this ourself, though that would require a lot of bit conversion.

a simpler way is to convert our program to hex, and output the binary that way, using a program, or a hex editor.

A quick reminder: one hex character is equivilent to four bytes of binary. Numbers 0-9 are the same, while 10-16 is equal to A-F.

```
00 40 00 22 # Load 0x4000 into r2
48 00 00 21 # Load H into r1
00 01 02 60 # Write the character in r1 to address at r2
49 00 00 21 # Load I
00 01 02 60 # Write I
21 00 00 21 # Load !
00 01 02 60 # Write !
A0 8C 00 3D # Hacky program exit.
```
In my notes, I have written a quick test program that will convert a hex program to a binary object code.

It is called asciitobin. It can be found [here](%WEBPATH%/notes/asciitobin/)
`00 40 00 22 48 00 00 21 00 01 02 60 49 00 00 21 00 01 02 60 21 00 00 21 00 01 02 60 A0 8C 00 3E`

Let's use my asciitobin program and compile it.
`asciitobin out.bin 00 40 00 22 48 00 00 21 00 01 02 60 49 00 00 21 00 01 02 60 21 00 00 21 00 01 02 60 A0 8C 00 3E`

Now if we run our trusty emulator, we should see..


`HI!`

That means that our program works!