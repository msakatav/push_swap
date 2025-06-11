#!/bin/bash

if [ -z "$1" ]; then
	echo "Usage: $0 <number_of_values>"
	exit 1
fi

COUNT=$1
MIN=-1000
MAX=1000

generate_random_numbers() {
	local count=$1
	local min=$2
	local max=$3
	local -a numbers=()

	while [ "${#numbers[@]}" -lt "$count" ]; do
		num=$((RANDOM % (max - min + 1) + min))
		if [[ ! " ${numbers[@]} " =~ " ${num} " ]]; then
			numbers+=($num)
		fi
	done
	echo "${numbers[@]}"
}

VALUES=$(generate_random_numbers "$COUNT" "$MIN" "$MAX")

# echo "Generated values: $VALUES"

TMP_FILE=$(mktemp)
./push_swap $VALUES > "$TMP_FILE"
STEP_COUNT=$(wc -l < "$TMP_FILE")

echo "Operation count: $STEP_COUNT"

RESULT=$(./checker $VALUES < "$TMP_FILE")
echo "Checker result: $RESULT"

rm "$TMP_FILE"