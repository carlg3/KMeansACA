#!/bin/bash
MAX_INT=$1
DATASET_DIR="../DataSet/weak"
DIR_NAME=$(basename "$DATASET_DIR")

ESEGUIBILE="kmeans_parallel"

FILES=($(ls "$DATASET_DIR" | sort -V))
FILE_COUNT=${#FILES[@]}

for ((i=0; i<FILE_COUNT && MAX_INT>0; i++))
do
    np=$((i+1))
    FILE="$DIR_NAME/${FILES[$i]}"
    echo "Esecuzione con -np $np su file $FILE"

    OUTPUT=$(mpirun -np $np --oversubscribe "$ESEGUIBILE" "$FILE")
    echo "$OUTPUT"
done