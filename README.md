# Wordle Game & Solveur — ALGO3 L2 ISIL

 Projet réalisé dans le cadre du module ** ALGO3 (Langage C) ** - Département Informatique , USTHB
 
Ce projet implémente le célèbre jeu Wordle en langage C , avec deux modes de fonctionnement : 

1. **Joueur humain**  : le joueur doit denviner un mot secret de 5 lettres en un nombre limité de tentatives  (6 essais).
- Le programme choisit aléatoirement un mot dans un dictionnaire ( word.txt ).
- Chaque proposition du joueur est vérifiée pour s'asurer qu'elle est valide (présente dans le dictionnaire ).
- Après chaque essai , le programme fournit un feedback pour chaque lettre.

2. **Solveur automatique** : le programme peut aussi deviner le mot secret a votre place en utilisant une **stratégie logique** basée sue le feedback.
  - Le solveur parcourt le dictionnaire pour filtrer les mots  incompatibles avec le feedback recu.
  - Il utilise des structure comme 'min_count' , 'max_count' , 'correct_pos' et 'wrong_pos' pour suivre les contraintes sur les lettres.
  - A chaque tour , il choisit le mot le plus prometteur et répète le processus jusqu'a trouver le mot correct.

## Objectif du projet

Ce projet a pour but de mettre en pratique les concepts d'algorithmes , de structures de donées et de gestion de mémoire en langage C a travers un jeu interactif .

Il permet de :
- Jouer au **wordle** en ligne de commande avec un feedback précis pour chaque lettre.
- Tester un **Solveur automatique** capable de deviner le mot secret en utilisant le feedback pour filtrer les mots incompatibles.
- Appliquer la **programmation modulaire** et la **gestion dynamique de la mémoire** pour gérer le dictionnaire et les mots condidats.


