# dfcc: Dirt's Forth Chip Compiler

## Command-line usage

`dfcc inputFile outputFile`

* `inputfile`: The name/path of the file to be compiled
* `outputFile`: Where to put the compiled binary

For an example, see the Makefile

## TO-DO's

Get it to recognize numbers.  I'm pretty sure `doLit` is what I would call "push" - it pushes a number onto the stack.  I need to read up on this, but that is one thing I don't have yet.  In the Forths I've built, there's a token that precedes numbers to tell the interpreter, "this is a number".  If that is the case, then maybe "doLit" should not be a word in the first place.  What I mean is, if I compile `65535`, the compiled binary will have to do i.e. `08 FF FF`.  This also begs the question, are we talking about an 8-bit machine?  16-bit?  Again, this will take some research.  I mean, how high (and how low) will the range of allowed numbers go?




----------------------------------------------------------------------------

## Notes

### Re: `doLit`

To reformat Dirt's notes:

word:		doLit
Function:	Take the literal from inline code and put on stack
Steps:		Read the number or text and push on stack
ASCII code:	8

This seems to suggest that doLit should take not only numbers, but text.  So what would text look like?  I mean okay, I know about `."` and `S"` in Forth - they're pretty important.  But since those words are not on the list, I might need to look at the Forth standard, or at least the "eForth" he was telling me about, to figure out how it's really supposed to work.  It would be easy enough to have my compiler recognize stuff like:

```
doLit 12345
doLit "String literal"
```

And if I really wanted to get fancy, I could have it add the `doLit` without the end-user even having to type it - when it sees a number or a string, just compile the `doLit` followed by the number/string.


----------------------------------------------------------------------------

## The rest of Dirt's notes

These are mainly for the sake of the VM at this point.

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


