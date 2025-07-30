/*
 * Program Description:
 * --------------------
 * This C program checks whether a given word is a palindrome using recursion.
 * A palindrome is a string that reads the same forwards and backwards (e.g., "level", "radar").
 *
 * Components:
 * -----------
 * 1. #include <stdio.h>
 *    - Provides standard input/output functions like printf().
 *
 * 2. #include <string.h>
 *    - Required for the strlen() function to determine the length of the input string.
 *
 * 3. int isPalindrome(char *str, int left, int right)
 *    - A recursive function that checks if the string is a palindrome.
 *    - Base case:
 *        • If left >= right, all characters have been successfully matched — returns 1 (true).
 *        • If characters at positions `left` and `right` differ — returns 0 (false).
 *    - Recursive step:
 *        • Compares str[left] and str[right], then recurses inward: left + 1, right - 1.
 *
 * 4. int main()
 *    - Declares a C-style string `word` with the value "level".
 *    - Calculates its length using strlen().
 *    - Calls isPalindrome() with the full string bounds: indices 0 to len - 1.
 *    - Prints whether the word is a palindrome or not based on the return value.
 *
 * Sample Output:
 * ---------------
 * The word 'level' is a palindrome.
 *
 * Notes:
 * ------
 * - This implementation only works on null-terminated strings (standard C strings).
 * - It is case-sensitive. For example, "Level" would not be recognized as a palindrome.
 * - It does not ignore spaces or punctuation. You could extend it to do so with preprocessing.
 */

#include <stdio.h>
#include <string.h>

int isPalindrome(char *str, int left, int right) {
    if (left >= right)
        return 1; // base case: all characters matched
    if (str[left] != str[right])
        return 0; // mismatch found
    return isPalindrome(str, left + 1, right - 1); // recursive step
}


int main() {
    char word[] = "level";
    int len = strlen(word);

    if (isPalindrome(word, 0, len - 1))
        printf("The word '%s' is a palindrome.\n", word);
    else
        printf("The word '%s' is not a palindrome.\n", word);

    return 0;
}