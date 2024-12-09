#include <iostream>
#include <iostream>
#include <fstream>

using namespace std;

class Transaksi {
    public:
        string idBarang;
        string kategori;
        string namaPengambil;
        string niuPengambil;
};


void simpanTransaksi(const Transaksi& t) {
    ofstream file("transaksi.txt", ios::app);
    if (file.is_open()) {
        file << "ID Barang: " << t.idBarang << ", ";
        file << "Kategori: " << t.kategori << ", ";
        file << "Nama Pengambil: " << t.namaPengambil << ", ";
        file << "NIU Pengambil: " << t.niuPengambil << "\n";
        file.close();
        cout << "Data transaksi berhasil disimpan!\n";
    } else {
        cout << "Gagal membuka file transaksi.txt untuk menyimpan data.\n";
    }
}