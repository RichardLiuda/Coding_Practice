.ORIG	x3000
    JSR DISPLAYBOARD
PROMPT
    LD  R6, ROUND
    ADD R6, R6, #1;player1
    ST  R6, ROUND
NOADDROUND
    AND R0, R0, #0
    AND R1, R1, #0
    AND R2, R2, #0
    AND R3, R3, #0
    AND R4, R4, #0
    AND R5, R5, #0
    AND R6, R6, #0
    AND R7, R7, #0
    ST  R3, GETSCORE
    JSR DISPLAYPROMPT
    JSR GETROW
    LD R1, ROW
    JSR JUDGEQUIT
    JSR GETLINE
    LD R2, LINE
    JSR IS_INPUT_VALID;include IS_OCCUPIE judgement
    ADD	R3, R3, #0
    BRnp NOADDROUND
    ;JSR TRANSLATE_MOVE
    JSR APPLY_MOVE
    JSR UPDATE_STATE
    JSR DISPLAYBOARD
    JSR CHECK_OVER
    ADD R3, R3, #0
    BRz QUIT
    LD R3, GETSCORE
    BRp NOADDROUND
    BRnzp PROMPT

QUIT
    HALT


DISPLAYBOARD
    ST R7, SAVE_R7
    LEA R0,  BOARDADDR
    LDR R0, R0, #0
    PUTS
    ADD R0, R0, #11
    PUTS
    ADD R0, R0, #11
    PUTS
    ADD R0, R0, #11
    PUTS
    ADD R0, R0, #11
    PUTS
    ADD R0, R0, #11
    PUTS
    ADD R0, R0, #11
    PUTS
    ADD R0, R0, #11
    PUTS
    LD R7, SAVE_R7
    RET
    
DISPLAYPROMPT
    ST R6, SAVE_R6 
    ST R0, SAVE_R0
    ST R7, SAVE_R7
    LEA R0, PROMPT1ADDR
    LDR R0, R0, #0
    PUTS
    LD  R6, ROUND
    AND R6, R6, #1;if player2
    BRz DISPLAYPLAYER2
DISPLAYPLAYER1
    LEA R0, PLAYER1
    PUTS
    BRnzp DISPLAYPROMPT2
DISPLAYPLAYER2
    LEA	R0,	PLAYER2
    PUTS
DISPLAYPROMPT2
    LEA R0, PROMPT2ADDR
    LDR R0, R0, #0
    PUTS
    LD R6, SAVE_R6
    LD R0, SAVE_R0
    LD R7, SAVE_R7
    RET

GETROW
    ST R7, SAVE_R7
    ST R0, SAVE_R0
    ST R1, SAVE_R1
    IN
    LD R1, Q_ASCII
    NOT R1, R1
    ADD R1, R1, #1
    ADD R1, R0, R1
    BRz QUIT
    ST R0, ROW
    LD R1, SAVE_R1
    LD R0, SAVE_R0
    LD R7, SAVE_R7
    RET

GETLINE
    ST R7, SAVE_R7
    ST R0, SAVE_R0
    IN
    ST R0, LINE
    LD R0, SAVE_R0
    LD R7, SAVE_R7
    RET

JUDGEQUIT
    ST  R7, SAVE_R7
    ST  R4, SAVE_R4
    ST  R5, SAVE_R5
    LD  R4, Q_ASCII
    NOT R4, R4
    ADD R4, R4, #1
    ADD R5, R4, R1
    BRz QUIT
    LD  R7, SAVE_R7
    LD  R4, SAVE_R4
    LD  R5, SAVE_R5
    RET
    
IS_INPUT_VALID
    ST R5, SAVE_R5
    ST R6, SAVE_R6
    ST R7, SAVE_R7

    AND R0, R0, #0
    ADD R0, R2, R0;R0 is between '0' and '6'
    LD  R4, ZERO_ASCII
    NOT R4, R4
    ADD R4, R4, #1
    ADD R4, R0, R4
    BRn INVALID
    LD  R4, SIX_ASCII
    NOT R4, R4
    ADD R4, R4, #0
    ADD R4, R0, R4
    BRp INVALID
    LD  R4, A_ASCII
    NOT R4, R4
    ADD R4, R4, #1
    ADD R4, R1, R4
    BRn INVALID
    LD  R4, G_ASCII
    NOT R4, R4
    ADD R4, R4, #1
    ADD R4, R1, R4
    BRp INVALID
    ;judge if the position is empty
    LEA R6, MAPADDR
    LDR R6, R6, #0
    JSR TRANSMAP
    LDR	R6,	R6,	#0
    LD  R5, SPACE_ASCII
    NOT R5, R5
    ADD R5, R5, #1
    ADD R5, R5, R6
    BRnp INVALID

    LD R5, SAVE_R5
    LD R6, SAVE_R6
    LD R7, SAVE_R7
    AND R3, R3, #0
    RET
INVALID
    AND R3, R3, #0
    ADD R3, R3, #-1
    LD R4, SAVE_R4
    LD R5, SAVE_R5
    LD R6, SAVE_R6
    LD R7, SAVE_R7
    RET

TRANSMAP
    AND R3, R3, #0
    AND R4, R4, #0
    AND R5, R5, #0
    LD  R5, ALP_TO_MAP
    ADD R3, R1, R5;x
    ST  R3, SAVEX
    ADD R3, R3, #13
    ADD R6, R6, R3
    LD  R5, NUM_TO_MAP
    ADD R4, R0, R5;y
    ST  R4, SAVEY
    AND R2, R2, R4;cnt
    BRz LOOPFIN
TRANSMAP_LOOP
    ADD R6, R6, #11
    ADD R2, R2, #-1
    BRp TRANSMAP_LOOP
LOOPFIN
    RET


PROMPT1ADDR .FILL	PROMPT1
PROMPT2ADDR .FILL	PROMPT2
ROUND .FILL #0
PLAYER1 .STRINGZ	"1"
PLAYER2 .STRINGZ	"2"
PL1SCORE .FILL	#0
CHAR0 .FILL	#46
CHAR1 .FILL	#0
PL2SCORE .FILL	#0
CHAR2 .FILL	#46
CHAR3 .FILL	#0
GETSCORE .FILL 	#0
SAVE_R0   .BLKW	1
SAVE_R1   .BLKW	1
SAVE_R2   .BLKW	1
SAVE_R3   .BLKW	1
SAVE_R4   .BLKW	1
SAVE_R5   .BLKW	1
SAVE_R6   .BLKW	1
SAVE_R7   .BLKW	1
SAVE_R71   .BLKW	1
ROW     .BLKW	1
LINE    .BLKW	1
Q_ASCII .FILL	#81
ZERO_ASCII    .FILL	#48
SIX_ASCII     .FILL	#54
A_ASCII .FILL	#65
G_ASCII .FILL	#71
SPACE_ASCII .FILL	#32
HY_ASCII    .FILL	#45
PIPE_ASCII  .FILL	#124
ALP_TO_MAP  .FILL	#-65
NUM_TO_MAP  .FILL	#-48
MAPADDR .FILL	MAPL
BOARDADDR .FILL	BOARDL
SAVEX   .BLKW	1
SAVEY   .BLKW	1

; TRANSLATE_MOVE
;     ;x pos in R3 has been translated in IS_INPUT_VALID
;     ;just translate y pos in R1
;     ST  R5, SAVE_R5
;     AND R0, R0, #0
;     ADD R0, R0, R3;x
;     AND R1, R1, #0
;     LD  R5, ALP_TO_MAP
;     ADD R1, R1, R5;y
;     LD  R5, SAVE_R5
;     RET

APPLY_MOVE
    ST  R7, SAVE_R7
    LD  R0, SAVEX
    LD  R1, SAVEY
    LEA R3, BOARDADDR
    LDR  R3, R3, #0
    LEA R4, MAPADDR
    LDR  R4, R4, #0
    ADD R3, R3, #13
    ADD R4, R4, #13
    ADD R5, R1, #0;cnt
    BRz AMLOOPFIN
MOVE_LOOP
    ADD R3, R3, #11
    ADD R4, R4, #11
    ADD R5, R5, #-1
    BRp MOVE_LOOP
AMLOOPFIN
    ADD R3, R3, R0
    ADD R4, R4, R0;GET_ADDRESS
    ; LEA  R0, BOARDADDR
    ; LDR  R0, R0, #0
    ; NOT R0, R0
    ; ADD R0, R0, #1
    ; ADD R5, R3, R0
    LD  R5, SAVEY
    AND R5, R5, #1;judge odd
    BRp ODD
    LD  R6, HY_ASCII
    BRnzp   FILL_BOX
ODD LD  R6, PIPE_ASCII
FILL_BOX
    STR R6, R3, #0
    STR R6, R4, #0
    LD  R7, SAVE_R7
    RET

UPDATE_STATE
    ST  R7, SAVE_R7
    AND R5, R5, #0
    AND R6, R6, #0
    LD  R5, HY_ASCII
    LD  R6, PIPE_ASCII
    NOT R5, R5
    ADD R5, R5, #1
    NOT R6, R6
    ADD R6, R6, #1
    ADD R0, R3, #0
    ; AND R4, R4, #0;CNT
JUDGE_ODD
    ; LEA  R1, BOARDADDR
    ; LDR  R1, R1, #0
    ; NOT R1, R1
    ; ADD R1, R1, #1
    ; ADD R5, R3, R1
    LD  R3, SAVEY
    AND R3, R3, #1
    BRz UP_EVEN
UP_ODD
    AND R3, R3, #0
    JSR CHECKL
    JSR CHECKR
    ADD R3, R3, #0
    BRp SETFLAG
    LD  R7, SAVE_R7
    BRnzp CONTINUE
UP_EVEN
    AND R3, R3, #0
    JSR CHECKU
    JSR CHECKD
    ADD R3, R3, #0
    BRp SETFLAG
    LD  R7, SAVE_R7
    BRnzp CONTINUE

SETFLAG
    AND R3, R3, #0
    ADD R3, R3, #1
    ST  R3, GETSCORE
    LD  R7, SAVE_R7
    BRnzp CONTINUE

CHECKD
    ST  R7, SAVE_R71
    LD  R1, SAVEY
    ADD R1, R1, #-6
    BRzp CONTINUE
    LDR R2, R0, #10
    ADD R2, R2, R6
    BRnp CONTINUE
    LDR R2, R0, #12
    ADD	R2,	R2,	R6
    BRnp CONTINUE
    ADD R2, R0, #11
    LDR R2, R2, #11
    ADD R2, R2, R5
    BRnp CONTINUE
    JSR ADDCNT
    LD  R7, SAVE_R71
    BRnzp CONTINUE

CHECKU
    ST  R7, SAVE_R71
    LD  R1, SAVEY
    BRnz CONTINUE
    LDR R2, R0, #-12
    ADD R2, R2, R6
    BRnp CONTINUE
    LDR R2, R0, #-10
    ADD	R2,	R2,	R6
    BRnp CONTINUE
    ADD R2, R0, #-11
    LDR R2, R2, #-11
    ADD R2, R2, R5
    BRnp CONTINUE
    JSR ADDCNT
    LD  R7, SAVE_R71
    BRnzp CONTINUE

CHECKR
    ST  R7, SAVE_R71
    LD  R1, SAVEX
    ADD R1, R1, #-6
    BRzp CONTINUE
    LDR R2, R0, #-10
    ADD R2, R2, R5
    BRnp CONTINUE
    LDR R2, R0, #2
    ADD	R2,	R2,	R6
    BRnp CONTINUE
    LDR R2, R0, #12
    ADD R2, R2, R5
    BRnp CONTINUE
    JSR ADDCNT
    LD  R7, SAVE_R71
    BRnzp CONTINUE

CHECKL
    ST  R7, SAVE_R71
    LD  R1, SAVEX
    BRnz CONTINUE
    LDR R2, R0, #-12
    ADD R2, R2, R5
    BRnp CONTINUE
    LDR R2, R0, #-2
    ADD	R2,	R2,	R6
    BRnp CONTINUE
    LDR R2, R0, #10
    ADD R2, R2, R5
    BRnp CONTINUE
    JSR ADDCNT
    LD  R7, SAVE_R71
    BRnzp CONTINUE

CONTINUE
    RET

ADDCNT
    ADD R3, R3, #1
    LD  R1, ROUND
    AND R1, R1, #1
    BRz ADDPL2
ADDPL1
    LD  R1, PL1SCORE
    ADD R1, R1, #1
    ST  R1, PL1SCORE
    RET
ADDPL2
    LD  R1, PL2SCORE
    ADD R1, R1, #1
    ST  R1, PL2SCORE
    RET

CHECK_OVER
    LD  R1, PL1SCORE
    LD  R2, PL2SCORE
    AND R3, R3, #0
    ADD R3, R3, #1
    ADD R4, R2, R1
    ADD R4, R4, #-9
    BRn CONTINUE
DISPLAYWINNER
    NOT R2, R2
    ADD R2, R2, #1
    ADD R3, R1, R2
    BRn PL2WIN
PL1WIN
    LEA  R0, PL1WINPROMPT
    PUTS
    BRnzp PRINTSCORE
PL2WIN
    LEA  R0, PL2WINPROMPT
    PUTS
PRINTSCORE
    LEA  R0, SCOREPROMPT1
    PUTS
    LD  R0, PL1SCORE
    LD  R1, ZERO_ASCII
    ADD R0, R1, R0
    ; PUTCHAR
    ST  R0, PL1SCORE
    LEA R0, PL1SCORE
    PUTS
    LEA  R0, SCOREPROMPT2
    PUTS
    LD  R0, PL2SCORE
    LD  R1, ZERO_ASCII
    ADD R0, R1, R0
    ; PUTCHAR
    ST  R0, PL2SCORE
    LEA R0, PL2SCORE
    PUTS
    AND R3, R3, #0
    HALT


PROMPT1 .STRINGZ	"Player "
PROMPT2 .STRINGZ	",  input a move  (or 'Q' to quit):"
PL1WINPROMPT .STRINGZ	"Game over. Player 1 is the winner!"
PL2WINPROMPT .STRINGZ	"Game over. Player 2 is the winner!"
SCOREPROMPT1 .STRINGZ	"Player 1's score is "
SCOREPROMPT2 .STRINGZ	"Player 2's score is "
                      ;0123456
BOARDL  .STRINGZ	"  ABCDEFG\n"
BOARD0  .STRINGZ	"0 *-*-*-*\n"
BOARD1  .STRINGZ	"1 |      \n"
BOARD2  .STRINGZ	"2 *-*-*-*\n"
BOARD3  .STRINGZ	"3 |      \n"
BOARD4  .STRINGZ	"4 *-*-*-*\n"
BOARD5  .STRINGZ	"5 |      \n"
BOARD6  .STRINGZ	"6 *-*-*-*\n"

MAPL  .STRINGZ	"xxABCDEFG\n"
MAP0  .STRINGZ	"0x*-*-*-*\n"
MAP1  .STRINGZ	"1x|x x x \n"
MAP2  .STRINGZ	"2x*-*-*-*\n"
MAP3  .STRINGZ	"3x|x x x \n"
MAP4  .STRINGZ	"4x*-*-*-*\n"
MAP5  .STRINGZ	"5x|x x x \n"
MAP6  .STRINGZ	"6x*-*-*-*\n"
.END