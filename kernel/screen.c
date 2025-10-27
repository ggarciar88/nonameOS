#include "screen.h"
#include <stdint.h>

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

int cursor_offset = 0;

void print_char(char c) {
    volatile char* video = (char*) VIDEO_ADDRESS;
    video[cursor_offset] = c;
    video[cursor_offset + 1] = 0x07;
    cursor_offset += 2;
}

void print(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        print_char(str[i]);
    }
}

void clear_screen() {
    volatile char* video = (char*) VIDEO_ADDRESS;
    for (int i = 0; i < MAX_ROWS * MAX_COLS * 2; i += 2) {
        video[i] = ' ';
        video[i + 1] = 0x07;
    }
    cursor_offset = 0;
}
