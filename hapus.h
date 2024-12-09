#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool hapusItemDariFile(const string& namaFile, const string& idHapus) {

//Membaca seluruh isi file
ifstream fileInput(namaFile);
if (!fileInput.is_open()) {
    cout << "Gagal membuka file: " << namaFile << endl;
    return false;
}

// Vektor untuk menyimpan baris-baris yang akan dipertahankan
vector<string> barisSisa;
string baris;
bool itemDitemukan = false;

// Baca file baris per baris
while (getline(fileInput, baris)) {
    // Cari posisi ID dalam baris
    size_t posId = baris.find("ID: ");
    if (posId != string::npos) {
        // Ekstrak ID dari baris
        size_t posKoma = baris.find(",", posId);
        string idDalamBaris = baris.substr(posId + 4, posKoma - (posId + 4));

        // Jika ID tidak cocok, simpan baris
        if (idDalamBaris != idHapus) {
            barisSisa.push_back(baris);
        } else {
            itemDitemukan = true;
        }
    }
}

fileInput.close();
// Tulis ulang file dengan baris-baris yang tersisa
ofstream fileOutput(namaFile, ios::trunc);
    if (!fileOutput.is_open()) {
        cout << "Gagal membuka file untuk menulis: " << namaFile << endl;
        return false;
    }

    // Tulis ulang baris-baris yang tersisa
    for (const auto& barisYangDisimpan : barisSisa) {
        fileOutput << barisYangDisimpan << endl;
    }
    fileOutput.close();

    if (itemDitemukan) {
        cout << "Item dengan ID " << idHapus << " berhasil dihapus dari " << namaFile << endl;
        return true;
    } else {
        cout << "Tidak ditemukan item dengan ID " << idHapus << " di " << namaFile << endl;
        return false;
    }
}

// Fungsi untuk memilih file yang sesuai berdasarkan kategori
void hapusItemSesuaiKategori(int kategori, const string& idHapus) {
    bool berhasilDihapus = false;

    switch(kategori) {
        case 1:
            berhasilDihapus = hapusItemDariFile("botol.txt", idHapus);
            break;
        case 2:
            berhasilDihapus = hapusItemDariFile("alattulis.txt", idHapus);
            break;
        case 3:
            berhasilDihapus = hapusItemDariFile("lainnya.txt", idHapus);
            break;
        default:
            cout << "Kategori tidak valid." << endl;
            return;
    }

    if (berhasilDihapus) {
        cout << "Proses penghapusan selesai." << endl;
    }
}