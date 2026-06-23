# Projet-Mini-Shell-
I’m excited to share my project — a mini shell developed in C. This shell is capable of executing both external commands (such as cd, pwd, etc.) and internal commands, providing core functionalities similar to those of a standard Unix shell.
watch the link of the video : https://drive.google.com/file/d/1Y63qG-bol6rdy58pk_ViRofKBG7aqWR9/view?usp=sharing

Implémentation d'un **mini-shell** en langage **C**, capable d'interpréter et d'exécuter des commandes simples ainsi que des commandes internes (builtins), à la manière d'un shell Unix basique.

## Fonctionnalités

- Lecture et exécution de commandes saisies par l'utilisateur
- Exécution de commandes système externes (via `fork`/`exec`)
- Gestion de commandes internes (builtins) : par exemple `cd`, `exit`, `pwd`...
- Boucle d'invite de commande interactive
- Fonctions utilitaires pour le traitement des entrées (découpage de la ligne de commande, gestion des arguments, etc.)

## Structure du projet

| Fichier | Description |
|---|---|
| `shell.c` | Point d'entrée du programme et boucle principale du shell |
| `shell.h` | Déclarations des fonctions et structures utilisées dans le projet |
| `bultain.c` | Implémentation des commandes internes (builtins) du shell |
| `utils.c` | Fonctions utilitaires (parsing, gestion de chaînes, etc.) |
| `shell` | Exécutable compilé du shell |

## Prérequis

- Un compilateur C (`gcc` ou équivalent)
- Un système Unix/Linux (ou WSL sous Windows)

## Compilation

```bash
gcc -o shell shell.c bultain.c utils.c
```

## Utilisation

Lancer le shell compilé :

```bash
./shell
```

Une invite de commande s'affiche, dans laquelle on peut saisir des commandes comme :

```bash
ls -l
pwd
cd ..
exit
```

## Technologies utilisées

- **Langage C**
- Appels système Unix (`fork`, `exec`, `wait`, etc.)

## Auteur

Projet développé par **yahyasafadi**.
