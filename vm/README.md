# The virtual machine (VM) for Dirt's Forth Chip

Once the compiler is done - and by "done" I mean my current to-do list is finished - it will be time to put it to use.  My game plan here is:

1. Create a function that executes all 32 of the words/instructions in `ISA.h`.  Note that since we're currently talking Forth, I'm just gonna call them words, not instructions or opcodes.  Once we get into classic mode, then I'll use the right lingo for classic CPU design (registers etc.). :)
2. Use that function in a loop to run compiled Forth code.  Maybe I'll try my hand at writing other Forth words, like `ROT` or `PICK`, in Forth-mode Assembly (so hilarious to be calling it that :D).  Not gonna tackle `:`, `if` or anything like that... at least not *yet*. :)
3. Work the code created in steps 1 and 2 into a header-only library, something I can use in unrelated projects.  Like I'm building an audio game platform for Linux - a Forth-based VM would kinda rock at that (and taht already uses a 24-instruction VM that is very Forth-like).  It also opens the door for code I build on one that is useful on the other.
4. For the purposes of *this* project, use that library to create a sort of "monitor" (to borrow the term from Assembly).  Show me what it's doing, what's on the stack, etc.  Maybe a REPL... idk, getting *waaaay* ahead of myself here :)

---------------------------------------------------------------------------

# Dirt's notes, better formatted for plain-text and Markdown

Markdown seriously needs a way to do tables.  I'm a big fan of just using the Tab key to line stuff up.  And in fact I kinda think that's why we call it "Tab" - short for table or the funkier word "tabular" (tubular dude :D).  Buuuut... it doesn't.  Markdown doesn't do tables, and he fought long and hard with putting his notes on Locals in an eas-yto-read format, so I'm gonna break it down differently.

## The ISA

**Primitive:** `NEXT`
**Function:** Fetch word in IP
**Steps:**
1. Fetch address in IP to Jump Table
2. Increase IP
3. Jump to address
**ASCII code:** 0

**Primitive:** `DOLIST`
**Function:** Push IP to return stack
**Steps:**
1. Push IP to RS
2. Copy first address to IP
3. Jump to Subroutine Next
**ASCII code:** 1

**Primitive:** `EXIT`
**Function:** Pop return stack to IP
**Steps:** 
1. Pop RS to IP
2. Jump to Subroutine Next
**ASCII code:** 2

**Primitive:** `BYE`
**Function:** Exits Forth
**Steps:** Final return to where invoked
**ASCII code:** 3
**NOTE:** The difference between `EXIT` and `BYE` is interesting; we're not talking about a Forth in the traditional sense, like GForth or PForth or SwiftForth, a program to be "exited".  In that context, `BYE` is one of the first words a newbie learns.  But on a CPU...?  I'm thinking `EXIT` is more like what th 6502 Assembly language calls `RTS` (return from subroutine) and `BYE` is what that language calls `BRK` (end program).  I could be wrong, but for now that is my understanding of this one.

**Primitive:** `?RX`
**Function:** Reads character from input device
**Steps:** 
1. Test for character input (just 1 char)
2. Push the input char and true (-1?) on the stack, or false (0) if there is no char
**ASCII code:** 4

**Primitive:** `TX!`
**Function:** Sends char on stack to output device
**Steps:** Send char to output
**ASCII code:** 5

**Primitive:** `!IO`
**Function:** Init IO device
**Steps:** Init IO device
**ASCII code:** 6
**NOTE:** What does this look like?  Like okay, I'm sure when teh program starts, it will probably load stdout, stdin and stderr; what about files?  I'm sure I'm *waaaay* ahead of myself here, but it seems like there will be multiple use cases for this word - maybe even an RS232 serial port or something. xD  Okay seriously tho, this one will probably be crazy-important for later.

**Primitive:** `EXECUTE`
**Function:** Execute code at address
**Steps:** 
1. Get address from stack
2. Jump
**ASCII code:** 7

**Primitive:** `DOLIT`
**Function:** Take the literal from inline code and put on the stack
**Steps:** 
1. Read the number or text
2. Push it onto stack
**ASCII code:** 8

**Primitive:** LEFT OFF HERE
**Function:** 
**Steps:** 
**ASCII code:** 

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 

## To be formatted

Nextloop decrement index and exit loop if index <0 exit loop 9

?branch branch if flag is 0 pop from stack flag, branch on 0 10

branch branch to inline address IP = (IP) 11

! write stack to address pop address then pop data write to address the data 12

@ read address to stack pop address then pop data from address and push on stack 13

C! same as ! But for bytes only 14

C@ same as @ but for bytes only 15

RP@ push current RP to stack 16

RP! push stack to RP init RP 17

R> pop return stack to stack 18

R@ copy return stack to stack 19


