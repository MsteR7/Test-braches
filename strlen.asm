BITS 64
default rel

section .text
    ;export strlen
    global strlen

strlen:
    enter 0,0
    mov rcx, 0 ;counter
.lp:
    ; The BYTE define a byte
    ; IN this case 1 byte
    cmp byte [rdi + rcx], 0 ; deference rdi who contains the string ans compare to the null terminator
    je .done ; if equal : end of the loop
    inc rcx ; increment the counter
    jmp .lp ; if not equal : verift the next caracter of the string
.done:
    mov rax, rcx ; the return value is equal to the loop counter
    leave
    ret ; RETURN
