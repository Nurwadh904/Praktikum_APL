#include <iostream>
#include <string>
using namespace std;

#define max 15

struct Harga {
    double harga;
};

struct Buah {
    string nama;
    Harga hargaDetail;
};

Buah ListDaftarBuah[max];
int index = 0;

void tampilkan(Buah *listDaftarBuah, int *index) {
    if (*index > 0) {
        cout << "Daftar Buah Yang Tersimpan" << endl;
        double totalHarga = 0.0;
        for (int a = 0; a < *index; a++) {
            cout << a + 1 << ". " << listDaftarBuah[a].nama << " - Rp" << listDaftarBuah[a].hargaDetail.harga << endl;
            totalHarga += listDaftarBuah[a].hargaDetail.harga;
        }
        cout << "Total Harga: Rp" << totalHarga << endl;
    } else {
        cout << "Tidak ada daftar buah yang tersimpan" << endl;
    }
}

void tambahBuah(Buah *listDaftarBuah, int *index) {
    string loop;
    do {
        tampilkan(listDaftarBuah, index);
        if (*index < max) {
            cin.ignore();
            cout << "Tambah buah yang anda inginkan: ";
            getline(cin, listDaftarBuah[*index].nama);
            cout << "Masukkan harga buah: Rp";
            cin >> listDaftarBuah[*index].hargaDetail.harga;
            (*index)++;
            tampilkan(listDaftarBuah, index);
            cout << "Apakah anda ingin menambahkan daftar buah lagi? (ya/tidak) : ";
            cin >> loop;
        } else {
            cout << "Kapasitas maksimum tercapai" << endl;
            cout << "Tekan 'tidak' untuk kembali : ";
            cin >> loop;
        }
    } while (loop == "ya");
}

void ubahBuah(Buah *listDaftarBuah, int *index) {
    string loop;
    int indeks;
    do {
        tampilkan(listDaftarBuah, index);
        cout << "Pilih nomor buah yang ingin anda diubah: ";
        cin >> indeks;
        cin.ignore();
        cout << "Ubah menjadi buah: ";
        getline(cin, listDaftarBuah[indeks - 1].nama);
        cout << "Masukkan harga baru: Rp";
        cin >> listDaftarBuah[indeks - 1].hargaDetail.harga;
        tampilkan(listDaftarBuah, index);
        cout << "Apakah anda ingin ubah daftar buah lagi? (ya/tidak) : ";
        cin >> loop;
    } while (loop == "ya");
}

void hapusBuah(Buah *listDaftarBuah, int *index) {
    string loop;
    int indeks;
    do {
        tampilkan(listDaftarBuah, index);
        if (*index > 0) {
            cout << "Hapus nomor buah yang anda inginkan: ";
            cin >> indeks;
            for (int i = indeks; i < *index; i++) {
                listDaftarBuah[i - 1] = listDaftarBuah[i];
            }
            (*index)--;
            tampilkan(listDaftarBuah, index);
            cout << "Apakah anda ingin ingin menghapus lagi? (ya/tidak) : ";
            cin >> loop;
        } else {
            cout << "Daftar buah kosong. Tekan 'tidak' untuk kembali : ";
            cin >> loop;
        }
    } while (loop == "ya");
}

double hitungTotalHarga(Buah *listDaftarBuah, int *index) {
    double totalHarga = 0.0;
    for (int i = 0; i < *index; i++) {
        totalHarga += listDaftarBuah[i].hargaDetail.harga;
    }
    return totalHarga;
}

int main() {
    string username;
    string password;
    int ulang = 0;
    do {
        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        if (username == "Nurwadah" && password == "138") {
            cout << "Login berhasil" << endl;
            break;
        } else {
            cout << "Username atau password salah. Silakan coba lagi." << endl;
            ulang++;
        }
    } while (ulang < 3);

    if (ulang == 3) {
        cout << "Anda telah mencoba login sebanyak 3 kali. Aplikasi akan keluar." << endl;
        return 0;
    }

    int pilihan;
    do {
        cout << "===== Toko Buah =====" << endl;
        cout << "1. Tambah Buah" << endl;
        cout << "2. Ubah Buah" << endl;
        cout << "3. Hapus Buah" << endl;
        cout << "4. Tampilkan Daftar Buah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahBuah(ListDaftarBuah, &index);
                break;
            case 2:
                ubahBuah(ListDaftarBuah, &index);
                break;
            case 3:
                hapusBuah(ListDaftarBuah, &index);
                break;
            case 4:
                tampilkan(ListDaftarBuah, &index);
                break;
            case 5:
                cout << "Total Harga Semua Buah: Rp" << hitungTotalHarga(ListDaftarBuah, &index) << endl;
                cout << "Terima kasih telah menggunakan aplikasi Toko Buah\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih 1 - 5\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}