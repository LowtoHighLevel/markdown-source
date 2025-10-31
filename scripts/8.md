# Episode 8

### This will be with me in front of the camera.


Previously, we designed an 8-bit CPU out of logic gates. Last time, we took those concepts to the next level, and designed a 32-bit CPU architecture, and created a basic emulator for it.

Today, I want to take those concepts that we have learned, and put them to good use. Welcome back to Low To High Level. I'm your host Cory, and today we are going to look at Machine Code.

In the early days of computing, we had to write our computer programs by using plug boards, and later punch cards. These were all in binary, and had to be meticulously planned in advance.

A lot of programs from the past had to be planned, to ensure that no errors occured while running the program, as that would have a significant cost. Luckily, as computers have gotten cheaper, we have found ways to make this easier.

Today, I plan on writing the first program on our custom processor!

These days, that would often happen with a high level language, like C, though we don't have that. We don't even have assembly! Assembly is a programming language that directly translates to our machine code. As we don't have a program that can handle this, we will have to write our program in machine code from scratch.

Here's the idea for our first program. I want to print some text to the screen. It should be short and simple. Let's print out Hi.

### This is where we go to pen and paper.