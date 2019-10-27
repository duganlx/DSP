NAME main       
seg_1 SEGMENT CODE                  
           RSEG    seg_1            
TABLE:     DB      3,2,5,0x0ee  
seg_2 SEGMENT IDATA           
           RSEG    seg_2
BUFFER:    DS      19
seg_3 SEGMENT XDATA                 
           RSEG    seg_3
XBUFFER:   Ds      100      
                      
myprog SEGMENT CODE  
           RSEG    myprog  
		   USING 0
		   LJMP    main    
           org    0x100				   
main:      MOV     DPTR, #TABLE      ;access code segment 
           MOV     A,#03              
           MOVC    A,@A+DPTR         
		   MOV     P1,#0              
		   MOV     P1,A    
		   
		   MOV     R0,#BUFFER        ;access IDATA segment
           MOV     @R0,A
           INC     A		   
           INC     R0           
           MOV     @R0,A        
		   
           MOV     DPTR,#XBUFFER     ;access XDATA segment              
           INC     A
		   MOVX    @DPTR,A          
           INC      DPTR            
           CLR      A                 
           MOVX    @DPTR,A          
		   
END
