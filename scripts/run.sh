#!/bin/bash
PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"

BINARIO="$PROJECT_ROOT/build/vieiraChess"

if [ ! -f "$BINARIO" ]; then
  echo "Erro: O binário $BINARIO não foi encontrado. Compile primeiro usando build.sh."
  exit 1
fi

echo "Executando $BINARIO..."

"$BINARIO" "$@"

echo "Execução finalizada."