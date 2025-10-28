/*
 * operator-precedence.c
 *
 * Chapter 02 — Types, Operators, and Expressions
 * Demo: Precedence and Associativity in C (ANSI C: C89/C90)
 *
 * This program illustrates how C parses and evaluates expressions:
 * - Operator precedence (which operators bind tighter)
 * - Associativity (how operators of the same precedence group)
 * - Common gotchas and how to disambiguate with parentheses
 *
 * Build (Linux/macOS):
 *   mkdir -p build
 *   gcc c_programming_language/chapters/chapter-02-types-operators-expressions/exercises/operator-precedence.c -o build/operator-precedence
 *   ./build/operator-precedence
 *
 * Build (Windows, using MinGW or similar):
 *   mkdir build
 *   gcc c_programming_language\chapters\chapter-02-types-operators-expressions\exercises\operator-precedence.c -o build\operator-precedence.exe
 *   build\operator-precedence.exe
 */

#include <stdio.h>

static void line(void) {
    printf("------------------------------------------------------------\n");
}

int main(void) {
    /* 1) Multiplicative vs. Additive precedence */
    {
        int a, b, c, r1, r2;
        a = 2; b = 3; c = 4;

        /* * binds tighter than + */
        r1 = a + b * c;         /* parsed as a + (b * c) => 2 + (3*4) = 14 */
        r2 = (a + b) * c;       /* (2 + 3) * 4 = 20 */

        printf("[1] Multiplicative vs Additive precedence\n");
        line();
        printf("2 + 3 * 4          => %d\n", r1);
        printf("(2 + 3) * 4        => %d\n\n", r2);

        /* Left-associativity
 for + and * and / */
        {
            int r3, r4;
            r3 = 20 / 5 * 2;    /* ((20 / 5) * 2) = 8 because / and * are left-associative */
            r4 = 20 / (5 * 2);  /* 20 / 10 = 2 */
            printf("20 / 5 * 2        => %d\n", r3);
            printf("20 / (5 * 2)      => %d\n\n", r4);
        }
    }

    /* 2) Unary operators vs cast and unary minus */
    {
        double x;
        int r1, r2;

        x = 3.7;
        r1 = (int)x;    /* truncates toward zero => 3 */
        r2 = - (int)x;  /* -(3) => -3 */

        printf("[2] Unary operators and casts\n");
        line();
        printf("(int)3.7           => %d\n", r1);
        printf("-(int)3.7          => %d\n", r2);

        /* Note difference
 between (int)-3.7 and -(int)3.7 */
        {
            int m1, m2;
            m1 = (int)(-3.7);   /* truncates -3.7 => -3 */
            m2 = - (int)(3.7);  /* -(3) => -3 */
            printf("(int)(-3.7)       => %d\n", m1);
            printf("-(int)(3.7)       => %d\n\n", m2);
        }
    }

    /* 3) Relational, Equality, and Logical precedence */
    {
        int r1, r2, r3, r4;

        /* * has higher precedence than +, relational < higher than equality ==,
           logical && and || are lower than bitwise ops, and much lower than relational/equality. */
        r1 = 1 + 2 < 3 * 2;         /* (1 + 2) < (3 * 2) => 3 < 6 => 1 */
        r2 = (1 + 2 < 3) * 2;       /* (3 < 3) => 0, 0 * 2 => 0 */
        r3 = (1 + 2) < (3 * 2);     /* same as r1 => 1 */
        r4 = (1 + 2 == 3) && (4 < 5); /* (3 == 3) && (4 < 5) => 1 && 1 => 1 */

        printf("[3] Relational, Equality, Logical precedence\n");
        line();
        printf("1 + 2 < 3 * 2      => %d\n", r1);
        printf("(1 + 2 < 3) * 2    => %d\n", r2);
        printf("(1 + 2) < (3 * 2)  => %d\n", r3);
        printf("(1 + 2 == 3) && (4 < 5) => %d\n\n", r4);

        /* Equality vs bitwise AND precedence: == is higher than & */
        {
            int eq1, eq2;
            eq1 = (1 == (1 & 3));    /* explicitly parenthesized for clarity */
            eq2 = (1 == 1) & 3;      /* 1 & 3 => 1 (bitwise) */
            printf("1 == 1 & 3        => %d  (parses as 1 == (1 & 3))\n", eq1);
            printf("(1 == 1) & 3      => %d  (bitwise AND of 1 and 3)\n\n", eq2);
        }
    }

    /* 4) Assignment is right-associative */
    {
        int a, b, c;
        a = b = c = 1;  /* parsed as a = (b = (c = 1)) */

        printf("[4] Assignment associativity (right-to-left)\n");
        line();
        printf("After a = b = c = 1 => a=%d, b=%d, c=%d\n", a, b, c);

        /* Using assignment expressions inside a larger expression.
           Note: Order of evaluation of the two operands of '+' is unspecified,
           but the final value of z = (x=2) + (y=3) is well-defined as 5,
           and x becomes 2, y becomes 3 regardless of order. */
        {
            int x, y, z;
            x = 0; y = 0;
            z = (x = 2) + (y = 3);
            printf("z = (x = 2) + (y = 3) => z=%d, x=%d, y=%d\n\n", z, x, y);
        }
    }

    /* 5) Conditional operator ?: is right-associative */
    {
        int r1, r2;
        r1 = 0 ? 1 : 0 ? 2 : 3;        /* parsed as 0 ? 1 : (0 ? 2 : 3) => 3 */
        r2 = (0 ? 1 : 0) ? 2 : 3;      /* (0 ? 1 : 0) => 0, then 0 ? 2 : 3 => 3 */

        printf("[5] Conditional operator (?:) associativity (right-to-left)\n");
        line();
        printf("0 ? 1 : 0 ? 2 : 3  => %d  (0 ? 1 : (0 ? 2 : 3))\n", r1);
        printf("(0 ? 1 : 0) ? 2 : 3 => %d\n\n", r2);
    }

    /* 6) Bitwise vs Logical operators */
    {
        int a,
 b;
        int r_and, r_or, r_xor;
        int l_and, l_or;

        a = 6;  /* 110b */
        b = 3;  /* 011b */

        r_and = a & b;  /* 010b => 2 */
        r_or  = a | b;  /* 111b => 7 */
        r_xor = a ^ b;  /* 101b => 5 */

        l_and = (a != 0) && (b != 0); /* 1 && 1 => 1 */
        l_or  = (a != 0) || (b != 0); /* 1 || 1 => 1 */

        printf("[6] Bitwise (& | ^) vs Logical (&& ||)\n");
        line();
        printf("6 & 3  => %d\n", r_and);
        printf("6 | 3  => %d\n", r_or);
        printf("6 ^ 3  => %d\n", r_xor);
        printf("(6 != 0) && (3 != 0) => %d\n", l_and);
        printf("(6 != 0) || (3 != 0) => %d\n\n", l_or);
    }

    /* 7) Prefix vs Postfix increment (avoid using the same variable
          multiple times in a single expression to prevent UB) */
    {
        int i, a, b;

        i = 1;
        a = i++ + 10;   /* uses i (1), then increments => a=11, i=2 */
        b = ++i + 10;   /* increments i first (3), then uses => b=13, i=3 */

        printf("[7] Prefix (++i) vs Postfix (i++)\n");
        line();
        printf("Start i=1:\n");
        printf("a = i++ + 10  => a=%d, i=%d\n", a, i);
        printf("b = ++i + 10  => b=%d, i=%d\n\n", b, i);
    }

    /* 8) Comma operator has the lowest precedence */
    {
        int a, b, r1, r2;

        a = 0; b = 0;

        /* Comma as an operator yields the value of the right operand.
           Parentheses are needed to make comma be an operator here. */
        r1 = (b = 1, b + 2);   /* b set to 1, then value is 1+2 => 3 */
        r2 = (a = 5, b = a + 7);/* a=5, then b=12, expression value is 12 */

        printf("[8] Comma operator (lowest precedence)\n");
        line();
        printf("r1 = (b = 1, b + 2) => r1=%d, b=%d\n", r1, b);
        printf("r2 = (a = 5, b = a + 7) => r2=%d, a=%d, b=%d\n\n", r2, a, b);
    }

    /* 9) Shifts vs Additive precedence */
    {
        int r1, r2;
        r1 = (1 + 2) << 3;      /* explicitly parenthesized: (1 + 2) << 3 => 3 << 3 => 24 */
        r2 = 1 + (2 << 3);      /* 2 << 3 => 16, 1 + 16 => 17 */

        printf("[9] Shift vs Additive precedence\n");
        line();
        printf("1 + 2 << 3        => %d\n", r1);
        printf("1 + (2 << 3)      => %d\n\n", r2);
    }

    printf("Tips:\n");
    printf("- Use parentheses to make intent explicit and portable.\n");
    printf("- Remember precedence order (high to low): unary, multiplicative, additive, shifts,\n");
    printf("  relational, equality, bitwise (& ^ |), logical (&& ||), ?:, assignment, comma.\n");
    printf("- Operators like +, -, *, /, %%, <<, >>, <, >, <=, >=, ==, !=, &, ^, | are left-associative;\n");
    printf("  ?: and assignment are right-associative; comma is the lowest.\n");
    printf("- Avoid relying on unspecified operand evaluation order; parenthesize and split statements.\n");

    return 0;
}