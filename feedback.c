#include <stdio.h>
#include <ctype.h>
#include "feedback.h"
// Calcule les couleurs Wordle (GREEN,YELLOW,GRAY)
//guess=mot proposer par le joueur
//target=mot secret
//colors=tableau qui stocke le resultat
void compute_feedback(const char *guess, const char *target, Color colors[])
{ 
   int count[26] = {0};// il compte les lettres restantes du mot cible apres avoir marqué les GREEN
//(1) mettre tout en GRAY (lettre absente) on le fais par defaut puis on corrige par green ou yellow
for (int i = 0 ; i < WORD_LEN ;i++)
  colors[i] = GRAY;
//(2) premiere passe : GREEN + compter lettres restantes(bonne letrre,bonne position)
for (int i=0;i < WORD_LEN;i++)
{
   char g = tolower(guess[i]); // lettre proposée (minuscule)
   char t = tolower(target[i]); // lettre du mot secret (minuscule)
 if(g == t)
    colors[i] = GREEN ;
else 
    count[t -'a']++;
}
//(3) seconde passe : YELLOW (bonne lettre,mauvaise position)   
for(int i = 0; i < WORD_LEN; i++)
{
  if (colors[i] == GREEN)
     continue;
   char g = tolower(guess[i]);
  int idx = g -'a';
  if (count[idx] > 0)
{
  colors[i] = YELLOW;
  count[idx]--;
}
else 
    colors[i] = GRAY;//(lettre absente)
}
}
// Affiche les couleurs dans le terminal
void print_feedback(const char *guess, Color colors[])
{ 
   for (int i = 0 ; i < WORD_LEN; i++)
{ 
printf("[");
   //couleur ANSI ( fond vert/ texte noir/lettre en majuscule)
if (colors[i] == GREEN) 
   printf("\x1b[42m\x1b[30m%c\x1b[0m", toupper(guess[i]));
else if (colors[i] == YELLOW)
   printf("\x1b[43m\x1b[30m%c\x1b[0m", toupper(guess[i]));
else
   printf("\x1b[100m\x1b[37m%c\x1b[0m", toupper(guess[i]));
printf("]");
 }
printf("\n");
}





















     
