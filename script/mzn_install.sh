#!/bin/bash

# https://pmateusz.github.io/linux/2018/11/11/minizinc-installation-on-debian.html

echo "Téléchargement MiniZincIDE..."
wget https://github.com/MiniZinc/MiniZincIDE/releases/download/2.2.3/MiniZincIDE-2.2.3-bundle-linux-x86_64.tgz

sudo mkdir -p /opt/minizinc/2.2.3

sudo tar -xf MiniZincIDE-2.2.3-bundle-linux-x86_64.tgz -C /opt/minizinc/2.2.3

rm MiniZincIDE-2.2.3-bundle-linux-x86_64.tgz

echo "Création d'un lien symbolique - exécutable..."
sudo ln -s /opt/minizinc/2.2.3/MiniZincIDE-2.2.3-bundle-linux/bin/minizinc /bin/minizinc

echo "Installation des pré-requis pour Gecode..."
sudo apt-get --yes install g++-6 cmake qt5-qmake qtbase5-dev qtbase5-dev qtdeclarative5-dev qt5-default

echo "Télechargement de Gecode + Compilation..."
wget --quiet https://github.com/Gecode/gecode/archive/release-6.1.0.tar.gz
tar -xf release-6.1.0.tar.gz
rm release-6.1.0.tar.gz
cd gecode-release-6.1.0 && ./configure --prefix=/opt/gecode-6.1.0 --enable-gist && make -j 4 && sudo make install

echo "Création d'un lien symbolique - exécutable Gecode..."
cd /usr/bin && sudo ln -s /opt/gecode-6.1.0/bin/fzn-gecode fzn-gecode

echo '/opt/gecode-6.1.0/lib' | sudo tee /etc/ld.so.conf.d/gecode.conf && sudo ldconfig

cd /opt/MiniZincIDE-2.2.3-bundle-linux/bin/ && sudo rm fzn-gecode

echo "=== Fin des installation ! ==="
