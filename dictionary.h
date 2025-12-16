#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stdbool.h>
#include "wordle.h"
//DICTIONNAIRE
extern char **dictionary; // declation du tableau de mots
extern int dict_size; //nombre de mots chargés

int load_dictionary(const char *filename); // charger le dictionnaire depuis un fichier
bool is_valid_word(const char *w); //verifie si un mot est dans le dictionnaire
void free_dictionary(void); // libere la memoire du dictionnaire  
#endif
