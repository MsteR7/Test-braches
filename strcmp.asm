BITS 64
default rel

section .text
    global strcmp

;   strcmp() returns an integer indicating the result of the comparison, as follows :
;   0, s1 == s2
;   negative number, if s1 is less than s2
;   positive number, if s1 is greater than s2

strcmp:
    enter 0,0 ; prologue
    ; rdi ; string s1
    ; rsi; string s2
    mov rcx, 0 ; counter
.lp:
    mov r10b, [rdi + rcx] ; s1
    cmp r10b, 0
    je .end ; if equal : end of the loop
    mov r11b, [rsi + rcx] ; s2
    cmp r11b, 0
    je .end ; if equal : end of the loop
    cmp r10b, r11b
    jl .negative ; If r10 is less than r11
    jg .positive
    inc rcx ; increment the counter
    jmp .lp ;


.end:
    jmp .is_equal
    cmp r10b, r11b
    jl .negative
    jg .positive


.is_equal:
    cmp r10b, 0
    je .s1_finished
    cmp r11b, 0
    je .s2_finished


.s1_finished:
    inc rcx
    mov r11b, [rsi + rcx]
    cmp r10b, r11b
    je .same
    jmp .negative

.s2_finished:
    mov r10b, [rdi + rcx]
    cmp r11b, r10b
    je .same
    jmp .positive


.same:
    mov rax, 0
    jmp .done

.negative:
    mov rax, -1
    jmp .done

.positive:
    mov rax, 1
    jmp .done

.done:
    leave ; epilogue
    ret

;rdi, rsi, rdx, rcx, r8, r9 register for parameters

; use rdx, rcx, r8, r9, r10, r11 as general purposes
; rcs and r11 may be overwritten in system calls

; A revoir
