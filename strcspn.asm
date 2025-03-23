BITS 64

default rel

section .text
    global strcspn

strcspn:
    enter 0, 0
    mov rcx, 0
    mov r8, 0
.lp :
    mov r10b, byte [rdi + rcx]
    jmp .compare
.continue:
    cmp r10b, 0
    je .Not_Found
    inc r8
    inc rcx
    jmp .lp


.compare:
    mov r11, 0 ; counter for the second loop
.loop:
    mov dl, byte [rsi + r11] ; character from s2
    cmp r10b, dl ; found?
    je .done
    cmp dl, 0  ; end of s2 ?
    je .continue  ; continue for the other letters in s1
    inc r11
    jmp .loop


.Not_Found :
    mov rax, 0
    leave
    ret

.done :
    mov rax, r8
    leave
    ret