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

**Primitive:** `NEXTLOOP`
**Function:** Decrement index and exit loop
**Steps:** If index <0 exit loop
**ASCII code:** 9

**Primitive:** `?BRANCH`
**Function:** Branch if flag is 0
**Steps:** 

1.  Pop from stack
2. Branch if the number just popped == 0

**ASCII code:** 10

**Primitive:** `BRANCH`
**Function:** Branch
**Steps:** Branch (jump) to inline address IP = (IP)
**ASCII code:** 11

**Primitive:** `!`
**Function:** Write stack to address
**Steps:** 

1. Pop address
2. Pop data
3. Write data to address

**ASCII code:** 12

**Primitive:** `@`
**Function:** Read address to stack
**Steps:** 

1. Pop address
2. Pop data from address
3. Push on stack

**ASCII code:** 13

**Primitive:** `C!`
**Function:** C! same as `!` But for bytes only
**Steps:** C! same as `!` But for bytes only
**ASCII code:** 14

**Primitive:** `C@`
**Function:** Same as `@` but for bytes only
**Steps:** Same as `@` but for bytes only
**ASCII code:** 15

**Primitive:** `RP@`
**Function:** Push current RP to stack
**Steps:** Push current RP to stack
**ASCII code:** 16

**Primitive:** LEFT OFF HERE
**Function:** 
**Steps:** 
**ASCII code:** 17

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 18

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 19

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 20

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 21

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 22

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 23

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 24

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 25

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 26

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 27

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 28

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 29

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 30

**Primitive:** 
**Function:** 
**Steps:** 
**ASCII code:** 31

## To be formatted

Primitive Function Steps Ascii code
Next fetch word in IP fetch address in IP to Jump Table 0
inc IP inc IP
jump jump to address

doList push IP to return stack push IP to RS 1
copy first address to IP copy address to IP
calls Next Jump to Subroutine Next

Exit pop return stack to IP pop RS to IP 2
calls Next Jump to Subroutine Next

Bye exits forth final return to where invoked 3

?Rx reads character from input device test for character input 4
returns input char and true or false if there is no char return false
otherwise return char and true on stack

Tx! sens char on stack to output device send char to output 5

!Io Init IO device init io device 6

Execute execute code at address get address from stack and jump 7

doLit take the literal from inline code and put on stack read the number or text and push on stack 8

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

>R push stack to return stack 20

Drop discard the top of stack 21

Dup duplicate the top of stack 22

Swap Change the places of the top two stack items 23

Over copy the second stack item to the top of stack 24

SP@ push the current data stack pointer to top of stack 25

SP! push the address on stack to the data stack pointer 26

0< return true if negative 0 for positive, zero is positive 27

And bitwise And 28

Or bitwise inclusive Or 29

Xor bitwise Exclusive Or 30

UM+ adds two unsigned numbers on stack and returns sum and carry 31

size Forth Function Forth Function Classic Function Classic Function
1k temp stack data stack addressing registers data registers
1k flow stack r stack kernal stack app stack
1k core execute user execute kernal execute app execute
1k core vars user var kernal vars app vars
4k 1 2 3 4 on core 16k dual port sram on each core
8k core dictionary user dictionary kernal stack app stack
8k core page tables user page tables kernal page tables app page tables L1 64k cache on each core
4k 256 blocks L2 1M cache on each core
4k 4k blocks L3 16M cache on each core
4k 64k blocks SRAM 256M on each core
4k 1M blocks DRAM 4G common
4k 16M blocks Flash 64G common
4k 256T blocks Storage 1024P common

Notes Each core will have 16k dual port sram internally Words to be executed are taken into the 1k execute stages
Each core will have 64k L1 cache execute stages are fed from 4k virtual pages in the L2,L3, and SRAM on each core
Each core will have 1M L2 cache Cores can pull from a common pool of virtual pages from DRAM, Flash, and Storage
Each core will have 16M L3 cache Variables are handled in the same way by the virtual subsystem
Each core will have 256M on board Stack overflows are handled by virtual paging when the stack counter enters into the overflow condition
The overflow system then grabs a virtual page to put the overflow into as it puts the new variable on the stack
DRAM will be shared between all cores this will introduce a delay for the stack operations while the overflow condition exists
Flash will be shared between all cores core word lookups are performed with the L1 cache as well as the page table lookups
Storage will be shared between all cores when the dictionary gets too large it can also be virtualized
Virtual pages can be rotated out to slower forms when usage is not warranted for immediate use


