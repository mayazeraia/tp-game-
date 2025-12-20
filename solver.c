#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "wordle.h"
#include "dictionnary.h" // pour utiliser le dictionnaire 
#include "solver.h"

int solver_user_feedback()
{
  bool used_words[MAX_WORDS] = {false}; //évite de proposer le meme mots chaque mots
  int min_count[26] = {0} // le nombre minimum de fois ou une lettre peut apparaitre dans le mot secret 
  int man_count[26]; // la lettre peut apparaitre au plus de X fois
  bool correct_pos[WORD_LEN][26]= {false};
  bool wrong_pos[WORD_LEN][26] = {false};

  for (int i = 0 ; i < 26 ; i++ )
    max_count[i] = WORD_LEN;

  char guesses_history[MAX_GUESSES][WORD_LEN + 1]; //stocke les mots proposer par le solveur 
  char feedback_history[MAX_GUESSES][WORD_LEN + 1]; //stocke le feedback correspandant
  int history_count = 0 ;  //nombe d'essaie deja fait et aide a savoir ou stocker le prochain essaie 

  printf("\n--- SOLVEUR LOGIQUE WORDLE (angalis) ---\n")
  printf("Feedback: g=verT , y=jaune , b=gris\n");

  for (int turn = 1 ; turn <= MAX_GUESSES; turn++ ) //boucle principale 1 : on choisit un mot pour ce tour 
    {
      int best_idx = -1;
      int best_score = -1;

       for (int i=0 ; i < dict_size; i++)  // verifier si le mot est valide , calculer le score , garder le meilleur mot
       {   
        if (used_words[i]) // si se mot a deja été proposer on passe au suivant 
                continue;

          char *w = dictionary[i]; //w est un pointeur qui pointe vers les mots du dictionnaire  
            bool valid = true;
            int count_letter[26] = {0}; // compte les lettres d'un mot 

          for (int j = 0; j < WORD_LEN; j++)  // parcourt chaque lettre du mot w
            {
                int c = w[j] - 'a';
                count_letter[c]++;  //On compte combien de fois chaque lettre apparaît dans le mot
                if (wrong_pos[j][c])  //Si la lettre c ne doit pas être à cette position , le mot est invalide
                {
                    valid = false;
                    break;
                }
                if (correct_pos[j][c] && w[j] - 'a' != c) //Si la lettre doit être à cette position, mais n’est pas là, le mot est invalide.
                {
                    valid = false;
                    break;
                }
            }

              if (!valid)
                continue ;

          for (int c = 0; c < 26; c++)
                if (count_letter[c] < min_count[c] || count_letter[c] > max_count[c])
                {
                    valid = false;
                    break;
                }

            if (!valid)
                continue;

            int score = 0;
            for (int j = 0; j < WORD_LEN; j++)
            {
                int c = w[j] - 'a';
                if (min_count[c] == 0)
                    score++;
            }

            if (score > best_score)
            {
                best_score = score;
                best_idx = i;
            }
        }

        if (best_idx < 0)
        {
            printf("Erreur: aucun mot valide restant !\n");
            break;
        }

        const char *guess = dictionary[best_idx];
        used_words[best_idx] = true;

        printf("\nEssai %d : %s\n", turn, guess);
        if (turn == 1)
            printf("(Premier mot choisi pour maximiser lettres fréquentes)\n");

        printf("Feedback (g/y/b) : ");
        char fb[WORD_LEN + 1];
        if (scanf("%5s", fb) != 1)
        {
            printf("Erreur lecture\n");
            return 1;
        }

        strncpy(guesses_history[history_count], guess, WORD_LEN + 1);
        strncpy(feedback_history[history_count], fb, WORD_LEN + 1);
        history_count++;

        bool win = true;
        int count_guess[26] = {0};
        int g_or_y[26] = {0};

        for (int j = 0; j < WORD_LEN; j++)
        {
            char c = tolower(guess[j]);
            count_guess[c - 'a']++;

            if (fb[j] == 'g')
            {
                correct_pos[j][c - 'a'] = true;
                g_or_y[c - 'a']++;
            }
            else if (fb[j] == 'y')
            {
                wrong_pos[j][c - 'a'] = true;
                g_or_y[c - 'a']++;
            }

            if (fb[j] != 'g')
                win = false;
        }

        for (int c = 0; c < 26; c++)
        {
            if (g_or_y[c] > 0)
                min_count[c] = (min_count[c] > g_or_y[c] ? min_count[c] : g_or_y[c]);
            if (count_guess[c] > g_or_y[c])
                max_count[c] = g_or_y[c];
        }

        if (win)
        {
            printf("🎉 Mot trouvé : %s en %d essais\n", guess, turn);
            break;
        }
    }

    printf("\n=== HISTORIQUE ===\n");
    for (int i = 0; i < history_count; i++)
        printf("%d) %s -> %s\n", i + 1, guesses_history[i], feedback_history[i]);
    printf("=================\n");

    return 0;
} 

/* ---------------- Joueur humain ---------------- */
void human_play()
{
    srand((unsigned)time(NULL));
    int idx = rand() % dict_size;
    char *target = dictionary[idx];

    char guess[64];

    printf("\nDevinez le mot (%d lettres)\n", WORD_LEN);

    for (int t = 1; t <= MAX_GUESSES; t++)
    {
        printf("Essai %d> ", t);
        if (scanf("%63s", guess) != 1)
        {
            printf("Erreur lecture\n");
            return;
        }

        if ((int)strlen(guess) != WORD_LEN)
        {
            printf("Mot de %d lettres !\n", WORD_LEN);
            t--;
            continue;
        }

        for (int i = 0; i < WORD_LEN; i++)
            guess[i] = tolower((unsigned char)guess[i]);

        if (!is_valid_word(guess))
        {
            printf("Mot invalide\n");
            t--;
            continue;
        }

        Color c[WORD_LEN];
        compute_feedback(guess, target, c);
        print_feedback(guess, c);

        if (strcmp(guess, target) == 0)
        {
            printf("Bravo ! Trouvé en %d essais !\n", t);
            return;
        }
    }

    printf("Perdu ! Mot = %s\n", target);
}
