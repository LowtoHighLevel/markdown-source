# LTHLv2 Interrupt Extension

The base CPU for LTHL does not support interrupts, or any I/O that is not memory-mapped.

If you wanted to handle any I/O operations, you would most likely need to poll it's memory location on a loop to get to it. That can be quite inefficient at times, so this extension is designed to allow for hardware interrupts.

## Main changes to CPU

### Flags
There are two new flags with this extension, Flag 4 is the interrupt enable flag, and flag 5 is the interrupt flag.


### Interrupt Vector
The interrupt vector is stored in register 29 in this case.
Whenever interrupts are enabled and an interrupt is triggered, we will jump to the interrupt vector stored in this register.

## Setting up the interrupt system on startup
There is a specific order of things that needs to happen for the interrupt system to work properly

First, the stack pointer needs to be set to a valid address in RAM. This will allow us to have a proper return address when we load the interrupt system.

Next, we will need to enable interrupts by setting the interrupt enable flag to 1. That will allow future interrupts to come in.

As for how to tell what type of interrupt was put in, this is yet to be decided. This may need some more planning here to figure that out.