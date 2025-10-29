# Episode 9 Planning
Last time on LTHL, we wrote a quick program in machine code that prints to the screen.

I have a few gripes with the current system though.

The biggest issue I have is that parts of the binary source is not completely relocatable. Another issue is that there is no way to have some sort of hardware/software interrupt, which may be useful for input in the future.

One way around that is to poll for interrupts via code for now, but that may be a little long-winded, and a pain to do when we should have it handle it immediately. Instead, I would like to have a vector table that jumps to a memory address whenever an interrupt is called, and puts the current memory address in a position in RAM. that would be a little more beneficial to us in the end.

I'm looking for this to be an array of 32 bit addresses, with a pointer to that array at memory address 0.

This will mean that the vector table could theoretically be moved, and relocated if it ever needed to be expanded in the future.

Of course, it's not always that simple, but it definitely is what I am thinking of doing.

This episode will involve discussing what I previously did, and looking at a few other options similar to what I would like to implement when needed.

The unfortunate thing about what I would like to do, is that it will cost a few cycles, but that's not the end of the world.

Another possibility is to use some of our registers as the interrupt vectors. In that case, we would yoink the current address into a register, jump to the position in the register of the interrupt vector, and output that. Now that I am thinking about it, the vector table could be more of an implementation concern as opposed to the actual program. That means that our bios/bootloader will actually load the correct registers when the time comes.

Let's say that by convention, r31 is always the return address, r30 is the interrupt vector, and r29 is the stack pointer. That will make it possible to handle all of it at once. Triggering an interrupt will push an item onto the stack, with the other stuff happening. We could also have an "interrupt enable" flag that allows or disallows interrupts, which means that the programmer can make sure that interrupts will happen only if the stack is properly set up. This also gives a best of both worlds scenario, where any current programs will not break.


So, in laymans terms, here's the official plan:

1.) Add a few new instructions: 