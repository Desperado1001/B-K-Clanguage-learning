/*
 * Chapter 03 — Control Flow
 * Exercise: else-if ladder grading example
 *
 * Description:
 *   Read integer scores (0–100) from standard input and map each score
 *   to a letter grade using an else-if ladder:
 *     90–100: A
 *     80–89 : B
 *     70–79 : C
 *     60–69 : D
 *     0–59  : F
 *
 *   Optionally, this demo also assigns a sign (+ / -) for A–D based on
 *   the ones digit, to showcase a deeper else-if ladder:
 *     ones in [7..9] => '+'
 *     ones in [0..2] => '-'
 *     otherwise      => ' ' (no sign)
 *
 *   Invalid inputs are handled gracefully, and the program loops until EOF.
 *
 * Build (Linux/macOS):
 *   mkdir -p build
 *   gcc chapters/chapter-03-control-flow/exercises/else-if-ladder.c -o build/else-if-ladder -Wall -Wextra -std=c89
 *   ./build/else-if-ladder
 *
 * Build (Windows, MinGW or similar):
 *   mkdir build
 *   gcc chapters\chapter-03-control-flow\exercises\else-if-ladder.c -o build\else-if-ladder.exe -Wall -Wextra -std=c89
 *   build\else-if-ladder.exe
 */

#include <stdio.h>

/* Toggle whether to compute +/- signs for A–D grades. */
#ifndef ENABLE_GRADE_SIGN
#define ENABLE_GRADE_SIGN 1
#endif

/* Flush the rest of the current input line (up to and including newline). */
static void flush_line(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard */
    }
}

/* Compute the base letter grade using an else-if ladder. Returns '\0' if invalid. */
static char letter_from_score(int score) {
    char letter;

    if (score < 0 || score > 100) {
        letter = '\0'; /* invalid marker */
    } else if (score >= 90) {
        letter = 'A';
    } else if (score >= 80) {
        letter = 'B';
    } else if (score >= 70) {
        letter = 'C';
    } else if (score >= 60) {
        letter = 'D';
    } else {
        letter = 'F';
    }

    return letter;
}

/* Compute the sign for A–D using an else-if ladder on the ones digit. */
static char sign_for_letter(int score, char letter) {
#if ENABLE_GRADE_SIGN
    int ones;
    char sign;

    /* No sign for F or invalid. */
    if (letter == 'F' || letter == '\0') {
        return ' ';
    }

    /* Perfect 100 -> A+ */
    if (score == 100) {
        return '+';
    }

    ones = score % 10;

    if (ones >= 7) {
        sign = '+';
    } else if (ones <= 2) {
        sign = '-';
    } else {
        sign = ' ';
    }

    return sign;
#else
    (void)score;
    (void)letter;
    return ' ';
#endif
}

int main(void) {
    int score;
    int rc;

    printf("Else-if ladder grading example\n");
    printf("Enter integer scores (0–100). Ctrl+D (Unix) or Ctrl+Z then Enter (Windows) to end.\n");
#if ENABLE_GRADE_SIGN
    printf("Signs enabled for A–D: ones [7..9] -> '+', [0..2] -> '-', otherwise no sign.\n");
#else
    printf("Grade signs are disabled (set ENABLE_GRADE_SIGN=1 to enable).\n");
#endif
    printf("\n");

    for (;;) {
        char letter;
        char sign;

        printf("Score: ");
        rc = scanf("%d", &score);

        if (rc == 1) {
            flush_line();

            letter = letter_from_score(score);
            sign = sign_for_letter(score, letter);

            if (letter == '\0') {
                printf("=> %d is invalid; please enter a value in [0, 100].\n\n", score);
            } else {
                if (sign == ' ') {
                    printf("=> %d -> %c\n\n", score, letter);
                } else {
                    printf("=> %d -> %c%c\n\n", score, letter, sign);
                }
            }
        } else if (rc == EOF) {
            printf("\nEOF reached. Bye.\n");
            break;
        } else {
            printf("Invalid input (not an integer). Please enter an integer score.\n\n");
            flush_line();
        }
    }

    return 0;
}