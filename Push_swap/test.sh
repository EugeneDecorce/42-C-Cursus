#!/bin/bash

# Function to generate a random sequence of unique integers
generate_random_sequence() {
    local num_elements=$1
    local min_value=$2
    local max_value=$3

    # Generate a sequence of unique random integers
    local numbers=()
    while [ ${#numbers[@]} -lt $num_elements ]; do
        local rand=$((RANDOM % (max_value - min_value + 1) + min_value))
        if [[ ! " ${numbers[@]} " =~ " ${rand} " ]]; then
            numbers+=($rand)
        fi
    done

    # Join the numbers with spaces
    echo "${numbers[@]}"
}

# Parameters for random sequence generation
NUM_ELEMENTS=500  # Number of unique integers to generate
MIN_VALUE=-10000  # Minimum value (inclusive)
MAX_VALUE=10000   # Maximum value (inclusive)

# Generate the random sequence
ARG=$(generate_random_sequence $NUM_ELEMENTS $MIN_VALUE $MAX_VALUE)
RESULT=$(./push_swap $ARG | ./checker_Mac $ARG)
COUNT=$(./push_swap $ARG | wc -l)
COUNT=${COUNT// /}
leaks --atExit -- ./push_swap 3 4 2 > leaks_output.txt
LEAKS_INFO=$(grep 'total leaked bytes' leaks_output.txt)
rm leaks_output.txt

echo "Generated sequence: $ARG"
echo "Operations count: $COUNT"
echo "Check response: $RESULT"
echo "Leaks info: $LEAKS_INFO"

