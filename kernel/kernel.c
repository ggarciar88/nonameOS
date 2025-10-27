void main() {
    const char* message = "Hello from nonameOS kernel!";
    char* video_memory = (char*)0xb8000;

    for (int i = 0; message[i] != '\0'; ++i) {
        video_memory[i * 2] = message[i];
        video_memory[i * 2 + 1] = 0x07; // Light grey on black
    }

    while (1); // Halt
}
