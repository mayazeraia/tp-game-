#ifndef WORDLE_H
#define WORDLE_H

#include <stdbool.h>

#define WORD_LEN 5
#define MAX_WORDS 10000
#define MAX_GUESSES 6

typedef enum { GRAY, YELLOW, GREEN } Color;

void compute_feedback(const char *guess, const char *target, Color colors[WORD_LEN]);
void print_feedback(const char *guess, Color colors[WORD_LEN]);

#endif
