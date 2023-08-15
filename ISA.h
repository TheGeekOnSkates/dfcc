#ifndef _ISA_H
#define _ISA_H

/**
 * The first 31 instructions are the instruction set in "Forth mode".
 * The high bit, bit 7 (which would add 128 to each of these) tells the
 * CPU to work in "classic mode" (which has not been defined yet, but I
 * expect will work more like other CPUs, load/store/call/return/etc.).
 * I could be way off on that.  But for now, we got #FORTH! :)
 */
enum {
	NEXT,				// 0. next
	DOLIST,				// 1. doList
	EXIT,				// 2. exit
	BYE,				// 3. bye
	QUESTION_RX,		// 4. ?rx
	TX_BANG,			// 5. tx!
	BANG_IO,			// 6. !io
	EXECUTE,			// 7. execute
	DOLIT,				// 8. doLit
	NEXTLOOP,			// 9. nextLoop
	QUESTION_BRANCH,	// 10. ?branch
	BRANCH,				// 11. branch
	STORE,				// 12. !
	FETCH,				// 13. @
	CSTORE,				// 14. c!
	CFETCH,				// 15. c@
	RP_FETCH,			// 16. rp@
	RP_STORE,			// 17. rp!
	R_FROM,				// 18. r>
	R_FETCH,			// 19. r@
	TO_R,				// 20. >r
	DROP,				// 21. drop
	DUP,				// 22. dup
	SWAP,				// 23. swap
	OVER,				// 24. over
	SP_FETCH,			// 25. sp@
	SP_STORE,			// 26. sp!
	COMPARE,			// 27. 0<
	AND,				// 28. and
	OR,					// 29. or
	XOR,				// 30. xor
	UM_ADD,				// 31. um+
};

#endif

