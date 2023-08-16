# dfcc: Dirt's Forth Chip Compiler

## Command-line usage

`dfcc inputFile outputFile`

* `inputfile`: The name/path of the file to be compiled
* `outputFile`: Where to put the compiled binary

For an example, see the Makefile

## TO-DO's

Get it to recognize numbers.  I'm pretty sure `doLit` is what I would call "push" - it pushes a number onto the stack.  I need to read up on this, but that is one thing I don't have yet.  In the Forths I've built, there's a token that precedes numbers to tell the interpreter, "this is a number".  If that is the case, then maybe "doLit" should not be a word in the first place.  What I mean is, if I compile `65535`, the compiled binary will have to do i.e. `08 FF FF`.  This also begs the question, are we talking about an 8-bit machine?  16-bit?  Again, this will take some research.  I mean, how high (and how low) will the range of allowed numbers go?

