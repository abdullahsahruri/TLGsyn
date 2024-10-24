#!/bin/bash

BENCHMARKS=("c17" "c432" "c499" "c880" "c1355" "c1908") # Add more as needed
METRICS=("TLG_count" "sum_weights" "fanin")

for benchmark in "${BENCHMARKS[@]}"; do
    for metric in "${METRICS[@]}"; do
        echo "Running $benchmark with area metric: $metric"
        ./abc -c "read ./benchmarks/$benchmark.blif; strash; set_area_metric $metric; map_threshold; print_stats" > ./results/${benchmark}_${metric}.log
    done
done

echo "All benchmarks tested!"
