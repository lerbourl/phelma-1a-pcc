EPALLE COLIN\nLERBOURG LOUIS

# Projet en cours: Plus court chemin entre sommets d'un graphe

## Commentaires

Le fichier "liste.h" a été codé lors de projets plus anciens. Dans le but de
pouvoir utiliser le fichier sans le modifier, le fichier arc.h (éléments de
liste) est adapté : définition de `ELEMENT` et `affiche_element()`.
D'autant plus que les structures sont toutes imbriquées les unes dans les
autres, nous avons choisis d'avoir un fichier .h par structure.

## Commandes utiles

* compiler avec:`make`
* recompiler les .h avec:`make clean`
* exécuter avec:`./pcc donnee_graphe.txt && echo $?`\n
récupère aussi le code d'erreur:\n
0 pas de soucis\n
1 erreur indéterminée\n
2 erreur d'ouverture de fichier)
* debugger avec:`gdb ./pcc`\n
commandes:\n
`break n` pour placer breakpoint ligne n,\n
`run` pour exécuter,\n
`step` pour avancer,\n
`list` pour montrer l'environnement de la ligne,\n
`h` pour help,\n
`q` quitter)\n
* tracer les fuites de memoire avec:`valgrind --leak-check=full ./pcc`

# Git

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
