#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define DISPLAY_WIDTH 32
#define DISPLAY_HEIGHT 8
#define DISPLAY_TEXT "Hello World! "

void initDisplay(char *p)
{
    for (int row = 0; row < DISPLAY_HEIGHT; row++)
    {
        for (int col = 0; col < DISPLAY_WIDTH; col++)
        {
            *p++ = '.';
        }
        *p++ = '\0';
    }
}

void printDisplay(char *p)
{
    for (int row = 0; row < DISPLAY_HEIGHT; row++)
    {
        printf("%s\n", p + row * (DISPLAY_WIDTH + 1));
    }
}

void deleteDisplay()
{
    printf("\033[H\033[J"); // ANSI code for cleaning terminal
}

void setMessageToCurrentOffset(int offset, char *p)
{
    for (int col = 0; col < DISPLAY_WIDTH; col++)
    {
        p[col] = DISPLAY_TEXT[(offset + col) % strlen(DISPLAY_TEXT)];
    }
}

void showAnimation(char *p)
{
    int display_text_length = strlen(DISPLAY_TEXT);
    int offset_from_left = 0;
    int middle_row = (int)floor((double)DISPLAY_HEIGHT / 2);
    char *mrp = p + (middle_row) * (DISPLAY_WIDTH + 1); // pointer points to the middle row where text should be displayed

    while (1)
    {
        setMessageToCurrentOffset(offset_from_left, mrp);
        offset_from_left = (offset_from_left + 1) % strlen(DISPLAY_TEXT);
        deleteDisplay();
        printDisplay(p);
        usleep(200000);
    }
}

int main()
{
    char display[DISPLAY_HEIGHT][DISPLAY_WIDTH + 1]; //  WIDTH +1 because one element is reserved for nul-terminator '\0'
    initDisplay(&display[0][0]);
    showAnimation(&display[0][0]);
    return 0;
}