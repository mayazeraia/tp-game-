#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dictionary.h"
#include "solver.h"
int main (int argc, char **argv) {
if (argc < 2)
{
 printf("Usage: %s <words.txt>\n" , argv[0]);
 return 1;
 }
 int loaded = load_dictionary(argv[1]);
 if (loaded <=0)
 {
   printf("Dictionnaire vide ou erreur\n");
   return 1;
   }
   printf("%d mots chargés (%d lettres)\n", loaded,WORD_LEN);
   srand((unsigned)time(NULL));
 while (1)
  {
  //Afficher le menu 
    printf("\n**********Bienvenue dans Wordle Solver anglais***********\n");
    printf("1.Jouer\n2. Solveur logique corrigé\n3.Quitter\n");
    printf("Votre choix:");
    //Lire le choix utilisateur
    int ch;
    if (scanf("%d",&ch)!=1)
    {
      while (getchar() != '\n');
      printf("Entrée invalide\n");
      continue;
      }
  //Traiter le choix 
     if (ch == 1)
        human_play();
     else if (ch == 2)
         solver_user_feedback();
      else if (ch == 3)
         break;
      else
          printf("Choix invalide\n");
       }
    free_dictionary();
    return 0; //indique que le programme sest terminer avec succes 
    }
    























    
