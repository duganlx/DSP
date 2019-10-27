   ORG 	0000H
		LJMP 	Main
		
		ORG 	00F0H
Main:   
		MOV     P2,#0F0H
Next:	MOV 	R7, #250 
Loop: 
		MOV 	R6, #240
		DJNZ 	R6, $
		MOV 	R6, #240
		DJNZ 	R6, $
		MOV 	R6, #240
		DJNZ 	R6, $
		MOV 	R6, #240
		DJNZ 	R6, $
		DJNZ 	R7, Loop  ;
		CPL 	P2.0 	; P 2 .0È¡·´
		CPL 	P2.1 	; P 2 .0 
		CPL 	P2.2 	; P 2 .0 
		CPL 	P2.3 	; P 2 .0 
		CPL 	P2.4 	; P 2 .0 
		CPL 	P2.5 	; P 2 .0 
		CPL 	P2.6	; P 2 .0 
		CPL 	P2.7 	; P 2 .0
		SJMP 	Next
		END