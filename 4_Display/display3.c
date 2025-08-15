#include <stdio.h>   // printf, fflush
#include <stdlib.h>  // atexit
#include <string.h>  // strlen
#include <time.h>    // nanosleep, struct timespec
#include <signal.h>  // (not used here directly, but okay to keep)

#define DISPLAY_WIDTH  32   // number of visible characters per row
#define DISPLAY_HEIGHT 9    // number of rows in the display

// Text that will scroll across the middle row
static const char DISPLAY_TEXT[] = "Hello World! ";

/*
 * Restore terminal settings on exit:
 * - \033[?25h : show cursor (it gets hidden while animating)
 * - fflush(stdout) ensures the escape sequence is sent immediately
 */
static void restore_tty(void)
{
    printf("\033[?25h");
    fflush(stdout);
}

/*
 * Sleep helper in milliseconds using POSIX nanosleep:
 * - Converts ms into seconds and nanoseconds
 * - Sleeps without busy-waiting
 */
static void sleep_ms(long ms)
{
    struct timespec ts;
    ts.tv_sec  = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}

/*
 * Initialize the display framebuffer pointed to by `p`.
 * Memory layout is a flat 1D buffer of DISPLAY_HEIGHT rows,
 * each row containing DISPLAY_WIDTH characters + 1 byte for '\0'.
 *
 * This fills every visible cell with '-' and writes a '\0' at the end
 * of each row so we can print a row with printf("%s").
 */
void initDisplay(char *p)
{
    for (size_t row = 0; row < DISPLAY_HEIGHT; row++)
    {
        for (size_t col = 0; col < DISPLAY_WIDTH; col++)
        {
            *p++ = '-';     // put a placeholder character in each column
        }
        *p++ = '\0';        // null-terminate the current row
    }
}

/*
 * Print the full display starting at address `p`.
 * - \033[H moves the cursor to the top-left of the terminal without clearing
 *   the whole screen; we overwrite in place to reduce flicker.
 * - Each row starts at offset row * (DISPLAY_WIDTH + 1)
 *   (the +1 accounts for the '\0' per row).
 * - fflush to push output immediately so animation looks smooth.
 */
void printDisplay(const char *p)
{
    printf("\033[H");  // move cursor to home position
    for (size_t row = 0; row < DISPLAY_HEIGHT; row++)
    {
        printf("%s\n", p + row * (DISPLAY_WIDTH + 1));
    }
    fflush(stdout);
}

/*
 * Write DISPLAY_TEXT into the row pointed to by `row_ptr`, starting at a
 * given circular offset. Wrap using modulo on the text length so the text
 * scrolls seamlessly.
 *
 * Note: we only write DISPLAY_WIDTH characters; the '\0' at the end of
 * the row remains intact because printf needs it.
 */
void setMessageToCurrentOffset(size_t offset, char *row_ptr, size_t text_len)
{
    for (size_t col = 0; col < DISPLAY_WIDTH; col++)
    {
        row_ptr[col] = DISPLAY_TEXT[(offset + col) % text_len];
    }
}

/*
 * Main animation loop:
 * - Compute constants once (text length, middle row address).
 * - Send terminal setup sequences:
 *     \033[2J  : clear entire screen
 *     \033[H   : move cursor to home
 *     \033[?25l: hide cursor (it will be restored on exit)
 * - Register restore_tty with atexit so the cursor reappears if the program exits.
 * - On each frame:
 *     * write the scrolled text into the middle row
 *     * advance the offset circularly
 *     * print the whole display
 *     * sleep a bit to control frame rate
 */
void showAnimation(char *p)
{
    const size_t text_len = strlen(DISPLAY_TEXT);
    size_t offset_from_left = 0;
    const size_t middle_row = DISPLAY_HEIGHT / 2;       // integer division; for 9 rows this is 4
    char *mrp = p + middle_row * (DISPLAY_WIDTH + 1);   // pointer to start of the middle row

    // One-time terminal setup: clear, home, hide cursor
    printf("\033[2J\033[H\033[?25l");
    atexit(restore_tty);  // ensure cursor is shown again on exit

    for (;;)
    {
        // Write current frame text into the middle row
        setMessageToCurrentOffset(offset_from_left, mrp, text_len);

        // Advance scroll offset; wrap at text length so it repeats smoothly
        offset_from_left = (offset_from_left + 1) % text_len;

        // Draw the full display buffer
        printDisplay(p);

        // Control animation speed (~200 ms per frame)
        sleep_ms(200);
    }
}

/*
 * Program entry point:
 * - Allocate a 2D character buffer where each logical row has DISPLAY_WIDTH
 *   visible characters plus one '\0' so it can be printed with "%s".
 * - Pass the base address to initializer and animation.
 */
int main(void)
{
    char display[DISPLAY_HEIGHT][DISPLAY_WIDTH + 1];  // +1 for per-row '\0'
    initDisplay(&display[0][0]);
    showAnimation(&display[0][0]);
    return 0;
}
