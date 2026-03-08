#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Fungsi menghitung cicilan
double hitungCicilan(double jumlah, int bulan, double bungaRate, double admin) {
    double totalBunga = jumlah * bungaRate * bulan;
    double totalBayar = jumlah + totalBunga + admin;
    return totalBayar / bulan;
}

int main() {

    char ulang;

    do {

        cout << "=== SMARTLOAN PRO ===" << endl;

        string nama;
        double jumlah;

        cout << "\nMasukkan nama: ";
        getline(cin, nama);

        cout << "Masukkan jumlah pinjaman: ";
        cin >> jumlah;

        if (cin.fail() || jumlah <= 0) {
            cout << "Error: Jumlah pinjaman harus lebih dari 0!\n";
            return 0;
        }

        int pilihanBulan;
        int bulan;
        double bungaRate;

        cout << "\nPilih lama cicilan:\n";
        cout << "1. 6 bulan  (Bunga 0.05)\n";
        cout << "2. 12 bulan (Bunga 0.06)\n";
        cout << "3. 24 bulan (Bunga 0.08)\n";
        cout << "Pilihan: ";
        cin >> pilihanBulan;

        switch (pilihanBulan) {
        case 1:
            bulan = 6;
            bungaRate = 0.05;
            break;
        case 2:
            bulan = 12;
            bungaRate = 0.06;
            break;
        case 3:
            bulan = 24;
            bungaRate = 0.08;
            break;

        default:
            cout << "Pilihan tidak tersedia!\n";
            return 0;
        }

        double admin = 5000;

        double totalBunga = jumlah * bungaRate * bulan;
        double totalBayar = jumlah + totalBunga + admin;
        double cicilan = hitungCicilan(jumlah, bulan, bungaRate, admin);

        cout << fixed << setprecision(2);

        cout << "\n=== HASIL PINJAMAN ===" << endl;
        cout << "Nama            : " << nama << endl;
        cout << "Jumlah Pinjaman : " << jumlah << endl;
        cout << "Lama Cicilan    : " << bulan << " bulan" << endl;
        cout << "Total Bunga     : " << totalBunga << endl;
        cout << "Biaya Admin     : " << admin << endl;
        cout << "Total Bayar     : " << totalBayar << endl;
        cout << "Cicilan/Bulan   : " << cicilan << endl;

        cout << "\n=== TABEL CICILAN ===" << endl;
        for (int i = 1; i <= bulan; i++) {
            cout << "Bulan " << i << " : " << cicilan << endl;
        }

        cout << "\nApakah anda ingin mengajukan pinjaman lagi? (Y/N): ";
        cin >> ulang;
        cin.ignore();

        cout << endl;

    } while (ulang == 'Y' || ulang == 'y');

    cout << "Terima kasih telah menggunakan SMARTLOAN PRO.\n";

    return 0;
}