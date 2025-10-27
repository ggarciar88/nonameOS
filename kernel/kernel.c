#include "screen.h"
#include "keyboard.h"

void handle_command(const char* input) {
    if (strcmp(input, "help\n") == 0) {
        print("\nAvailable commands:\nhelp\nclear\necho\n");
    } else if (strcmp(input, "clear\n") == 0) {
        clear_screen();
    } else if (strncmp(input, "echo ", 5) == 0) {
        print("\n");
        print(input + 5);
    } else {
        print("\nUnknown command\n");
    }
}

void main() {
    clear_screen();
    print("nonameOS Shell\n> ");
    while (1);
}
