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
	NEXT = 128,			// 128. next
	DOLIST,				// 129. doList
	EXIT,				// 130. exit
	BYE,				// 131. bye
	QUESTION_RX,		// 132. ?rx
	TX_BANG,			// 133. tx!
	BANG_IO,			// 134. !io
	EXECUTE,			// 135. execute
	DOLIT,				// 136. doLit
	NEXTLOOP,			// 137. nextLoop
	QUESTION_BRANCH,	// 138. ?branch
	BRANCH,				// 139. branch
	STORE,				// 140. !
	FETCH,				// 141. @
	CSTORE,				// 142. c!
	CFETCH,				// 143. c@
	RP_FETCH,			// 144. rp@
	RP_STORE,			// 145. rp!
	R_FROM,				// 146. r>
	R_FETCH,			// 147. r@
	TO_R,				// 148. >r
	DROP,				// 149. drop
	DUP,				// 150. dup
	SWAP,				// 151. swap
	OVER,				// 152. over
	SP_FETCH,			// 153. sp@
	SP_STORE,			// 154. sp!
	COMPARE,			// 155. 0<
	AND,				// 156. and
	OR,					// 157. or
	XOR,				// 158. xor
	UM_ADD,				// 159. um+
	LOAD_IMM,			// 160. load imm
	LOAD_REG,			// 161. Load Reg
	LOAD_IDX,			// 162. Load Idx
	LOAD_SPEC,			// 163. Load Spec
	// 164-175 are reserved
	STORE_IMM = 176,	// 176. STORE Imm
	STORE_REG,			// 177. STORE Reg
	STORE_IDX,			// 178. STORE Idx
	STORE_SPEC,			// 179. STORE Spec
	// 180-191 are reserved
	AND_IMM = 192,		// 192. AND Imm
	AND_REG,			// 193. AND Reg
	AND_IDX,			// 194. AND Idx
	AND_SPEC,			// 195. AND Spec
	OR_IMM,				// 196. OR Imm
	OR_REG,				// 197. OR Reg
	OR_IDX,				// 198. OR Idx
	OR_SPEC,			// 199. OR Spec
	NOT_IMM,			// 200. NOT Imm
	NOT_REG,			// 201. NOT Reg
	NOT_IDX,			// 202. NOT Idx
	NOT_SPEC,			// 203. NOT Spec
	XOR_IMM,			// 204. XOR Imm
	XOR_REG,			// 205. XOR Reg
	XOR_IDX,			// 206. XOR Idx
	XOR_SPEC,			// 207. XOR Spec
	ADD_IMM,			// 208. ADD Imm
	ADD_REG,			// 209. ADD Reg
	ADD_IDX,			// 210. ADD Idx
	ADD_SPEC,			// 211. ADD Spec
	SUB_IMM,			// 212. SUB Imm
	SUB_REG,			// 213. SUB Reg
	SUB_IDX,			// 214. SUB Idx
	SUB_SPEC,			// 215. SUB Spec
	MULT_IMM,			// 216. MULT Imm
	MULT_REG,			// 217. MULT Reg
	MULT_IDX,			// 218. MULT Idx
	MULT_SPEC,			// 219. MULT Spec
	DIV_IMM,			// 220. DIV Imm
	DIV_REG,			// 221. DIV Reg
	DIV_IDX,			// 222. DIV Idx
	DIV_SPEC,			// 223. DIV Spec
	JUMP_IMM,			// 224. JUMP Imm
	JUMP_REG,			// 225. JUMP Reg
	JUMP_IDX,			// 226. JUMP Idx
	JUMP_SPEC,			// 227. JUMP Spec
	// 228-239 are reserved
	BRANCH_IMM = 240,	// 240. BRANCH Imm
	BRANCH_REG,			// 241. BRANCH Reg
	BRANCH_IDX,			// 242. BRANCH Idx
	BRANCH_SPEC,		// 243. BRANCH Spec
	// 244-254 are reserved
	NOP
};

#endif

