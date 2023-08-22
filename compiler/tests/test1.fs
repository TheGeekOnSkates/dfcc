\ Test 1: Just compile all 32 Forth mode instructions, one at a time.
\ This would obviously throw an error in a Forth REPL, who knows what it
\ would do to a CPU (lol), but it's the simplest test we can possibly do.

next doList exit bye
?rx tx! !io execute
doLit nextLoop ?branch branch
! @ c! c@ rp@ rp! r> r@ >r
drop dup swap over sp@ sp! 0<
and or xor um+
