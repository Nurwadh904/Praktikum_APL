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

void tampilkan() {
    if (index > 0) {
        cout << "Daftar Buah Yang Tersimpan" << endl;
        double totalHarga = 0.0;
        for (int a = 0; a < index; a++) {
            cout << a + 1 << ". " << ListDaftarBuah[a].nama << " - Rp" << ListDaftarBuah[a].hargaDetail.harga << endl;
            totalHarga += ListDaftarBuah[a].hargaDetail.harga;
        }
        cout << "Total Harga: Rp" << totalHarga << endl;
    } else {
        cout << "Tidak ada daftar buah yang tersimpan" << endl;
    }
}

void tambahBuah() {
    string loop;
    do {
        tampilkan();
        if (index < max) {
            cin.ignore();
            cout << "Tambah buah yang anda inginkan: ";
            getline(cin, ListDaftarBuah[index].nama);
            cout << "Masukkan harga buah: Rp";
            cin >> ListDaftarBuah[index].hargaDetail.harga;
            index++;
            tampilkan();
            cout << "Apakah anda ingin menambahkan daftar buah lagi? (ya/tidak) : ";
            cin >> loop;
        } else {
            cout << "Kapasitas maksimum tercapai" << endl;
            cout << "Tekan 'tidak' untuk kembali : ";
            cin >> loop;
        }
    } while (loop == "ya");
}

void ubahBuah() {
    string loop;
    int indeks;
    do {
        tampilkan();
        cout << "Pilih nomor buah yang ingin anda diubah: ";
        cin >> indeks;
        cin.ignore();
        cout << "Ubah menjadi buah: ";
        getline(cin, ListDaftarBuah[indeks - 1].nama);
        cout << "Masukkan harga baru: Rp";
        cin >> ListDaftarBuah[indeks - 1].hargaDetail.harga;
        tampilkan();
        cout << "Apakah anda ingin ubah daftar buah lagi? (ya/tidak) : ";
        cin >> loop;
    } while (loop == "ya");
}

void hapusBuah() {
    string loop;
    int indeks;
    do {
        tampilkan();
        if (index > 0) {
            cout << "Hapus nomor buah yang anda inginkan: ";
            cin >> indeks;
            for (int i = indeks; i < index; i++) {
                ListDaftarBuah[i - 1] = ListDaftarBuah[i];
            }
            index--;
            tampilkan();
            cout << "Apakah anda ingin ingin menghapus lagi? (ya/tidak) : ";
            cin >> loop;
        } else {
            cout << "Daftar buah kosong. Tekan 'tidak' untuk kembali : ";
            cin >> loop;
        }
    } while (loop == "ya");
}

double hitungTotalHarga() {
    double totalHarga = 0.0;
    for (int i = 0; i < index; i++) {
        totalHarga += ListDaftarBuah[i].hargaDetail.harga;
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
                tambahBuah();
                break;
            case 2:
                ubahBuah();
                break;
            case 3:
                hapusBuah();
                break;
            case 4:
                tampilkan();
                break;
            case 5:
                cout << "Total Harga Semua Buah: Rp" << hitungTotalHarga() << endl;
                cout << "Terima kasih telah menggunakan aplikasi Toko Buah\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih 1 - 5\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}