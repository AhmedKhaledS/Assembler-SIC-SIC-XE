Prbn06   START   1000
         LDX     ZERO
         LDCH    BLANK
LOOP     STCH    STR,X
         TIX     K20
         JLT     LOOP
STR      BYTE    c'0123456789'
STR2     BYTE    c'0123456789666565656565'
BLANK    BYTE    c' '
BUFFER   RESB    90050
K20      WORD    20
ZERO     WORD    0
         END     Prbn06
