#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Botol{
    public:
        string id;
        string merk;
        string warna;
        string ukuran;
        string material;
        string lokasi;
};

// Fungsi untuk menyimpan data botol ke dalam file
void simpanBotol(const Botol& b) {
    ofstream file("botol.txt", ios::app);  // Membuka file untuk menambah data
    if (file.is_open()) {
        
        file << "ID: " << b.id << ",";
        file << "Merk: " << b.merk << ",";
        file << "Warna: " << b.warna << ",";
        file << "Ukuran: " << b.ukuran << ",";
        file << "Material: " << b.material << ",";
        file << "Lokasi: " << b.lokasi <<"\n";
        file.close();
        cout << "Data botol berhasil disimpan!\n";
    } else {
        cout << "Gagal membuka file botol.txt untuk menyimpan data.\n";
    }
}