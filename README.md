Recherche de mots
Description
Ce programme recherche des mots dans une grille de lettres. La grille est de taille 12x12 et est constituée de caractères alphabétiques. Les mots sont recherchés horizontalement et verticalement, de gauche à droite, de droite à gauche, de haut en bas et de bas en haut. Le programme affiche les lettres inutilisées de la grille après avoir recherché tous les mots.

Compilation
Pour compiler le programme, utilisez la commande suivante :

go

make
Cela générera un exécutable nommé wordsearch.

Exécution
Pour exécuter le programme, utilisez la commande suivante :

bash

./wordsearch <nom_du_fichier>
Remplacez <nom_du_fichier> par le nom du fichier contenant la grille et la liste des mots à rechercher.

Format du fichier d'entrée
Le fichier d'entrée doit être formaté de la manière suivante :

La grille de 12x12 caractères, chaque ligne étant suivie d'un caractère de saut de ligne ('\n').
Une ligne vide séparant la grille de la liste des mots.
La liste des mots à rechercher, chaque mot étant suivi d'un caractère de saut de ligne ('\n').
Par exemple :


abcdefghijkl
mnopqrstuvwx
yzABCDEFGHIJK
LMNOPQRSTUVWX
YZabcdefghijk
lmnopqrstuvwx
YZABCDEFGHIJK
lmnopqrstuvwx
yzABCDEFGHIJK
LMNOPQRSTUVWX
yzabcdefghijk
lmnopqrstuvwx

mot1
mot2
mot3
Tests
Des tests unitaires et des tests d'intégration ont été inclus pour valider le bon fonctionnement du programme. Les tests unitaires sont écrits à l'aide de CUnit et les tests d'intégration sont écrits à l'aide de Bats.

Pour exécuter les tests unitaires, utilisez la commande suivante :

go

make test
Pour exécuter les tests d'intégration, assurez-vous que Bats est installé sur votre système, puis utilisez la commande suivante :


bats integration_tests.bats
Nettoyage
Pour nettoyer les fichiers générés lors de la compilation et des tests, utilisez la commande suivante :

go

make clean
Cela supprimera les fichiers exécutables, les fichiers objet et les fichiers temporaires utilisés pour les tests.
