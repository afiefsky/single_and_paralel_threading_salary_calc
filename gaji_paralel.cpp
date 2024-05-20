#include <iostream>
#include <vector>
#include <omp.h>
#include <iomanip> // Untuk mengatur format keluaran

// Fungsi untuk menghitung gaji bersih
double hitungGajiBersih(int hariHadir, int totalHariKerja) {
    const double tunjanganHarian = 100000;
    const double potonganHarian = 50000;

    double gajiBersih = (hariHadir * tunjanganHarian) - ((totalHariKerja - hariHadir) * potonganHarian);
    return gajiBersih;
}

int main() {
    int totalHariKerja;
    std::cout << "Masukkan jumlah total hari kerja dalam sebulan: ";
    std::cin >> totalHariKerja;

    std::vector<int> kehadiran{20, 18, 15, 22}; // Contoh data hadir karyawan
    std::vector<double> gajiBersih(kehadiran.size());

    #pragma omp parallel for
    for (int i = 0; i < kehadiran.size(); ++i) {
        gajiBersih[i] = hitungGajiBersih(kehadiran[i], totalHariKerja);
    }

    std::cout << std::fixed << std::setprecision(0); // Mengatur presisi keluaran tanpa desimal
    for (int i = 0; i < gajiBersih.size(); ++i) {
        std::cout << "Gaji bersih untuk " << kehadiran[i] << " hari hadir: Rp " << gajiBersih[i] << std::endl;
    }

    return 0;
}
