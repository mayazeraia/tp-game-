# 🎮 WORDLE GAME & SOLVEUR🎮
🧠 ALGO3 — L2 ISIL

📘 PROJET RÉALISÉ DANS LE CADRE DU MODULE ALGO3 (LANGAGE C)
🏫 DÉPARTEMENT INFORMATIQUE — USTHB

# 🎯 OBJECTIF DU PROJET🎯

Ce projet consiste en l’implémentation complète du jeu Wordle en langage C, intégrant un mode joueur humain ainsi qu’un solveur automatique intelligent capable de deviner le mot secret en un nombre réduit de tentatives.

🎯 Les objectifs principaux sont :

-Permettre à un utilisateur de jouer à Wordle en ligne de commande, avec un feedback précis.

-Mettre en œuvre un solveur logique capable de résoudre automatiquement une grille Wordle.

#    🚀 FONCTIONNALITÉS:


# 👤 MODE JEU HUMAIN 👤

Le joueur doit deviner un mot secret de 5 lettres.

Le mot est choisi aléatoirement par l’ordinateur depuis un dictionnaire externe (word.txt).

Le joueur dispose de 6 tentatives maximum.

Chaque mot proposé est vérifié afin de s’assurer qu’il est valide (présent dans le dictionnaire).

Après chaque essai, un feedback coloré est affiché pour chaque lettre.

La partie se termine lorsque le mot est trouvé ou que le nombre maximum d’essais est atteint.


# 🤖 MODE SOLVEUR AUTOMATIQUE 🤖

Le programme peut deviner automatiquement le mot secret à la place de l’utilisateur.

Il utilise une stratégie logique basée sur le feedback reçu à chaque tentative.

Le solveur parcourt le dictionnaire afin de filtrer les mots incompatibles.

Il exploite plusieurs structures de contraintes :

min_count : nombre minimum d’occurrences d’une lettre

max_count : nombre maximum d’occurrences d’une lettre

correct_pos : lettres bien placées

wrong_pos : lettres mal placées

À chaque tour, le mot le plus prometteur est sélectionné jusqu’à trouver la solution.

# 📚 GESTION DU DICTIONNAIRE

-Chargement dynamique des mots depuis un fichier texte externe.

Utilisation de la mémoire dynamique pour gérer efficacement les mots candidats.

# 🎨 INTERFACE COLORÉE (TERMINAL)🎨

-Utilisation des codes couleurs ANSI pour afficher le feedback :

🟩 Vert 

🟨 Jaune 

⬜ Gris 

# ⚙️ASPECTS TECHNIQUES ⚙️

-Langage utilisé : C

-Programmation modulaire (.c / .h)

-Utilisation de la mémoire dynamique

-Manipulation de fichiers

-Affichage coloré via les codes ANSI

# 🖥️ MULTIPLATEFORME🖥️

Programme compatible avec Windows et Linux.

## 📏 RÈGLES DU JEU WORDLE 📏

🔤 Le mot secret contient WORD_LEN lettres (5 lettres).

À chaque essai, un feedback est donné :

🟩 VERT : lettre correcte à la bonne position

🟨 JAUNE : lettre correcte mais mal positionnée

⬜ GRIS : lettre absente du mot

⏳ Le joueur dispose de MAX_GUESSES tentatives (6 essais).

⚙️ MODES DE JEU

👤 MODE JOUEUR HUMAIN

L’utilisateur tente de deviner le mot secret en un maximum de 6 essais.

🤖 MODE SOLVEUR LOGIQUE

Le programme applique une stratégie algorithmique optimisée afin de trouver le mot secret avec le minimum d’essais possible.

# 👨‍💻 AUTEURS

📌 PROJET RÉALISÉ PAR :

 -Zeraia Maya

 -Belabed Imene Zohra

 -Guettache Cerine

# 🧩 COMPÉTENCES MISES EN PRATIQUE 🧩

✔️ Algorithmes
✔️ Structures de données
✔️ Programmation modulaire en langage C
✔️ Gestion dynamique de la mémoire
✔️ Manipulation de fichiers
✔️ Résolution de problèmes logiques

