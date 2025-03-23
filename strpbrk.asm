BITS 64

default rel

section .text
    global strpbrk

strpbrk:
    enter 0, 0
    mov rcx, 0
.lp :
    mov r10b, byte [rdi + rcx]
    jmp .compare
.continue:
    cmp r10b, 0
    je .Not_Found
    inc rcx
    jmp .lp


.compare:
    mov r11, 0
.loop:
    mov dl, byte [rsi + r11] ; character from s2
    cmp r10b, dl ; found?
    je .done
    cmp dl, 0  ; end of s2 ?
    je .continue  ; continue for the other letters in s1
    inc r11
    jmp .loop


.Not_Found :
    xor rax, rax
    leave
    ret

.done :
    lea rax, [rdi + rcx]
    leave
    ret