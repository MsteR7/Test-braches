BITS 64
default rel

section .text
    global strrchr

strrchr:
    enter 0, 0
    mov rcx, 0
    xor r10, r10
.lp:
    cmp byte [rdi + rcx], 0
    je .end
    cmp byte [rdi + rcx], sil
    je .set
.continue:
    inc rcx
    jmp .lp


.set:
    lea r10, [rdi + rcx] ; Save the adress
    jmp .continue

.done:
    leave
    ret

.found:
    mov rax, r10
    jmp .done

.not_found:
    xor rax, rax
    jmp .done

.special:
    lea r10, [rdi + rcx]
    jmp .found

.end:
    cmp sil, 0
    je .special
    cmp r10, 0
    je .not_found
    jne .found
