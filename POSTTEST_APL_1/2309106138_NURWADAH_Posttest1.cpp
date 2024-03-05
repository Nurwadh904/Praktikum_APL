#include <iostream>
using namespace std;

int main()
{
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
    }

    int pilihan;
    float C, K, R, F, temperatur;
    char pilih;

    do {
        cout << "           KONVERSI SUHU           " << endl;
        cout << "===================================" << endl;
        cout << "PILIH SUHU YANG INGIN DIKONVERSIKAN" << endl;
        cout << "===================================" << endl;
        cout << "1. Celcius" << endl;
        cout << "2. Kelvin" << endl;
        cout << "3. Reamur" << endl;
        cout << "4. Farenheit" << endl;
        cout << "Pilih Suhu: "; cin >> pilihan;

        if (pilihan = 1) {
            cout << "Konversi Suhu Celcius" << endl;
            cout << "Masukkan suhu: "; cin >> temperatur;
            F = (9 * temperatur / 5) + 32;
            K = temperatur + 273.15;
            R = (4 * temperatur) / 5;
            cout << "Farenheit = " << F << endl;
            cout << "Kelvin = " << K << endl;
            cout << "Reamur = " << R << endl;
        } else if (pilihan = 2) {
            cout << "Konversi Suhu Kelvin" << endl;
            cout << "Masukkan suhu: "; cin >> temperatur;
            C = temperatur - 273.15;
            F = (temperatur - 273.15) * 9 / 5 + 32;
            R = (temperatur - 273.15) * 4 / 5;
            cout << "Celcius = " << C << endl;
            cout << "Farenheit = " << F << endl;
            cout << "Reamur = " << R << endl;
        } else if (pilihan = 3) {
            cout << "Konversi Suhu Reamur" << endl;
            cout << "Masukkan suhu: "; cin >> temperatur;
            C = 5 * temperatur / 4;
            F = 9 * temperatur / 4 + 32;
            K = 5 * temperatur / 4 + 273.15;
            cout << "Celcius = " << C << endl;
            cout << "Farenheit = " << F << endl;
            cout << "Kelvin = " << K << endl;
        } else if (pilihan = 4) {
            cout << "Konversi Suhu Farenheit" << endl;
            cout << "Masukkan suhu: "; cin >> temperatur;
            C = (temperatur - 32) * 5 / 9;
            K = (temperatur - 32) * 5 / 9 + 273.15;
            R = (temperatur - 32) * 4 / 9;
            cout << "Celcius = " << C << endl;
            cout << "Kelvin = " << K << endl;
            cout << "Reamur = " << R << endl;
        } else {
            cout << "Mohon maaf, pilihan suhu yang dikonversikan salah" << endl;
        }

        cout << "Apakah Anda ingin melakukan konversi suhu lagi? (y/n): "; 
        cin >> pilih;
    } while (pilih == 'y' || pilih == 'Y');

    cout << "Terima kasih telah menggunakan program konversi suhu." << endl;

    return 0;
}
