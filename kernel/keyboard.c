#include "keyboard.h"
#include "screen.h"
#include <stdint.h>

#define KEYBOARD_PORT 0x60

char key_buffer[256];
int buffer_index = 0;

char scancode_to_ascii[128] = {
    0, 27, '1','2','3','4','5','6','7','8','9','0','-','=','\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n', 0,
    'a','s','d','f','g','h','j','k','l',';','\'','`', 0,'\\',
    'z','x','c','v','b','n','m',',','.','/', 0, '*', 0,' ', 0
};

void keyboard_handler() {
    uint8_t scancode = inb(KEYBOARD_PORT);
    if (scancode < 128) {
        char c = scancode_to_ascii[scancode];
        if (c) {
            key_buffer[buffer_index++] = c;
            print_char(c);
            if (c == '\n') {
                key_buffer[buffer_index] = '\0';
                handle_command(key_buffer);
                buffer_index = 0;
            }
        }
    }
}
