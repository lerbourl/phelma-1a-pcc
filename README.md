# Projet en cours: Plus court chemin entre sommets d'un graphe

## Collaborateurs

EPALLE COLIN, LERBOURG LOUIS

## Structures

Il est arrivé un moment ou nous avons eu besoin d'utiliser 2 fois le fichier liste, mais pour des éléments différents (liste d'arc et table de hachage). Nous avons alors découvert le type abstrait(merci M. Cayre), et l'utilisation du type void*!!!! Pour des raisons de simplicité, vu l'avancement de notre code, nous n'avons pas adapté toutes nos Structures en type abstrait (ce n'était pas l'envie qui manquait!). Certaines structures sont donc restées "classiques" (graphe, sommet), les autres ont été codées (ou recodée) de manière abstraite, pour des raisons de fonctionnement du code (liste, table de hachage, hach-sommet, arc). C'est l'occasion pour nous de s'entraîner à manipuler le type abstrait, qui est (nous nous en sommes rendu compte) très très utile dans la programmation structurée.

## Commentaires

Le fichier "liste.h" a été codé lors de projets plus anciens. Dans le but de
pouvoir utiliser le fichier sans le modifier, le fichier arc.h (éléments de
liste) est adapté : définition de `ELEMENT` et `affiche_element()`.
D'autant plus que les structures sont toutes imbriquées les unes dans les
autres, nous avons choisis d'avoir un fichier .h par structure.

## ERREURS

Erreurs exit
* gerées par `err_ctrl` : 2
* 0 pas d'erreurs
* 1 erreur non définie
* 2 erreur malloc `ajout_tete` (liste.c)
* 3 erreur malloc `supprimer_tete` (liste.c)
* 4 erreur malloc `copie` (liste.c)

## Commandes utiles

* compiler avec:`make`
* recompiler les .h avec:`make clean`
* exécuter avec:`./pcc donnee_graphe.txt ; echo $?` (récupère aussi le code
    d'erreur: 0 pas de soucis, 1 erreur indéterminée, 2 erreur d'ouverture de
    fichier)
* debugger avec:`gdb ./pcc` (commandes:`break n` pour placer breakpoint ligne n,
 `run` pour exécuter, `step` pour avancer, `list` pour montrer l'environnement
 de la ligne, `h` pour help, `q` quitter)
* tracer les fuites de memoire avec:`valgrind --leak-check=full ./pcc`

## Git

stp ne pas commit les .o!! make clean d'abord.

* `git init <project name>` créer le repository
* `git clone <url>` importer le repository
* `git remote add origin <url>` ajouter une origine en ligne
* `git remote -v` lister les origines
* `git add <file>` ajouter des fichiers, * pour tous
* `git reset <file>` retirer un fichier
* `commit -m "commit message" <file> ` commit les fichiers -a pour tout cibler
* `git fetch origin master` charger depuis l'origine
* `git push origin master` partager les fichiers à l'origine
* `git status` liste des changements
* `git log` liste des commits
* `git command --help` aide
