\ I'm still working on doLit, so here's an example of how it _might_ work.
\ I'll be showing what the stack would be in a traditional Forth
\ Words tested: and or xor drop dup swap over 0< {numbers, doLit}, bye

5 2				\ <2> 5 2
or				\ <1> 7
dup				\ <2> 7 7
0<				\ <1> 0
99 swap	over	\ <3> 99 0 99
3 and			\ <3> 99 0 3
swap drop		\ <1> 99 3
xor				\ <1> 96
-1 0<			\ <2> 96 -1
305419896		\ <3> 96 -1 305419896 (a.k.a. 0x12345678, so I can check big
				\ numbers in the binary
bye				\ Again, what would "bye" do in a CPU?  Exit Forth and go...
				\ where exactly? :)
