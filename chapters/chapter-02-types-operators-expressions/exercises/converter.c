/*
 * Chapter 02 — Types, Operators, and Expressions
 * Exercise: Type Conversion Demonstrator (converter.c)
 *
 * This program demonstrates common type conversions in C:
 *  - Integer division vs. floating-point division
 *  - Cast placement and its effect on results
 *  - Truncation when converting from floating to integer
 *  - Integer promotions (char/short -> int in expressions)
 *  - Narrowing conversions and wrap-around with unsigned types
 *  - Mixing signed and unsigned values in comparisons
 *
 * The code is written to be portable and to compile cleanly as ANSI C (C89/C90).
 *
 * Build (Linux/macOS):
 *   mkdir -p build
 *   gcc chapters/chapter-02-types-operators-expressions/exercises/converter.c -o build/converter
 *   ./build/converter
 *
 * Build (Windows, using MinGW or similar):
 *   mkdir build
 *   gcc chapters\chapter-02-types-operators-expressions\exercises\converter.c -o build\converter.exe
 *   build\converter.exe
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

static void separator(void) {
    printf("------------------------------------------------------------\n");
}

int main(void) {
    /* 1) Integer division vs floating-point division */
    {
        int a, b;
        double d1, d2, d3, d4;

        a = 5;
        b = 2;

        /* Integer division happens first, then converted to double */
        d1 = a / b;            /* 5/2 -> 2, then 2 -> 2.0 */
        /* One operand cast to double: floating-point division */
        d2 = (double)a / b;    /* 5.0/2 -> 2.5 */
        /* Casting after the division vs. before it */
        d3 = (double)(a / b);  /* (double)2 -> 2.0 */
        d4 = (double)a / (double)b; /* 5.0/2.0 -> 2.5 */

        printf("[1] Integer vs Floating Division\n");
        separator();
        printf("a = %d, b = %d\n", a, b);
        printf("d1 = a / b               => %.6f\n", d1);
        printf("d2 = (double)a / b       => %.6f\n", d2);
        printf("d3 = (double)(a / b)     => %.6f\n", d3);
        printf("d4 = (double)a / (double)b => %.6f\n", d4);
        printf("\n");
    }

    /* 2) Truncation when converting floating to integer; simple rounding */
    {
        double pi, neg;
        int ipi, ineg;
        int round_pos, round_neg;

        pi = 3.14159;
        neg = -3.7;

        /* Truncation toward zero */
        ipi = (int)pi;  /* 3 */
        ineg = (int)neg;/* -3 */

        /* Naive rounding (works well for non-negative values) */
        round_pos = (int)(pi + 0.5);        /* 3.14159 + 0.5 -> 3.64159 -> 3 */
        /* A common trick for negative numbers is (int)(x - 0.5) */
        round_neg = (int)(neg - 0.5);       /* -3.7 - 0.5 -> -4.2 -> -4 */

        printf("[2] Truncation and Rounding\n");
        separator();
        printf("pi = %.5f, (int)pi  = %d (truncation)\n", pi, ipi);
        printf("neg = %.1f, (int)neg = %d (truncation)\n", neg, ineg);
        printf("round_pos = (int)(pi + 0.5) = %d\n", round_pos);
        printf("round_neg = (int)(neg - 0.5) = %d\n", round_neg);
        printf("\n");
    }

    /* 3) Integer promotions and character arithmetic */
    {
        char c;
        int sum_as_int;
        char next_char;

        c = 'A'; /* typically 65 in ASCII */
        /* In expressions, char is promoted to int before arithmetic */
        sum_as_int = c + 5;       /* 65 + 5 = 70 */
        next_char = (char)sum_as_int; /* narrowing back to char */

        printf("[3] Integer Promotions (char -> int)\n");
        separator();
        printf("c = '%c' (%d)\n", c, (int)c);
        printf("c + 5 (as int) = %d\n", sum_as_int);
        printf("(char)(c + 5) = '%c' (%d)\n", next_char, (int)next_char);
        printf("\n");
    }

    /* 4) Unsigned arithmetic, narrowing conversions and wrap-around */
    {
        unsigned char uc1, uc2, uc_narrow;
        int sum_wide;

        uc1 = 250u;
        uc2 = 10u;
        /* Both unsigned char are promoted to int before addition */
        sum_wide = uc1 + uc2;                 /* 250 + 10 = 260 (int) */
        uc_narrow = (unsigned char)sum_wide;  /* narrowing to 8 bits -> 260 mod 256 = 4 */

        printf("[4] Narrowing and Wrap-around (unsigned char)\n");
        separator();
        printf("uc1 = %u, uc2 = %u\n", (unsigned int)uc1, (unsigned int)uc2);
        printf("uc1 + uc2 (promoted to int) = %d\n", sum_wide);
        printf("(unsigned char)(uc1 + uc2)  = %u (wrap-around)\n", (unsigned int)uc_narrow);
        printf("\n");
    }

    /* 5) Mixing signed and unsigned in comparisons */
    {
        int si;
        unsigned int ui;
        int result_less, result_equal;

        si = -1;
        ui = 1u;

        /* Usual arithmetic conversions: si is converted to unsigned
           (implementation-defined width), making -1 become a large value.
           Therefore, (-1u < 1u) is false, and (-1u == 1u) is false. */
        result_less = (si < ui) ? 1 : 0;
        result_equal = (si == ui) ? 1 : 0;

        printf("[5] Signed vs Unsigned Comparison\n");
        separator();
        printf("si = %d, ui = %u\n", si, ui);
        printf("si < ui  => %d (expected 0 due to unsigned comparison)\n", result_less);
        printf("si == ui => %d\n", result_equal);
        printf("Note: Avoid mixing signed and unsigned in comparisons.\n");
        printf("\n");
    }

    /* 6) Casting to control precision and format */
    {
        double x, y, ratio_d;
        int ix, iy;
        double safe_ratio_d;

        x = 7.0;
        y = 2.0;
        ix = 7;
        iy = 2;

        ratio_d = x / y;                 /* 3.5 */
        /* If we only have integers, cast first to avoid integer division */
        safe_ratio_d = (double)ix / (double)iy; /* 3.5 */

        printf("[6] Casting to Control Precision\n");
        separator();
        printf("x = %.1f, y = %.1f, x / y = %.6f\n", x, y, ratio_d);
        printf("ix = %d, iy = %d, (double)ix / (double)iy = %.6f\n", ix, iy, safe_ratio_d);
        printf("\n");
    }

    /* 7) Misc: limits and ranges (from headers) */
    {
        printf("[7] Selected Limits (from <limits.h>, <float.h>)\n");
        separator();
        printf("CHAR_BIT              = %d\n", CHAR_BIT);
        printf("INT_MIN               = %d\n", INT_MIN);
        printf("INT_MAX               = %d\n", INT_MAX);
        printf("UINT_MAX              = %u\n", (unsigned int)UINT_MAX);
        printf("FLT_MIN               = %e\n", FLT_MIN);
        printf("FLT_MAX               = %e\n", FLT_MAX);
        printf("DBL_MIN               = %e\n", DBL_MIN);
        printf("DBL_MAX               = %e\n", DBL_MAX);
        printf("\n");
    }

    printf("Done. Review each section to understand how C performs type conversions.\n");
    return 0;
}