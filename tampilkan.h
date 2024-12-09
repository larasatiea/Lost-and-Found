#include <iostream>
#include <fstream>

using namespace std;

// Fungsi untuk menampilkan isi file berdasarkan nama file yang diberikan
void tampilkanFile(const string& namaFile) {
    ifstream file(namaFile);  // Membuka file berdasarkan nama yang diberikan
    if (file.is_open()) {
        string line;
        bool isEmpty = true;  // Menandakan apakah file kosong atau tidak
        while (getline(file, line)) {  // Membaca file baris per baris
            isEmpty = false;
            cout << line << endl;  // Menampilkan setiap baris
        }
        if (isEmpty) {
            cout << "File kosong.\n";
        }
        file.close();  // Menutup file setelah selesai
    } else {
        cout << "Gagal membuka file: " << namaFile << endl;  // Jika file tidak bisa dibuka
    }
}

void tampilkanTransaksi() {
    tampilkanFile("const std::string &transaksi.txt");
}