all: os.iso

bootloader.bin: bootloader/boot.asm
    nasm -f bin bootloader/boot.asm -o bootloader.bin

kernel.bin: kernel/kernel.c kernel/kernel.ld
    i686-elf-gcc -ffreestanding -c kernel/kernel.c -o kernel.o
    i686-elf-ld -T kernel/kernel.ld -o kernel.bin kernel.o

os.iso: bootloader.bin kernel.bin
    cat bootloader.bin kernel.bin > build/os.iso

clean:
    rm -f bootloader.bin kernel.o kernel.bin build/os.iso
