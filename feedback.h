#ifndef FEEDBACK_H
#define FEEDBACK_H
#include "wordle.h"
// calcul le feedback (couleurs) dune tentatuve par rapport au mot cible
void compute_feedback(const char *guess,const char *target ,Color colors[]);
// afficher le ffedback a l'écran
void print_feedback(const char *guess, Color colors[]);
#endif
