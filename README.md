# Recherche de plus court chemin dans un graphe

Ce projet a pour but de fournir les outils utiles à l'exploitation d'un graphe dont les données sont organisées dans un fichier. L'utilisateur peut entrer le nom de deux sommets, afin de rechercher le plus court chemin entre ces sommets dans ce graphe.
Une application est le calcul d'itinéraires, dans des réseaux de transports comme les autoroutes ou les métros par exemple.
La réalisation du projet s'effectue dans le cadre de la première année à PHELMA en PET.

## Utiliser nos programmes

```
git clone https://github.com/lerbourl/phelma-1a-pcc.git
```
Ou aller directement à PHELMA sur:
`/users/phelma/phelma2018/mon-login/tdinfo/seance15.`

### Prérequis

Les outils de base de développement en C sont suffisants pour compiler nos sources. GCC comme compilateur (changer dans le makefile si autre compilateur) ainsi que les librairies standard.

### Installation

générer l'exécutable `pcc` avec:
```
make
```

Si vous souhaitez modifier des fichiers headers (.h), ne pas oublier de faire `make clean`, si besoin de regénèrer les objets (.o).

### Exécution du programme

`./pcc nom_du_graphe.txt`

notons que d'autres formats de fichiers sont supportés comme le csv. Le fichier doit avoir un certain formatage défini dans le cahier des charges, voir exemple:

```
2 3
Sommets du graphe
0 0.5 	0.95	M1	Aaa
1 0.1 	0.7 	M1	Baa
Arêtes du graphe : noeud1 noeud2 valeur
0 1 5
0 2 20
0 3 40
```

on peut tester les fuites de mémoire, et récupérer ce que retourne le programme en cas d'erreur avec la commande suivante:
`valgrind --leak-check=full ./pcc nom_du_graphe.txt ; echo $?`

### que faire ensuite?

Entrer le nom ou l'index de deux sommets du graphes, et laissez à nos algorithmes le temps de vous trouver l'absolu plus court chemin ! Vous n'avez pas à vous soucier des majuscules/minuscules !

ATTENTION
Pour les caractères avec accents ou cédilles, les fonctions de changement de case ne fonctionnent pas, il faut rentrer la bonne case.

## Tests et erreurs

### Compilation

`make tests`

### Exécution

`valgrind --leak-check=full ./tests nom_du_graphe.txt ; echo $?`
conseil : lire le code de tests.c en parallèle pour comprendre la pertinence des tests.

### Recupération des erreurs d'exit

* gerées par `err_ctrl()` : 2
* 0 pas d'erreurs
* 1 erreur non définie
* 2 erreur calloc `ajout_tete` (liste.c)
* 3 erreur calloc `supprimer_tete` (liste.c)
* 4 erreur calloc `copie` (liste.c)

## Logiciels qui ont servi

* [Git](https://git-scm.com/) - Gestionnaire de version utilisé, repo sur github
* [Atom](https://atom.io/) - IDE Louis
* [Kate](https://kate-editor.org/) - IDE Colin

## Auteurs

* Colin EPALLE
* Louis LERBOURG

Voir la liste des contributeurs [contributors](https://github.com/lerbourl/phelma-1a-pcc/graphs/contributors)
