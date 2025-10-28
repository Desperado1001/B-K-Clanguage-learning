/*
 * Chapter 03 — Control Flow
 * Exercise: while-loop basics (sum until EOF)
 *
 * Description:
 *   Read real numbers (double) from standard input and accumulate their sum
 *   using a while loop until EOF is reached. Also track the count and compute
 *   the average. Invalid tokens are skipped with a brief notice.
 *
 * Examples (input):
 *   1 2 3
 *   4.5
 *   foo 6
 *   ^Z (Windows) or Ctrl+D (Unix) to end
 *
 * Output:
 *   Count, Sum, Average (if any numbers were read)
 *
 * Build (Linux/macOS):
 *   mkdir -p build
 *   gcc chapters/chapter-03-control-flow/exercises/while-loop-basics.c -o build/while-loop-basics -Wall -Wextra -std=c89
 *   ./build/while-loop-basics
 *
 * Build (Windows, MinGW or similar):
 *   mkdir build
 *   gcc chapters\chapter-03-control-flow\exercises\while-loop-basics.c -o build\while-loop-basics.exe -Wall -Wextra -std=c89
 *   build\while-loop-basics.exe
 */

#include <stdio.h>

static void discard_invalid_token(void)
{
    int ch;
    /* Discard the remainder of the current non-numeric token.
       Stop at common token boundaries: whitespace or EOF. */
    ch = getchar();
    if (ch == EOF) {
        return;
    }
    if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r' || ch == '\f' || ch == '\v') {
        return;
    }
    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r' || ch == '\f' || ch == '\v') {
            break;
        }
    }
}

int main(void)
{
    /* Accumulators */
    double sum;
    long count;

    /* Input state */
    double x;
    int rc;

    sum = 0.0;
    count = 0L;

    printf("while-loop basics: sum numbers until EOF\n");
    printf("Enter numbers (space/newline separated). Non-numeric tokens will be skipped.\n");
    printf("End with Ctrl+D (Unix) or Ctrl+Z then Enter (Windows).\n\n");

    /* Core while loop: read numbers until EOF */
    while ((rc = scanf("%lf", &x)) != EOF) {
        if (rc == 1) {
            sum += x;
            count += 1L;
        } else {
            /* rc == 0: non-numeric token encountered */
            fprintf(stderr, "[skip] Non-numeric token encountered; skipping.\n");
            discard_invalid_token();
        }
    }

    printf("\n--- Result ---\n");
    if (count > 0L) {
        double avg;
        avg = sum / (double)count;
        printf("Count  : %ld\n", count);
        printf("Sum    : %.10g\n", sum);
        printf("Average: %.10g\n", avg);
    } else {
        printf("No numbers were read.\n");
    }

    return 0;
}