#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dictionary.h"
#include "solver.h"
int main (int argc, char **argv) {
 //argc est le nombre darguments passées au programme (y compris le nom du programme)
 //argv est le tableau de chaine contenant ces arguments
if (argc < 2)
 // Vérifier la presence du fichier dictionnaire words.txt
{
 printf("Usage: %s <words.txt>\n" , argv[0]);
 return 1;
 }//charger le dictionnaire 
 int loaded = load_dictionary(argv[1]);// lit tous les mots du fichier fourni 
 if (loaded <=0)
 {
   printf("Dictionnaire vide ou erreur\n");
   return 1;
   }
 //affiche combien de mots ont ete carger et la longueur des mots 
 //%d nombre de mots 
//(%d lettres )combien de lettre dans le mot
   printf("%d mots chargés (%d lettres)\n", loaded,WORD_LEN);
 // initialiser le générateur de nombres aléatoires
   srand((unsigned)time(NULL));
 // Permet de choisir un mot au hasard pour le mode joueur 
 while (1)// boucle du menu principal
  //le menu restera affiché jusqua ce que lutilisateur choisisse de quitter
  {
  //Afficher le menu 
    printf("\n**********Bienvenue dans Wordle Solver anglais***********\n");
    printf("1.Jouer\n2. Solveur logique corrigé\n3.Quitter\n");
    printf("Votre choix:");
    //Lire le choix utilisateur
    int ch;
    if (scanf("%d",&ch)!=1)
    {
      while (getchar() != '\n');// Dans le cas dune lecture impossible on vide le buffer pour éviter les mauvaises saisies et continue         
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
 // Libérer la mémoire du dictionnaire
    free_dictionary();
    return 0; //indique que le programme sest terminer avec succes 
    }
    























    
