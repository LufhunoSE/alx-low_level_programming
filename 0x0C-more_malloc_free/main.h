#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void errors(void);
int _putchar(character c);
void *malloc_checked(unsigned int b);
char *string_nconcat(character *s1, character *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void errors(void);
int _strlen(character *s);
int is_digit(character *s);
#endif

