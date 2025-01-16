#!/bin/bash

echo "Iniciando a instalação de dependências para vieiraChess..."

# Função para verificar o sistema operacional
check_os() {
  if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    echo "Sistema detectado: Linux"
    install_linux
  elif [[ "$OSTYPE" == "darwin"* ]]; then
    echo "Sistema detectado: macOS"
    install_macos
  else
    echo "Sistema não suportado. Abortando."
    exit 1
  fi
}

install_linux() {
  echo "Atualizando repositórios..."
  sudo apt-get update || { echo "Erro ao atualizar repositórios. Abortando."; exit 1; }

  echo "Instalando CMake..."
  sudo apt-get install -y cmake || { echo "Erro ao instalar CMake. Abortando."; exit 1;}

  echo "Instalando Qt5 e ferramentas de desenvolvimento..."
  sudo apt-get install -y qt5-default qtbase5-dev qttools5-dev-tools || { echo "Erro ao instalar Qt. Abortando."; exit 1; }

  echo "Dependências instaladas com sucesso no Linux!"
}