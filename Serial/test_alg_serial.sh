# Cartella contenente i file di input
DATASET_DIR="../DataSet/targets"
ESEGUIBILE="kmeans_sequential"
OUTPUT_FILE="results_ex_datasets.txt"

# Verifica che la cartella esista
if [ ! -d "$DATASET_DIR" ]; then
  echo "Errore: La cartella $DATASET_DIR non esiste."
  exit 1
fi

# Pulizia del file di output precedente
> "$OUTPUT_FILE"

# Itera attraverso i file nella cartella "DataSet"
for FILE in "$DATASET_DIR"/*; do
  if [ -f "$FILE" ]; then
    # Ottieni solo il nome del file con estensione
    FILENAME=$(basename "$FILE")

    # Esegui il comando sull'input e cattura l'output
    echo "Eseguo $ESEGUIBILE con $FILENAME..."
    OUTPUT=$(./"$ESEGUIBILE" "$FILE")
	  echo "$FILENAME done"

    # Salva il risultato nel file di output
    echo "$FILENAME; $OUTPUT" >> "$OUTPUT_FILE"

    # echo "$FILENAME" >> "$OUTPUT_FILE"
    # echo "$OUTPUT" >> "$OUTPUT_FILE"
  fi
done

echo "Elaborazione completata. Risultati salvati in $OUTPUT_FILE."
