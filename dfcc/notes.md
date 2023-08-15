# The ISA, modded from a post on Dirt's locals (computerdesign.locals.com)

Word:			next
Function:		Fetch word in IP
Steps:
	Fetch address in IP to Jump Table
	Increase IP (by 1)
	Jump to IP
Ascii code:		0

Word:			doList 
Function:		Push IP to return stack
Steps:		
	Push IP to RS
	Copy first address to IP copy address to IP
	Calls Next (Jump to Subroutine Next)
Ascii code:		1

