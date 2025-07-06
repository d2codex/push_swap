#!/bin/bash

over_5500=0
total_runs=1000

for ((i = 1; i <= total_runs; i++)); do
    ARG=$(seq -1000 1000 | shuf | head -n 500 | xargs)
    COUNT=$(./push_swap $ARG | wc -l)
    
    if [ "$COUNT" -gt 5500 ]; then
        ((over_5500++))
        echo "Run $i: $COUNT 🔴"
    else
        echo "Run $i: $COUNT ✅"
    fi
done

echo "---------------------------"
echo "Total runs over 5500: $over_5500 out of $total_runs"

