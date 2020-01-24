#!/bin/bash

echo "Copie des modèles et données (mzn + dzn) dans le répertoire ~/.minizinc-games"
mkdir -p $HOME/.minizinc-games
cp ../MiniZinc/game_1_mzn/* $HOME/.minizinc-games
echo "TERMINÉ"

