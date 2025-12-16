#ifndef SOLVER_H
#define SOLVER_H
#include "wordle.h"
#include <stdbool.h>
//solveur logique
//fonction qui gere le feedback de lutilisateur dans le solver
int solver_user_feedback(void);
//permet au jouer de deviner le mot et d'obtenir le feedback
void human_play(void); //mode joueur humain
#endif
