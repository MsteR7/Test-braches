BITS 64
default rel

section .text
    global strncmp

strncmp:
    enter 0,0
    xor rcx, rcx               ; rcx = 0 (index)

.lp:
    cmp rdx, 0                  ; n = 0
    je .same

    cmp rcx, rdx               ; Have we reached max length?
    je .same                   ; If yes, return 0 (equal up to n chars)

    mov r10b, [rdi + rcx]      ; Load s1[i]
    mov r11b, [rsi + rcx]      ; Load s2[i]

    cmp r10b, 0                ; Check if s1[i] == '\0
    je .end

    cmp r10b, r11b             ; Compare characters
    jg .positive
    jl .negative


    inc rcx                    ; Move to next character
    jmp .lp                    ; Repeat loop

.end:
    cmp r10b, r11b
    je .same
    jg .positive
    jl .negative


.negative:
    mov rax, -1                ; Return -1 if s1 < s2
    jmp .done

.positive:
    mov rax, 1                 ; Return 1 if s1 > s2
    jmp .done

.same:
    xor rax, rax               ; Return 0 (strings are equal)
    jmp .done

.done:
    leave
    ret


;rdi => s1
;rsi => s2
;rdx => len