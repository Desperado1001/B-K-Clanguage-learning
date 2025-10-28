/*
 * Chapter 03 — Control Flow
 * Exercise: if-else basics (range categorization)
 *
 * 中文说明：
 * 本练习通过 else-if 梯形结构实现“区间分类”示例：将输入的整数分数(0–100)
 * 映射为等级(A/B/C/D/F)，并对越界与非法输入进行提示。支持从标准输入读取多行，
 * 直到遇到 EOF 结束。
 *
 * Build (Linux/macOS):
 *   mkdir -p build
 *   gcc chapters/chapter-03-control-flow/exercises/if-else-basics.c -o build/if-else-basics -Wall -Wextra -std=c89
 *   ./build/if-else-basics
 *
 * Build (Windows, MinGW or similar):
 *   mkdir build
 *   gcc chapters\chapter-03-control-flow\exercises\if-else-basics.c -o build\if-else-basics.exe -Wall -Wextra -std=c89
 *   build\if-else-basics.exe
 */

#include <stdio.h>

/* Flush the rest of the current input line (up to and including newline). */
static void flush_line(void) {
    int ch;
    /* Read until newline or EOF. */
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard */
    }
}

static void categorize_score(int score) {
    /* Basic range categorization via if/else-if/else ladder.
       Boundaries are inclusive at the upper end for each band (e.g., <= 59). */
    if (score < 0) {
        printf("Score %d -> invalid (negative)\n", score);
    } else if (score <= 59) {
        printf("Score %d -> F (0–59)\n", score);
    } else if (score <= 69) {
        printf("Score %d -> D (60–69)\n", score);
    } else if (score <= 79) {
        printf("Score %d -> C (70–79)\n", score);
    } else if (score <= 89) {
        printf("Score %d -> B (80–89)\n", score);
    } else if (score <= 100) {
        printf("Score %d -> A (90–100)\n", score);
    } else {
        printf("Score %d -> invalid (greater than 100)\n", score);
    }
}

int main(void) {
    int score;
    int rc;

    printf("if-else basics: range categorization (score -> grade)\n");
    printf("Enter integer scores in [0, 100]; Ctrl+D (Unix) or Ctrl+Z (Windows) to end.\n");
    printf("Examples: 59  60  75  89  90  101  -3\n\n");

    /* Read multiple scores until EOF. */
    for (;;) {
        printf("Enter score: ");
        rc = scanf("%d", &score);

        if (rc == 1) {
            /* Valid integer read. Consume trailing characters on the line, if any. */
            flush_line();
            categorize_score(score);
        } else if (rc == EOF) {
            /* End of input stream. */
            printf("\nEOF reached. Bye.\n");
            break;
        } else {
            /* rc == 0: Non-integer input encountered. */
            printf("Invalid input (not an integer). Please enter an integer score.\n");
            flush_line(); /* Discard the rest of the invalid line. */
        }
    }

    return 0;
}