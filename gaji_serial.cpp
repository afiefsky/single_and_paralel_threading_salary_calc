#include <iostream>
#include <vector>
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

    std::cout << std::fixed << std::setprecision(0); // Mengatur presisi keluaran tanpa desimal
    for (int hariHadir : kehadiran) {
        double gajiBersih = hitungGajiBersih(hariHadir, totalHariKerja);
        std::cout << "Gaji bersih untuk " << hariHadir << " hari hadir: Rp " << gajiBersih << std::endl;
    }

    return 0;
}
