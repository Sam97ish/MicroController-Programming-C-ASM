;
; AssemblerApplication1.asm
;
; Created: 9/29/2020 6:57:58 PM
; Author : Lenovo
;


; Replace with your application code
start:
    LDI r18,0x01 //a
	LDI r19,0x01 //b
	LDI r20,0x01 //c
	LDI r21,0x01 //d
	LDI r22,0xff //used for output later.
	ADD r18,r19 //adding the values in the registers and storing them in a
	SUB r18,r20 //subtracting ...
	ADD r18,r21 // ...
	INC r18 // incrementing a by 1.
	out DDRB,r22 //setting the data dirction of all pins of PORTB to output.
	out portb,r18 //outputting a into portb pins.
    rjmp start
	//we're using LDI because we're loading in a direct value and not an adress (pointer).