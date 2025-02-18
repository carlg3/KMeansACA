#!/bin/bash

# TEST sui tempi di esecuzione con 1..MAX_NP processi in parallelo

# OUTPUT_FILE="dump.txt"

# Controlla che sia stato passato un argomento
# if [ $# -ne 1 ]; then
#     echo "Uso: $0 <numero_max_np>"
#     exit 1
# fi

# Numero massimo di processi da utilizzare
MAX_NP=$1

# Dataset da utilizzare
FILE=$2
FILENAME=$(basename "$FILE")
echo "Uso $FILENAME"

# File hostfile e percorso del file eseguibile
HOSTFILE="../hostfile"
ESEGUIBILE="kmeans_parallel"

# Esegui il comando per np da 1 a MAX_NP
for np in $(seq 1 $MAX_NP)
do
    echo "Esecuzione con -np $np..."

    OUTPUT=$(mpirun -np $np --oversubscribe "$ESEGUIBILE" "$FILE")

    # echo "$OUTPUT" >> "$OUTPUT_FILE"
    echo "$OUTPUT"
done

echo "Elaborazione completata." # Risultati salvati in $OUTPUT_FILE."