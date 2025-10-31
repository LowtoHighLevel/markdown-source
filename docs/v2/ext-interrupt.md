# LTHLv2 Interrupt Extension

The base CPU for LTHL does not support interrupts, or any I/O that is not memory-mapped.

If you wanted to handle any I/O operations, you would most likely need to poll it's memory location on a loop to get to it. That can be quite inefficient at times, so this extension is designed to allow for hardware interrupts.

## Required Features:
 - arch-base
 - ext-flag

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

## Calling an interrupt

An interrupt can be called one of two ways:

1.) From hardware. In real life, this would be via a pin on the CPU. When the value is toggled, an interrupt will be triggered

2.) From software via the interrupt instruction.


## Instructions

### Interrupt
```
110 00011 IGNORE SET|CLEAR
```

110 - EXT1 instruction type

00011 - Interrupt instruction

IGNORE - rest of bits are ignored.

SET_CLEAR - 1 bit. if it is 1, will trigger an interrupt, if 0, will clear an interrupt.

This will trigger an interrupt via software.



## What happens when an interrupt is called?

First, the interrupt flag is set to 1.


then the current memory address is written to the memory address at r30 (stack pointer).

Next, we will do a jump register to the value in register 29. From there, the interrupt is run.

## How do I clear an interrupt?
To clear the interrupt and return to the main method, you will

1.) Make sure that the stack (r30) is back to a "normal" state, meaning that the stack is how it was before the interrupt was called.

2.) Run the Interrupt instruction with the SET value to CLEAR (0). This will:

  a.) Set the interrupt flag to 0.
  b.) Jump to the address stored at the stack pointer (r30).

At this point, we are back to our normal point of execution.