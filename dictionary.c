#include <stdio.h>
#include <stdlib.h>
#include <string.h >
#include <ctype.h>
#include <stdbool.h> 
#include "wordle.h"
#include "dictionary.h" // on iclut notre .h pour etre sur que tout correspond

char **dictionary=NULL; // le tableau des mots
int dict_size = 0; //nombre de mots dans le dictionnaire

//  chargement du dictionnaire
int load_dictionary(const char *filename){
FILE*f=fopen(filename,"r");
if(!f){
   perror("open dictionary");
   return -1 ;
}
dictionary= malloc(sizeof(char*) * MAX_WORDS);
if (! dictionary){
fclose(f);
return -1;
}
char buffer[128]; // jai remplacer buf par buffer
dict_size = 0; 

while(fgets(buffer, sizeof(buffer),f)){
   buffer[ strcspn(buffer,"\r\n")] =0 ; //retire\n
  
if((int)strlen(buffer) == WORD_LEN && dict_size < MAX_WORDS){
   dictionary[dict_size++]= strdup(buffer);
}
}
fclose (f);
return dict_size;
}
// verification si un mot est valide

bool is_valid_word(const char *w) {
  for (int i = 0; i < dict_size ; i++){
    if (strcmp(dictionary[i],w) == 0)
      return true;
}
return false;
}
// libérer le dictionnaire
void free_dictionary(void) {
  if (!dictionary) return ;
  
  for (int i = 0 ; i < dict_size; i++)
    free(dictionary[i]);
  
free(dictionary);
dictionary = NULL;
dict_size = 0;
}



    










  
