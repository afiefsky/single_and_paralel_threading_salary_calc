#!/bin/bash

# Kompilasi program tanpa paralelisme
clang++ -std=c++17 -o gaji_serial gaji_serial.cpp

# Kompilasi program dengan paralelisme (pastikan LLVM diinstal dengan dukungan OpenMP)
clang++ -std=c++17 -Xpreprocessor -fopenmp -lomp -o gaji_paralel gaji_paralel.cpp

echo "Pengujian tanpa paralelisme:"
total_hari_kerja=20
for hadir_hari in 20 18 15 22; do
    echo "Jumlah hari hadir: $hadir_hari"
    ./hasil_gaji_serial <<< $total_hari_kerja
done

echo "Pengujian dengan paralelisme:"
for threads in 2 4 8; do
    echo "Jumlah thread: $threads"
    export OMP_NUM_THREADS=$threads
    for hadir_hari in 20 18 15 22; do
        echo "Jumlah hari hadir: $hadir_hari"
        ./hasil_gaji_paralel <<< $total_hari_kerja
    done
done
