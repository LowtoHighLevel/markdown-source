# Episode 9 Planning
Last time on Low To High Level, we wrote a quick program in Machine code to see if our idea of a computer will work.

This time, I want to take that a step further.

I would love to do a deep dive into the GNU Binutils suite, but that is quite difficult and time-consuming for what I want to get done right now.

In the mean time, I have a few small gripes with how our CPU works as of right now.

As a way to try and rectify that, I have a few small improvements that can be made.

Off-camera, I went back through the old CPU code, added comments, and generally cleaned things up. Functionally, it is exactly the same as it was.

My biggest issue with the CPU is that I don't have any way to handle any input. With the current design, all i/o is mapped to RAM, which is nice to have, but isn't always the most useful.

To see if we need to handle something from i/O we would have to be constantly checking if it is necessary, when instead we could just have an interrupt.

My plan is to add a few new flags to the CPU to handle interrupts, as well as to add a few new registers to allow for an interrupt to be triggered. In order for this to work, we're going to have to use a few extra little tools.

I wrote a partial assembler off-camera a long time ago, and though it's not exactly what I hoped for, it may be enough to get a couple of quick programs testing.

Remember that program that we wrote last time? Here it is in our temporary assembly language.

```asm
    ld r1 16384
    ld r2 'H'
    write r1 r2
    ld r2 'I'
    write r1 r2
    ld r2 '!'
    write r1 r2
    ld r2 '\n'
    write r1 r2
    ld r30 36000
```

This should function exactly how our hand-assembled program did and will be easier to test.

Now that we have a quick little program to test things, we can try to set up some code to handle interrupts.

We will need to add a few new flags to the CPU, an interrupt enable flag, and an interrupt flag. The enable flag will let the CPU know that we can receive interrupts, and the interrupt flag will let us know that there is currently an interrupt being handled.

I wrote [this site](https://lowtohighlevel.github.io/) to house some notes and documentation on the CPU and project. I also sometimes write some articles on my progress on this project.

If we look at our documentation, we have a base case of how the architecture works, and how our interrupts work.

With the latest version of the documentation, our emulator is a little out of date, so we will need to update it to support modifying flags, as well as a few other features.

