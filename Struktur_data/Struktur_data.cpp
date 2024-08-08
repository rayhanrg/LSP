#include <stdio.h>
#include <string.h>

// Definisi Struktur Mahasiswa
typedef struct {
    char nama[255];
    char npm[255];
    char tempat_lahir[255];
    char tanggal_lahir[255];
    char prodi[255];
} Mahasiswa;

// Deklarasi Array dan Variabel Global
Mahasiswa mhs[100];
int count = 0;

// Fungsi untuk Menambahkan Data Mahasiswa
void tambahData(const char nama[], const char npm[], const char tempat_lahir[], const char tanggal_lahir[], const char prodi[]) {
    if (count < 100) {
        strcpy(mhs[count].nama, nama);
        strcpy(mhs[count].npm, npm);
        strcpy(mhs[count].tempat_lahir, tempat_lahir);
        strcpy(mhs[count].tanggal_lahir, tanggal_lahir);
        strcpy(mhs[count].prodi, prodi);
        count++;
        printf("Data berhasil ditambahkan\n");
    } else {
        printf("Kapasitas penuh, tidak bisa menambahkan data.\n");
    }
}

// Fungsi untuk Menampilkan Data Mahasiswa
void tampilData() {
    if (count == 0) {
        printf("Data Tidak ada\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("Nama: %s\n", mhs[i].nama);
            printf("NPM: %s\n", mhs[i].npm);
            printf("Tempat Lahir: %s\n", mhs[i].tempat_lahir);
            printf("Tanggal Lahir: %s\n", mhs[i].tanggal_lahir);
            printf("Prodi: %s\n", mhs[i].prodi);
            printf("\n");
        }
    }
}

// Fungsi untuk Menghapus Data Mahasiswa
void hapusData(int index) {
    if (index < 0 || index >= count) {
        printf("Indeks mahasiswa tidak valid.\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        mhs[i] = mhs[i + 1];
    }
    count--;
    printf("Mahasiswa pada indeks %d berhasil dihapus.\n", index + 1);
}

// Fungsi Main
int main() {
    printf("\nDaftar Mahasiswa:\n");
    tampilData();
    
    tambahData("Azkia", "0620201087", "Bandung", "2002-12-09", "Informatika");
    tambahData("Rayhan RG", "0620201086", "Garut", "2002-01-09", "Informatika");

    printf("\nDaftar Mahasiswa:\n");
    tampilData();

    printf("\nMenghapus mahasiswa kedua:\n");
    hapusData(1);

    printf("\nDaftar Mahasiswa setelah dihapus:\n");
    tampilData();

    return 0;
}