all: os.img

os.img: bootloader/boot.asm kernel/kernel.bin
	nasm -f bin bootloader/boot.asm -o boot.bin
	cat boot.bin kernel/kernel.bin > os.img

kernel/kernel.bin: kernel/kernel.o kernel/screen.o kernel/keyboard.o
	ld -m elf_i386 -o kernel/kernel.bin -T kernel/kernel.ld $^ --oformat binary

%.o: %.c
	gcc -m32 -ffreestanding -c $< -o $@

run: os.img
	qemu-system-i386 -fda os.img

clean:
	rm -f boot.bin os.img kernel/*.o kernel/kernel.bin
