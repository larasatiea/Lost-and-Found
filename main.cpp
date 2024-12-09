#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <cstdlib> 
#include <ctime>
#include "User.h"
#include "Botol.h"
#include "Alat_Tulis.h"
#include "Lainnya.h"
#include "Transaksi.h"
#include "setID.h"
#include "tampilkan.h"
#include "hapus.h"

using namespace std;

int main(){
    initializeRandomSeed(); // supaya id random hanya dipanggil sekali
    int pilihan;
    Botol b;
    Alat_Tulis a;
    Lainnya c;


    string nama, email, NIU;
    ifstream file("botol.txt");
    vector<Botol> daftarBotol;
    int pilih;

    cout<<"Masukkan data\n"<<endl;
    cout<<"nama: ";
    cin>> nama;
    cout<<"email: \n";
    cin >> email;
    cout<<"NIU: ";
    cin>> NIU;
    cout<<"Login Berhasil!\n"<<endl;

    if (NIU == "11111") {
        cout << "Selamat datang, Admin!\n";
        while (true) {
            cout << "Menu Admin:\n";
            cout << "1. Lihat semua transaksi\n";
            cout << "2. Hapus barang\n";
            cout << "3. Keluar\n";
            cout << "Pilihan: ";
            int adminPilihan;
            cin >> adminPilihan;

        if (adminPilihan == 1) {
            void tampilkanTransaksi(); {
            tampilkanFile("transaksi.txt");
            }
        } else if (adminPilihan == 2) {
            int kategori;
            cout << "Pilih kategori:\n";
            cout << "1. Botol Minum\n";
            cout << "2. Alat Tulis\n";
            cout << "3. Lainnya\n";
            cout << "Opsiku: ";
            cin >> kategori;
            string idHapus;
            cout << "Masukkan ID barang yang ingin dihapus: ";
            cin >> idHapus;
            hapusItemSesuaiKategori(kategori, idHapus);
        } else if (adminPilihan == 3) {
            cout<<"keluar";
            return 0;
        } else {
            cout << "Pilihan tidak valid.\n";
        }  
    }
    }

    while(true){
        cout<<"Pilih menu\n";
        cout<<"1. Duh, barangku hilang\n";
        cout<<"2. Aku nemu barang nih\n";
        cout<<"Opsiku:"<<endl;
        cin>>pilih;

        if (pilih==1){
            int kategori;
            cout<< "Pilih kategori:\n";
            cout<<"1. Botol Minum\n";
            cout<<"2. Alat Tulis\n";
            cout<<"3. Lainnya\n";
            cout<<"Opsiku:"<<endl;
            cin>> kategori;

                if (kategori==1){
                    tampilkanFile("botol.txt");
                } 
                else if (kategori == 2) {
                    tampilkanFile("alattulis.txt");
                }
                else if (kategori == 3) {
                    tampilkanFile("lainnya.txt");
                }
                else {
                    cout << "Kategori tidak tersedia.\n";
                }

        if (pilih == 1) {
        cout << "Mau ambil yang mana?" << endl;
        cout << "Masukkan ID barang: ";
        string id;
        cin >> id;
        hapusItemSesuaiKategori(kategori, id);

        // Simpan log transaksi
        Transaksi t;
        t.idBarang = id;
        t.kategori = (kategori == 1 ? "Botol" : kategori == 2 ? "Alat Tulis" : "Lainnya");
        t.namaPengambil = nama;
        t.niuPengambil = NIU;
        simpanTransaksi(t);
    
        }
        cout<<"Okedeh, lain kali jangan sampai tertinggal lagi ya!";
        break;  
        }

        else if (pilih == 2) {
            int kategori;
            cout << "Pilih kategori barang yang ditemukan:\n";
            cout << "1. Botol Minum\n";
            cout << "2. Alat Tulis\n";
            cout << "3. Lainnya\n";
            cout << "Opsiku: ";
            cin >> kategori;

            if (kategori == 1) {
                b.id = generateID();  // Mengisi ID unik untuk botol
                cout << "Masukkan merk botol: ";
                cin >> b.merk;
                cout << "Masukkan warna botol: ";
                cin >> b.warna;
                cout << "Masukkan ukuran botol: ";
                cin >> b.ukuran;
                cout << "Masukkan material botol: ";
                cin >> b.material;
                cout << "Masukkan lokasi botol: ";
                cin >> b.lokasi;

                simpanBotol(b);
                cout<<"Terimakasih yaa!";
                break;
            } 

            else if (kategori == 2) {
                a.id = generateID();  // Mengisi ID unik untuk botol
                cout << "Masukkan jenis alat tulis: ";
                cin >> a.jenis;
                cout << "Masukkan merk alat tulis: ";
                cin >> a.merk;
                cout << "Masukkan warna alat tulis: ";
                cin >> a.warna;
                cout << "Masukkan ukuran alat tulis: ";
                cin >> a.ukuran;
                cout << "Masukkan material alat tulis: ";
                cin >> a.material;
                cout << "Masukkan lokasi alat tulis: ";
                cin >> a.lokasi;

                simpanAlatTulis(a);
                cout<<"Okay, terimakasih";
                break;
            }
            else if (kategori == 3) {
                c.id = generateID();  // Mengisi ID unik untuk botol
                cout << "Masukkan nama benda: ";
                cin >> c.Nama_Benda;
                cout << "Masukkan merk benda: ";
                cin >> c.merk;
                cout << "Masukkan warna benda: ";
                cin >> c.warna;
                cout << "Masukkan ukuran/detail benda: ";
                cin >> c.ukuran;
                cout << "Masukkan material benda: ";
                cin >> c.material;
                cout << "Masukkan lokasi benda: ";
                cin >> c.lokasi;
                simpanLainnya(c);
                cout<<"Okay, terimakasih";
                break;
            }
            else {
                cout << "Kategori tidak tersedia.\n";
            }

        } else {
            cout << "Pilihan tidak valid.\n";
        }
    }
    return 0;
}

