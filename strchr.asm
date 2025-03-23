BITS 64
default rel

section .text
    global strchr

strchr:
    enter 0, 0
    mov rcx, 0
.lp:
    cmp byte [rdi + rcx], 0
    je .end
    cmp byte [rdi + rcx], sil
    je .found
    inc rcx
    jmp .lp

.done:
    leave
    ret

.end:
    cmp sil, 0
    je .found
    xor rax, rax
    jmp .done

.found:
    lea rax, [rdi + rcx] ; The address into rax
    jmp .done


; an "INT" is passed buf if multiple char are passed it takes the last one