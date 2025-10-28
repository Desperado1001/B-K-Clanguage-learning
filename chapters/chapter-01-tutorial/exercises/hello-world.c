/*
 * Chapter 01 - A Tutorial Introduction
 * Exercise: Hello World
 *
 * This is a minimal, portable ANSI C (C89/C90) program that prints
 * the classic "Hello, World!" message.
 *
 * Build (Linux/macOS):
 *   mkdir -p build
 *   gcc chapters/chapter-01-tutorial/exercises/hello-world.c -o build/hello-world
 *   ./build/hello-world
 *
 * Build (Windows, using MinGW or similar):
 *   mkdir build
 *   gcc chapters\chapter-01-tutorial\exercises\hello-world.c -o build\hello-world.exe
 *   build\hello-world.exe
 */

#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    printf("Welcome to the C Programming Language!\n");
    return 0;
}