```text
                             _           ___   ___  
                            (_)         / _ \ / _ \   not©          not©          not©          not©          not©          not©          not©          not©          not©
   __ _ __ _ __ _ _ __ ___ _ __ _ _  __| (_) | (_) |       not©          not©          not©          not©          not©          not©          not©          not©          not©    
  / _` |/ _` |/ _` | '__/ __| |/ _` |   > _ < > _ <              not©          not©          not©          not©          not©          not©          not©          not©          not©     
 | (_| | (_| | (_| | |  ( __| | (_| | || (_) | (_) |
  \__, |\__, |\__,_|_|\_ ___|_|\__,_|_| \___/ \___/                 
   __/ | __/ |                                       
  |___/ |___/                                        
     

@ggarciar88  //  nonameOS
____________________________________________________________________________________________________________________________________________________________________________________________________________________
# nonameOS project
____________________________________________________________________________________________________________________________________________________________________________________________________________________

nonameOS is a bare-metal operating system written in C and x86 Assembly. It boots from a custom bootloader, initializes hardware, and provides a basic shell interface for user interaction.

##  Features

- Custom bootloader in 16-bit assembly
- Freestanding kernel in C
- Direct video memory output
- Keyboard input via IRQ1
- Command-line shell with basic commands
- Modular architecture for future expansion

##  Folder Structure

##  Build Instructions

To compile and run nonameOS using QEMU:
  make
  qemu-system-i386 -fda build/os.iso

##  Shell Commands
  help — List available commands
  clear — Clear the screen
  echo <text> — Print text to screen 

##  Requirements:
  nasm - assembler for bootloader
  i686-elf-gcc — Cross-compiler for kernel
  qemu — Emulator for testing

##  Future Goals:
  Interrupt Descriptor Table (IDT)
  Paging and memory management
  File system support (FAT12 or custom)
  Multitasking and process scheduling
  Graphical interface (VGA mode)

##  License:
  This project is released under the MIT License.




```bash
make
qemu-system-i386 -fda build/os.iso
