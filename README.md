# TO-DOs

## Compiler:

* Get it to recognize Classic Mode words
* Rework `doLit` - it's not what I thought it was
* Figure out how numbers are to be pushed onto the stack in Forth mode
* In classic mode, once I know what the syntax is supposed to be for each instruction, set up the compiler to expect that syntax.  For example, let's say `load imm` means "load an 8-bit number into a 16-bit address" and the syntax is something like `LOAD $1234 #$FF`.  The compiler will see `LOAD` and then expect an address; it'll see the address and then expect a number; if it sees the "#" it'll know that's a literal number vs. `load reg`, whatever that turns out to mean.
* At some point I'll probably want to set up a way to import/include files
* I'm sure we'll also want a way to define constants, labels etc. but these are all way off.

## Emulator

I'm going to start out in Classic Mode, since I'm more familiar with classic Assembly than this funky Forth variant.  I've never seen "eForth" before, though Dirt has hooked his subscribers up with a PDF (gotta read that).  But the first thing I plan on doing is getting it to run Classic Mode instructions.
* Once it does them all - and there are far less than 32 - then comes Forth Mode.  Some of the instructions are things I've done for my own 8-bit Forth (dup, swap, over, @, !, etc.) but a lot of them are not things I've ever seen in a Forth, so that's gonna be interesting.
* And at that point - if (Lord willing, *WHEN*) the compiler and emulator are able to use the entire ISA - then it'll be time to turn my attention to the memory map.  Dirt's CPU is supposedly 32-bit, and he even has it set up to have multiple cores (which is new territory for me, as I've only ever worked with 1 core at this awesome low level).  But I'm sure for the emulator to truly emulate Dirt's CPU... I'll need to learn all that. :-)


---------------------------------------------------------------------------

# dfcc - Dirt's Forth Chip Compiler

This project has three separate but related goals:

1. **To help a friend - or as close to a friend as we can be without having ever met in person. :D**  This is partly for `@Dirt2901` over on lunduke.locals.com.  This dude is building his own CPU, with a "classic mode" and a "Forth mode".  Yes, his CPU is using Forth as a low-level native instruction set!  That is so cool!  This is first and foremost a cross-compiler.  This way, he can compile code that runs on his chip as he builds and tests it.
2. **To help me in a few of my projects.** I'm building an 8-bit Forth.  I'm building an audio game system for Linux.  I'm building so many things that would benefit from a nice little VM that actually *interprets* the ISA of Dirt's Forth chip.  Even if things don't go all that great, I'm sure I can use the stuff I'm building here for my other projects.  Of course, for the purpose of this Git repo, the goal is eventually something that emulates his actual hardware - but for now, a little VM will have to do. :)
3. **To have some fun!** I've enjoyed creating stuff like this, for the purpose of creating stuff like this (lol).  Anyone who has seen my GitHub knows that.  Projects like this are generally more about the journey than the destination.  So it's nice to be able to play with it at my own pace, and enjoy the ride.  :)
