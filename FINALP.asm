.MODEL MEDIUM

PRINTF          MACRO   TXT                                             ; MACRO TO PRINT STRING
    LEA                 DX, TXT                                         ; LOAD THE STRING IN DX
    MOV                 AH, 09H                                         ; OUTPUT MODE FOR STRING
    INT                 21H                                             ; PRINT THE STRING
ENDM

SCANF           MACRO   NUMBER, LAB1, IS_ENTER, IS_NUM                  ; MACRO TO READ NUMBER

    MOV                 CX, 10                                          ; PUT 10 TO CX

    LAB1:
        MOV             AH, 01H                                         ; INPUT MODE
        INT             21H                                             ; READ THE CHAR

        CMP             AL, 0DH                                         ; CHECK IF IT'S AN ENTER
        JE              IS_ENTER         

        IS_NUM:                                                         ; MOST BE NUMBER (0-9)
        SUB             AL, 30H                                         ; CONVERT FROM ASCII TO HEX
        
        MOV             BL, AL                                          ; PUT THE DECIMAL NUMBER IN BL
        MOV             AX, NUMBER                                      ; PUT THE NUMBER IN AX

        MUL             CX                                              ; MULTIPLY THE NUMBER WITH 10 (TO SCAN FROM LEFT TO RIGHT)

        MOV             BH, 0

        ADD             AX, BX                                          ; ADD THE SCANNED NUMBER TO PREV NUMBER

        MOV             NUMBER, AX                                      ; PUT THE NEW NUMBER FROM AX

        JMP             LAB1                                            ; RE-SCAN NUMBER

        IS_ENTER:
        NOP                                                             ; NOTHING 
ENDM

.STACK 100H

.DATA        
    MSG_1               DB  "FIRST NUMBER: -$"
    MSG_2               DB  "SECOND NUMBER: -$"
    MSG_3               DB  "OPERATOR NUMBER", 13, 10, "[1:AND, 2:OR, 3:NOT, 4:XOR]: $"
    MSG_4               DB  "BINARY RESULT IS: $"

    NEWLINE_MSG         DB  13, 10, "$"

    NUM_1               DW  ?
    NUM_2               DW  ?
    OP_NUM              DW  ?

.CODE

    START:
        MOV             AX, @DATA                                       ; DS DATA
        MOV             DS, AX

        PRINTF          MSG_1                                           ; ASK FIRST NUMBER
        SCANF           NUM_1, L1, L2, NN1                              ; READ FIRST NUMBER

        ; OPERATION
        PRINTF          MSG_3                                           ; GET THE OPERATION
        SCANF           OP_NUM, L5, L6, NN2                             ; READ THE OPERATION NUMBER

        CMP             OP_NUM, 03H                                     ; IF OPERATION IS NOT 
        JE              NOT_OP                                          ; SKIP SCANNING SECOND NUMBER

        PRINTF          MSG_2                                           ; GET THE SECOND NUMBER
        SCANF           NUM_2, L3, L4, NN3                              ; READ THE SECOND NUMBER

        MOV             AX, NUM_1                                       ; PUT FIRST NUMBER IN AX

        CMP             OP_NUM, 01H                                     ; CHECK IF AND OPERATION
        JE              AND_OP
        CMP             OP_NUM, 02H                                     ; CHECK IF OR OPERATION
        JE              OR_OP
        CMP             OP_NUM, 04H                                     ; CHECK IF XOR OPERATION
        JE              XOR_OP

        AND_OP:                                                         ; AND SECOND NUMBER WITH FIRST NUMBER 
        AND             AX, NUM_2
        JMP             NEXT

        OR_OP:                                                          ; OR SECOND NUMBER WITH FIRST NUMBER 
        OR              AX, NUM_2
        JMP             NEXT

        NOT_OP:                                                         ; NOT THE FIRST NUMBER
        MOV             AX, NUM_1                                       ; PUT FIRST NUMBER IN AX
        NOT             AX
        JMP             NEXT

        XOR_OP:                                                         ; XOR SECOND NUMBER WITH FIRST NUMBER 
        XOR             AX, NUM_2
        JMP             NEXT

        NEXT: 
        MOV             BX, 0002H                                       ; PUT 2D IN BX
        MOV             CX, 0000H                                       ; ZERO CX

        PUT_IN_STACK:
        MOV             DX, 0000H                                       ; ZERO DX
        DIV             BX                                              ; DIVIDE BY 2, REMINDER IN DX
        PUSH            DX                                              ; PUSH DX (NUMBER) INTO STACK
        INC             CX                                              ; INCREMENT CX TO KNOW SIZE OF NUMBER (WILL BE USED LATER IN LOOP)

        CMP             CX, 32                                          ; LOOP UNTIL AX IS EMPTY, NUMBER OF BITS
        JNE             PUT_IN_STACK                                    ; IF NOT EMPTY, REPEAT
   
        
        
        PRINTF          MSG_4                                           ; PRINT THE RESULT
                
        DISPLAY_RESULT:
        POP             DX                                              ; GET THE MOST LEFT NUMBER FROM STACK

        ADD             DL, 30H                                         ; ADD 30H TO PRINT ASCII CHAR

        CMP             DL, 39H                                         ; IF THE CHAR IS < 39H (IS A NUMBER)
        JB              SKIP_ADDING                                     ; SKIP ADDING 07H (FOR CHAR FROM [A-F]H)

        ADD             DL, 07H                                         ; ADD 07H TO CONVERT IT TO LETTER [A-F]H

        
        SKIP_ADDING:                                                    ; EVENTUALLY IT WILL GET HERE TO PRINT THE CHAR WHATEVER IT IS
        
        MOV             AH, 02H                                         ; MODE OUTPUT FOR 1 CHAR
        INT             21H                                             ; PRINT THE CHAR
        LOOP            DISPLAY_RESULT                                  ; LOOP UNTIL CX IS ZERO (PREVIOUSLY SET)

        MOV             AX, 4C00H                                       ; RETURN TO OS
        INT             21H                                                         


    END START