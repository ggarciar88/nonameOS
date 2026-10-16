#include "../include/screen.h"

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80
#define WHITE_ON_BLACK 0x0f

void clear_screen() {
    char* vidmem = (char*) VIDEO_ADDRESS;
    for (int i = 0; i < MAX_ROWS * MAX_COLS * 2; i += 2) {
        vidmem[i] = ' ';
        vidmem[i+1] = WHITE_ON_BLACK;
    }
}

void print(char* message) {
    char* vidmem = (char*) VIDEO_ADDRESS;
    int i = 0;
    while (message[i] != 0) {
        vidmem[i*2] = message[i];
        vidmem[i*2+1] = WHITE_ON_BLACK;
        i++;
    }
}
