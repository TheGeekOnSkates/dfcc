# The virtual machine (VM) for Dirt's Forth Chip

Once the compiler is done - and by "done" I mean my current to-do list is finished - it will be time to put it to use.  My game plan here is:

1. Create a function that executes all 32 of the words/instructions in `ISA.h`.  Note that since we're currently talking Forth, I'm just gonna call them words, not instructions or opcodes.  Once we get into classic mode, then I'll use the right lingo for classic CPU design (registers etc.). :)
2. Use that function in a loop to run compiled Forth code.  Maybe I'll try my hand at writing other Forth words, like `ROT` or `PICK`, in Forth-mode Assembly (so hilarious to be calling it that :D).  Not gonna tackle `:`, `if` or anything like that... at least not *yet*. :)
3. Work the code created in steps 1 and 2 into a header-only library, something I can use in unrelated projects.  Like I'm building an audio game platform for Linux - a Forth-based VM would kinda rock at that (and taht already uses a 24-instruction VM that is very Forth-like).  It also opens the door for code I build on one that is useful on the other.
4. For the purposes of *this* project, use that library to create a sort of "monitor" (to borrow the term from Assembly).  Show me what it's doing, what's on the stack, etc.  Maybe a REPL... idk, getting *waaaay* ahead of myself here :)
