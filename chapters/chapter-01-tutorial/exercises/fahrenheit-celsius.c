/*
 * Chapter 01 - A Tutorial Introduction
 * Exercise: Fahrenheit to Celsius (conversion table)
 *
 * This program prints a Fahrenheit-to-Celsius conversion table.
 * It is written to be portable and compile cleanly as ANSI C (C89/C90).
 *
 * Build (Linux/macOS):
 *   mkdir -p build
 *   gcc chapters/chapter-01-tutorial/exercises/fahrenheit-celsius.c -o build/temp-converter
 *   ./build/temp-converter
 *
 * Build (Windows, using MinGW or similar):
 *   mkdir build
 *   gcc chapters\chapter-01-tutorial\exercises\fahrenheit-celsius.c -o build\temp-converter.exe
 *   build\temp-converter.exe
 */

#include <stdio.h>

#define LOWER  0    /* lower bound of table (Fahrenheit) */
#define UPPER  300  /* upper bound of table (Fahrenheit) */
#define STEP   20   /* step size (Fahrenheit) */

static double fahrenheit_to_celsius(double f)
{
    return (5.0 / 9.0) * (f - 32.0);
}

int main(void)
{
    int f;

    printf("Fahrenheit to Celsius conversion table\n");
    printf("--------------------------------------\n");
    printf("%8s  %8s\n", "F", "C");
    printf("%8s  %8s\n", "--------", "--------");

    for (f = LOWER; f <= UPPER; f += STEP) {
        double c = fahrenheit_to_celsius((double)f);
        printf("%8d  %8.1f\n", f, c);
    }

    return 0;
}