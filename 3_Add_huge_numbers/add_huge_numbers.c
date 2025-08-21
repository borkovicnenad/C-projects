#include <stdio.h>
#include <string.h>
#include <ctype.h>   // optional: for digit validation

/* Swap the contents of two chars safely using a temporary.
   XOR-swap is unnecessary here and can be risky if pointers alias. */
static void swap_char(char *a, char *b) {
    if (a == b) return;         // defensive: nothing to swap
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Reverse a char buffer of given length in place. */
static void reverse(char *p, size_t length) {
    if (!p || length < 2) return;
    for (size_t i = 0, j = length - 1; i < j; ++i, --j) {
        swap_char(&p[i], &p[j]);
    }
}

int main(void)
{
    /* Up to 1000 digits each (plus '\0').
       result needs up to 1001 digits + '\0' (when there is a final carry). */
    char firstNumber[1001];
    char secondNumber[1001];
    char result[1002];

    /* Safer scanf width specifiers prevent buffer overflow.
       Reads two space-separated strings of digits. */
    if (scanf("%1000s %1000s", firstNumber, secondNumber) != 2) {
        fprintf(stderr, "Input error: expected two numbers.\n");
        return 1;
    }

    /* (Optional) Validate inputs are digits only; reject otherwise. */
    for (size_t i = 0; firstNumber[i]; ++i) {
        if (!isdigit((unsigned char)firstNumber[i])) {
            fprintf(stderr, "First input contains non-digit characters.\n");
            return 1;
        }
    }
    for (size_t i = 0; secondNumber[i]; ++i) {
        if (!isdigit((unsigned char)secondNumber[i])) {
            fprintf(stderr, "Second input contains non-digit characters.\n");
            return 1;
        }
    }

    size_t first_length  = strlen(firstNumber);
    size_t second_length = strlen(secondNumber);
    size_t longer_len    = (first_length > second_length) ? first_length : second_length;

    /* Convert ASCII digits to numeric values in-place (0..9). */
    for (size_t i = 0; i < first_length;  ++i) firstNumber[i]  = (char)(firstNumber[i]  - '0');
    for (size_t i = 0; i < second_length; ++i) secondNumber[i] = (char)(secondNumber[i] - '0');

    /* Reverse both numbers so index 0 is the least significant digit. */
    reverse(firstNumber,  first_length);
    reverse(secondNumber, second_length);

    /* Pad the shorter array with zeros up to longer_len to avoid
       reading uninitialized memory during addition. */
    for (size_t i = first_length;  i < longer_len; ++i)  firstNumber[i]  = 0;
    for (size_t i = second_length; i < longer_len; ++i) secondNumber[i] = 0;

    /* Grade-school addition with carry on reversed arrays. */
    int carry = 0;
    size_t i = 0;
    for (i = 0; i < longer_len; ++i) {
        int sum   = firstNumber[i] + secondNumber[i] + carry; // each 0..9
        result[i] = (char)(sum % 10);                         // current digit
        carry     = (sum >= 10);                              // 1 if overflow
    }

    /* If a carry remains, append it as a new most significant digit. */
    if (carry) {
        result[i++] = 1;  // i becomes longer_len + 1
    }

    /* Reverse result to restore most significant digit first. */
    reverse(result, i);

    /* Convert numeric digits back to ASCII. */
    for (size_t k = 0; k < i; ++k) {
        result[k] = (char)(result[k] + '0');
    }
    result[i] = '\0';

    printf("%s\n", result);
    return 0;
}
