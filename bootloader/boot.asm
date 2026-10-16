[org 0x7c00]
KERNEL_LOCATION equ 0x1000

    mov [BOOT_DISK], dl
    mov bp, 0x9000
    mov sp, bp

    call load_kernel
    call switch_to_pm
    jmp $

%include "bootloader/disk.asm"
%include "bootloader/gdt.asm"
%include "bootloader/32bit_switch.asm"

[bits 16]
load_kernel:
    mov bx, KERNEL_LOCATION
    mov dh, 2
    mov dl, [BOOT_DISK]
    call disk_load
    ret

[bits 32]
BEGIN_PM:
    call KERNEL_LOCATION
    jmp $

BOOT_DISK db 0

times 510-($-$$) db 0
dw 0xaa55
