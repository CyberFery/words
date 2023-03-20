# Recherche de mots

## Introduction
Ce programme est une implémentation du jeu de recherche de mots. Le but est de trouver les mots cachés dans une grille de lettres. Les mots peuvent être cachés dans les quatre directions principales (gauche-droite, droite-gauche, haut-bas et bas-haut). Les lettres inutilisées dans la grille sont affichées à la fin du jeu.

## Compilation
Pour compiler le programme, exécutez la commande `make`. Cela générera un exécutable appelé `wordsearch`.

## Utilisation
Le programme prend un nom de fichier en argument. Le fichier doit contenir une grille de lettres suivie d'une ligne vide et d'une liste de mots à trouver, un par ligne. Les lettres de la grille doivent être alphabétiques (minuscules ou majuscules) et la grille doit être un carré de 12x12. Les mots à trouver doivent également être alphabétiques.

Pour exécuter le programme, utilisez la commande suivante : `./wordsearch <filename>`. Le programme affichera les lettres inutilisées après avoir trouvé tous les mots.

## Exemples
Le répertoire `examples` contient des exemples de fichiers d'entrée valides. Pour exécuter le programme sur l'un de ces fichiers, utilisez la commande suivante : `./wordsearch examples/<filename>`.

## Tests
Le programme a été testé à l'aide du framework de test unitaire CUnit et du framework de test d'acceptation BATS. Pour exécuter les tests, utilisez la commande `make test`.

## Auteur
Ce programme a été écrit par [Yacine Ferrat].
