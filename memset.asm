BITS 64

default rel

section .text
    global memset

memset:
    enter 0,0
    mov rcx, 0
.lp:
    cmp rcx, rdx
    je .done
    mov byte [rdi + rcx], sil
    inc rcx
    jmp .lp



.done:
    mov rax, rdi
    leave
    ret

;rdi  l'adresse du bloc mémoire à ré-initialiser.
;rsi  valeur pour remplir
;rdx  le nombre d'octects