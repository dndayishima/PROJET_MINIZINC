# PROJET_MINIZINC
Application QT faisant appel à un solver MiniZinc (Gecode).

## Installation de minizinc
Cette application fait appel à la commande `minizinc`. Tout d'abord, vérifiez que vous avez cette commande sur votre poste.
```bash
minizinc
```

Si cette dernière n'est pas installée, vous pouvez utiliser le script `mzn_install.sh`.
**Attention :** Ce script fait l'installation de tous les outils dont `minizinc` aura besoin pour fonctionner. On parle notamment des `solvers`. Une compilation des sources des solvers notamment **Gecode** est faite. Ceci pourra prendre un petit peu de temps.
```bash
cd script
./mzn_install.sh
```

## Initialisation des jeux (données et modèles)
Avant d'exécuter l'application avec QTCreaor par exemple, assurez-vous que les données et modèles nécessaires soient bien copiées dans le répertoire `$HOME/.minizinc-games`. Si ce n'est pas le cas, le script `init.sh` le fera.
```bash
cd script
./init.sh
```