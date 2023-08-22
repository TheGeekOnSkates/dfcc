\ Test 1: Just compile all 32 Forth mode instructions, one at a time.
\ This would obviously throw an error in a Forth REPL, who knows what it
\ would do to a CPU (lol), but it's the simplest test we can possibly do.

\ These are the Forth Mode words
next doList exit bye
?rx tx! !io execute
doLit nextLoop ?branch branch
! @ c! c@ rp@ rp! r> r@ >r
drop dup swap over sp@ sp! 0<
and or xor um+

\ And these are the Classic Mode words... at least, for now :)
\ I say that becuase (a) a bunch of them are reserved, and
\ (b) we might decide later that a different syntax is better
load_imm load_reg load_idx load_spec
store_imm store_reg store_idx store_spec
add_imm add_reg add_idx add_spec
sub_imm sub_reg sub_idx sub_spec
mult_imm mult_reg mult_idx mult_spec
div_imm div_reg div_idx div_spec
and_imm and_reg and_idx and_spec
or_imm or_reg or_idx or_spec
xor_imm xor_reg xor_idx xor_spec
not_imm not_reg not_idx not_spec
jump_imm jump_reg jump_idx jump_spec
branch_imm branch_reg branch_idx branch_spec
