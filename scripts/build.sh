#!/bin/bash
echo "Compilando vieiraChess!"
PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"

if [ ! -d "$PROJECT_ROOT/build" ]; then
  echo "Criando diretório $PROJECT_ROOT/build..."
  mkdir "$PROJECT_ROOT/build"
fi

cd "$PROJECT_ROOT/build" || { echo "Erro ao acessar ../build. Abortando."; exit 1; }

echo "Configuração do projeto com cmake" 
(cmake "$PROJECT_ROOT" && cmake --build .) || { echo "Erro de compilação"; exit 1; }

echo "Compilação finalizada" 
