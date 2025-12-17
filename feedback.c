#include <stdio.h>
#include <ctype.h>
#include "feedback.h"
// Calcule les couleurs Wordle (GREEN,YELLOW,GRAY)
void compute_feedback(const char *guess, const char *target, Color colors[])
{ 
   int cont[26] = {0};
//(1) mettre tout en GRAY
for (int i = 0 ; i <WORD_LEN ;i++)
  colors[i] = GRAY
