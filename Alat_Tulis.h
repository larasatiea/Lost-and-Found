#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class Alat_Tulis{
    public:
        string id;
        string jenis;
        string merk;
        string warna;
        string ukuran;
        string material;
        string lokasi;
};

// Fungsi untuk menyimpan data alat tulis ke dalam file
void simpanAlatTulis(const Alat_Tulis& a) {
    ofstream file("alattulis.txt", ios::app);  // Membuka file untuk menambah data (append)
    if (file.is_open()) {
        
        file << "ID: " << a.id << ",";
        file << "Jenis: " << a.jenis<< ",";
        file << "Merk: " << a.merk<< ",";
        file << "Warna: " << a.warna<< ",";
        file << "Ukuran: " << a.ukuran<< ",";
        file << "Material: " << a.material<< ",";
        file << "Lokasi: " << a.lokasi<<"\n";
        file.close();
        cout << "Data alat tulis berhasil disimpan!\n";
    } else {
        cout << "Gagal membuka file alattulis.txt untuk menyimpan data.\n";
    }
}