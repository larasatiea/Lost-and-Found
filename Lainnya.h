#include <iostream>
#include <iostream>
#include <fstream>

using namespace std;

class Lainnya{
    public:
        string id;
        string Nama_Benda;
        string merk;
        string warna;
        string ukuran;
        string material;
        string lokasi;
};


void simpanLainnya(const Lainnya& c) {
    ofstream file("lainnya.txt", ios::app);  // Membuka file untuk menambah data (append)
    if (file.is_open()) {
        file << "ID: " << c.id << ",";
        file << "Nama Benda: " << c.Nama_Benda<< ",";
        file << "Merk: " << c.merk<< ",";
        file << "Warna: " << c.warna<< ",";
        file << "Ukuran: " << c.ukuran<< ",";
        file << "Material: " << c.material<< ",";
        file << "Lokasi: " << c.lokasi<<"\n";
        file.close();
        cout << "Data barang berhasil disimpan!\n";
    } else {
        cout << "Gagal membuka file lainnya.txt untuk menyimpan data.\n";
    }
}