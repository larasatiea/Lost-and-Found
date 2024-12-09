#include <string>
#include <vector>
#include <cstdlib> // Untuk fungsi rand()
#include <ctime>   // Untuk seeding random

using namespace std;

// Seed random hanya sekali
void initializeRandomSeed() {
    srand(time(0));
}

// Fungsi untuk menghasilkan ID unik
string generateID() {
    srand(time(0)); // Seed random number
    string id = to_string(rand() % 100000); // ID berupa angka random 0-99999
    return id;
}