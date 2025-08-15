#include <stdio.h>
#include <string.h>
#include <unistd.h> // za usleep()

#define DISPLAY_ROWS 5
#define DISPLAY_COLS 20

void clearScreen() {
    printf("\033[H\033[J"); // ANSI kod za čišćenje terminala
}

void printDisplay(char display[DISPLAY_ROWS][DISPLAY_COLS + 1]) {
    for (int i = 0; i < DISPLAY_ROWS; i++) {
        printf("%s\n", display[i]);
    }
}

int main() {
    char display[DISPLAY_ROWS][DISPLAY_COLS + 1];

    // Inicijalno prazno
    for (int i = 0; i < DISPLAY_ROWS; i++) {
        memset(display[i], ' ', DISPLAY_COLS);
        display[i][DISPLAY_COLS] = '\0';
    }

    char message[] = "Hello from fixed display!   ";
    int msgLen = strlen(message);
    int offset = 0;

    while (1) {
        // Pomakni tekst u prvoj liniji
        for (int col = 0; col < DISPLAY_COLS; col++) {
            display[0][col] = message[(offset + col) % msgLen];
        }

        // Ostale linije su samo za dekoraciju
        for (int i = 1; i < DISPLAY_ROWS; i++) {
            memset(display[i], '-', DISPLAY_COLS);
        }

        clearScreen();
        printDisplay(display);

        offset = (offset + 1) % msgLen;
        usleep(200000); // pauza 0.2s
    }

    return 0;
}
