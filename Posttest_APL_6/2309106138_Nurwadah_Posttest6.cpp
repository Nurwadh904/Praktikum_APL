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

void tampilkan(Buah *listDaftarBuah, int index) {
    if (index > 0) {
        cout << "Daftar Buah Yang Tersimpan" << endl;
        double totalHarga = 0.0;
        for (int a = 0; a < index; a++) {
            cout << a + 1 << ". " << listDaftarBuah[a].nama << " - Rp" << listDaftarBuah[a].hargaDetail.harga << endl;
            totalHarga += listDaftarBuah[a].hargaDetail.harga;
        }
        cout << "Total Harga: Rp" << totalHarga << endl;
    } else {
        cout << "Tidak ada daftar buah yang tersimpan" << endl;
    }
}

void tambahBuah(Buah *listDaftarBuah, int &index) {
    string loop;
    do {
        tampilkan(listDaftarBuah, index);
        if (index < max) {
            cin.ignore();
            cout << "Tambah buah yang anda inginkan: ";
            getline(cin, listDaftarBuah[index].nama);
            cout << "Masukkan harga buah: Rp";
            cin >> listDaftarBuah[index].hargaDetail.harga;
            index++;
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

void bubbleSortDescending(Buah *listDaftarBuah, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (listDaftarBuah[j].nama < listDaftarBuah[j + 1].nama) {
                Buah temp = listDaftarBuah[j];
                listDaftarBuah[j] = listDaftarBuah[j + 1];
                listDaftarBuah[j + 1] = temp;
            }
        }
    }
}

void selectionSortAscending(Buah *listDaftarBuah, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (listDaftarBuah[j].hargaDetail.harga < listDaftarBuah[minIndex].hargaDetail.harga) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Buah temp = listDaftarBuah[i];
            listDaftarBuah[i] = listDaftarBuah[minIndex];
            listDaftarBuah[minIndex] = temp;
        }
    }
}

void quickSortDescending(Buah *listDaftarBuah, int low, int high) {
    if (low < high) {
        int pivotIndex = low;
        double pivotValue = listDaftarBuah[high].hargaDetail.harga;
        for (int i = low; i < high; i++) {
            if (listDaftarBuah[i].hargaDetail.harga > pivotValue) {
                Buah temp = listDaftarBuah[i];
                listDaftarBuah[i] = listDaftarBuah[pivotIndex];
                listDaftarBuah[pivotIndex] = temp;
                pivotIndex++;
            }
        }
        Buah temp = listDaftarBuah[pivotIndex];
        listDaftarBuah[pivotIndex] = listDaftarBuah[high];
        listDaftarBuah[high] = temp;

        quickSortDescending(listDaftarBuah, low, pivotIndex - 1);
        quickSortDescending(listDaftarBuah, pivotIndex + 1, high);
    }
}

void sortHargaDescending(Buah *listDaftarBuah, int n) {
    quickSortDescending(listDaftarBuah, 0, n - 1);
}


void ubahBuah(Buah *listDaftarBuah, int index) {
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

void hapusBuah(Buah *listDaftarBuah, int &index) {
    string loop;
    int indeks;
    do {
        tampilkan(listDaftarBuah, index);
        if (index > 0) {
            cout << "Hapus nomor buah yang anda inginkan: ";
            cin >> indeks;
            for (int i = indeks; i < index; i++) {
                listDaftarBuah[i - 1] = listDaftarBuah[i];
            }
            index--;
            tampilkan(listDaftarBuah, index);
            cout << "Apakah anda ingin ingin menghapus lagi? (ya/tidak) : ";
            cin >> loop;
        } else {
            cout << "Daftar buah kosong. Tekan 'tidak' untuk kembali : ";
            cin >> loop;
        }
    } while (loop == "ya");
}

double hitungTotalHarga(Buah *listDaftarBuah, int index) {
    double totalHarga = 0.0;
    for (int i = 0; i < index; i++) {
        totalHarga += listDaftarBuah[i].hargaDetail.harga;
    }
    return totalHarga;
}

int sequentialSearchAscending(Buah *listDaftarBuah, int n, string key) {
    for (int i = 0; i < n; i++) {
        if (listDaftarBuah[i].nama == key) {
            return i;
        }
    }
    return -1;
}

int binarySearchDescending(Buah *listDaftarBuah, int left, int right, double key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (listDaftarBuah[mid].hargaDetail.harga == key) {
            return mid;
        }
        if (listDaftarBuah[mid].hargaDetail.harga < key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
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
    string loop;
    do {
        cout << "===== Toko Buah =====" << endl;
        cout << "1. Tambah Buah" << endl;
        cout << "2. Ubah Buah" << endl;
        cout << "3. Hapus Buah" << endl;
        cout << "4. Tampilkan Daftar Buah" << endl;
        cout << "5. Pencarian" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahBuah(ListDaftarBuah, index);
                break;
            case 2:
                ubahBuah(ListDaftarBuah, index);
                break;
            case 3:
                hapusBuah(ListDaftarBuah, index);
                break;
            case 4:
                int sortChoice;
                cout << "Pilih metode sorting:" << endl;
                cout << "1. Bubble Sort (Descending huruf berdasarkan nama buah)" << endl;
                cout << "2. Selection Sort (Ascending angka berdasarkan harga)" << endl;
                cout << "3. Quick Sort (Descending angka berdasarkan harga)" << endl;
                cout << "Pilihan : ";
                cin >> sortChoice;

                switch (sortChoice) {
                    case 1:
                        bubbleSortDescending(ListDaftarBuah, index);
                        break;
                    case 2:
                        selectionSortAscending(ListDaftarBuah, index);
                        break;
                    case 3:
                        quickSortDescending(ListDaftarBuah, 0, index - 1);
                        break;
                    default:
                        cout << "Pilihan tidak valid." << endl;
                        break;
                }

                tampilkan(ListDaftarBuah, index);
                cout << "kembali (y) : ";
                cin >> loop;
                break;
            case 5:
                int searchChoice;
                cout << "Pilih metode pencarian:" << endl;
                cout << "1. Sequential Search (Ascending)" << endl;
                cout << "2. Binary Search (Descending)" << endl;
                cout << "Pilihan : ";
                cin >> searchChoice;

                switch (searchChoice) {
                    case 1: {
                        string keyword;
                        cout << "Masukkan nama buah yang ingin dicari: ";
                        cin >> keyword;
                        int result = sequentialSearchAscending(ListDaftarBuah, index, keyword);
                        if (result != -1) {
                            cout << "Buah ditemukan pada indeks " << result + 1 << endl;
                        } else {
                            cout << "Buah tidak ditemukan" << endl;
                        }
                        break;
                    }
                    case 2: {
                        double harga;
                        cout << "Masukkan harga buah yang ingin dicari: Rp";
                        cin >> harga;
                        int result = binarySearchDescending(ListDaftarBuah, 0, index - 1, harga);
                        if (result != -1) {
                            cout << "Buah ditemukan pada indeks " << result + 1 << endl;
                        } else {
                            cout << "Buah tidak ditemukan" << endl;
                        }
                        break;
                    }
                    default:
                        cout << "Pilihan tidak valid." << endl;
                        break;
                }

                cout << "kembali (y) : ";
                cin >> loop;
                break;
            case 6:
                cout << "Total Harga Semua Buah: Rp" << hitungTotalHarga(ListDaftarBuah, index) << endl;
                cout << "Terima kasih telah menggunakan aplikasi Toko Buah\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih 1 - 6\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}