[bits 16]
[org 0x7c00]

start:
    mov ah, 0x0E
    mov si, message

print_loop:
    lodsb
    cmp al, 0
    je done
    int 0x10
    jmp print_loop

done:
    jmp $

message db "Booting MicroOS...", 0

times 510 - ($ - $$) db 0
dw 0xAA55
