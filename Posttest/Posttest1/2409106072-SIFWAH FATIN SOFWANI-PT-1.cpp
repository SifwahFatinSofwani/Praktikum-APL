#include <iostream>
#include <limits>
using namespace std;

int main() {
    system("cls");
    string username, password;
    double rupiah, dolar, euro;
    double km, m, cm;
    double jam, menit, detik;
    double celcius, fahrenheit, kelvin;

    cout << string(61, '=') << endl;
    cout << "     silahkan masukkan username dan password untuk login" << endl;
    cout << string(61, '=') << endl;

    int chance = 0;
    while (chance < 3) {
        cout << "Masukkan username: ";
        getline(cin, username);
        cout << "Masukkan password: ";
        getline(cin, password);
        if (username == "sifwah fatin sofwani" && password == "2409106072") {
            break;
        } else {
            cout << "Username atau password salah" << endl;
            cout << "Anda memiliki " << 2 - chance << " kesempatan lagi" << endl;
            chance++;
            if (chance == 3) {
                cout << "Anda telah melebihi batas percobaan. Program akan keluar." << endl;
                return 0;
            }
        }
    }

    while (true) {
        system("cls");
        cout << string(77, '=') << endl;
        cout << "     Selamat datang di program konversi Mata uang, suhu, jarak, dan waktu" << endl;
        cout << string(77, '=') << endl;
        cout << "                   Pilih menu konversi yang diinginkan:   " << endl;
        cout << string(77, '=') << endl;
        cout << "1. Konversi Mata Uang" << endl;
        cout << "2. Konversi Jarak" << endl;
        cout << "3. Konversi Waktu" << endl;
        cout << "4. Konversi Suhu" << endl;
        cout << "5. Keluar" << endl;
        cout << string(72, '=') << endl;
        cout << "Masukkan pilihan anda: ";
        int pilihan;
        cin >> pilihan;
        system("cls");
        if (pilihan == 1) {
            while (true) {
                cout << string(67, '=') << endl;
                cout << "            Selamat datang di program konversi mata uang" << endl;
                cout << string(67, '=') << endl;
                cout << "                Pilih menu konversi yang diinginkan:   " << endl;
                cout << string(67, '=') << endl;
                cout << "1. Rupiah ke Dolar" << endl;
                cout << "2. Rupiah ke Euro" << endl;
                cout << "3. Dolar As ke Rupiah" << endl;
                cout << "4. Dolar As ke Euro" << endl;
                cout << "5. Euro ke Rupiah" << endl;
                cout << "6. Euro ke Dolar As" << endl;
                cout << "7. Kembali ke menu utama" << endl;
                cout << string(67, '=') << endl;
                cout << "Masukkan pilihan anda: ";
                cin >> pilihan;
                system("cls");
                if (pilihan == 1) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Rupiah ke Dolar" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan jumlah uang dalam Rupiah: ";
                    cin >> rupiah;
                    system("cls");
                    dolar = rupiah / 16348;
                    cout << "Rp." << rupiah << " = " << dolar << "$" << endl;
                } else if (pilihan == 2) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Rupiah ke Euro" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan jumlah uang dalam Rupiah: ";
                    cin >> rupiah;
                    system("cls");
                    euro = rupiah / 17097;
                    cout << "Rp." << rupiah << " = " << euro << " Euro" << endl;
                } else if (pilihan == 3) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Dolar ke Rupiah" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan jumlah uang dalam Dolar: ";
                    cin >> dolar;
                    system("cls");
                    rupiah = dolar * 16348;
                    cout << dolar << " Dolar = " << rupiah << " Rupiah" << endl;
                } else if (pilihan == 4) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Dolar ke Euro" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan jumlah uang dalam Dolar: ";
                    cin >> dolar;
                    system("cls");
                    euro = dolar * 0.92;
                    cout << dolar << " Dolar = " << euro << " Euro" << endl;
                } else if (pilihan == 5) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Euro ke Rupiah" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan jumlah uang dalam Euro: ";
                    cin >> euro;
                    system("cls");
                    rupiah = euro * 17097;
                    cout << euro << " Euro = " << rupiah << " Rupiah" << endl;
                } else if (pilihan == 6) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Euro ke Dolar" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan jumlah uang dalam Euro: ";
                    cin >> euro;
                    system("cls");
                    dolar = euro * 1.09;
                    cout << euro << " Euro = " << dolar << " Dolar" << endl;
                } else if (pilihan == 7) {
                    break;
                } else {
                    cout << "Pilihan tidak valid. Silahkan pilih menu yang tersedia." << endl;
                }
            }
        } else if (pilihan == 2) {
            while (true) {
                cout << string(67, '=') << endl;
                cout << "            Selamat datang di program konversi jarak" << endl;
                cout << string(67, '=') << endl;
                cout << "                Pilih menu konversi yang diinginkan:   " << endl;
                cout << string(67, '=') << endl;
                cout << "1. Kilometer ke Meter" << endl;
                cout << "2. Kilometer ke Centimeter" << endl;
                cout << "3. Meter ke Kilometer" << endl;
                cout << "4. Meter ke Centimeter" << endl;
                cout << "5. Centimeter ke Kilometer" << endl;
                cout << "6. Centimeter ke Meter" << endl;
                cout << "7. Kembali ke menu utama" << endl;
                cout << string(67, '=') << endl;
                cout << "Masukkan pilihan anda: ";
                cin >> pilihan;
                system("cls");

                if (pilihan == 1) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Kilometer ke Meter" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan jarak dalam kilometer: ";
                    cin >> km;
                    system("cls");
                    m = km * 1000;
                    cout << km << " kilometer = " << m << " meter" << endl;
                } else if (pilihan == 2) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Kilometer ke Centimeter" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan jarak dalam kilometer: ";
                    cin >> km;
                    system("cls");
                    cm = km * 100000;
                    cout << km << " kilometer = " << cm << " centimeter" << endl;
                } else if (pilihan == 3) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Meter ke Kilometer" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan jarak dalam meter: ";
                    cin >> m;
                    system("cls");
                    km = m / 1000;
                    cout << m << " meter = " << km << " kilometer" << endl;
                } else if (pilihan == 4) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Meter ke Centimeter" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan jarak dalam meter: ";
                    cin >> m;
                    system("cls");
                    cm = m * 100;
                    cout << m << " meter = " << cm << " centimeter" << endl;
                } else if (pilihan == 5) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Centimeter ke Kilometer" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan jarak dalam centimeter: ";
                    cin >> cm;
                    system("cls");
                    km = cm / 100000;
                    cout << cm << " centimeter = " << km << " kilometer" << endl;
                } else if (pilihan == 6) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Centimeter ke Meter" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan jarak dalam centimeter: ";
                    cin >> cm;
                    system("cls");
                    m = cm / 100;
                    cout << cm << " centimeter = " << m << " meter" << endl;
                } else if (pilihan == 7) {
                    break;
                } else {
                    cout << "Pilihan tidak valid. Silahkan pilih menu yang tersedia." << endl;
                }
            }
        } else if (pilihan == 3) {
            while (true) {
                cout << string(67, '=') << endl;
                cout << "            Selamat datang di program konversi waktu" << endl;
                cout << string(67, '=') << endl;
                cout << "                Pilih menu konversi yang diinginkan:   " << endl;
                cout << string(67, '=') << endl;
                cout << "1. Jam ke Menit" << endl;
                cout << "2. Jam ke Detik" << endl;
                cout << "3. Menit ke Jam" << endl;
                cout << "4. Menit ke Detik" << endl;
                cout << "5. Detik ke Jam" << endl;
                cout << "6. Detik ke Menit" << endl;
                cout << "7. Kembali ke menu utama" << endl;
                cout << string(67, '=') << endl;
                cout << "Masukkan pilihan anda: ";
                cin >> pilihan;
                system("cls");

                if (pilihan == 1) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Jam ke Menit" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan waktu dalam jam: ";
                    cin >> jam;
                    system("cls");
                    menit = jam * 60;
                    cout << jam << " jam = " << menit << " menit" << endl;
                } else if (pilihan == 2) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Jam ke Detik" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan waktu dalam jam: ";
                    cin >> jam;
                    system("cls");
                    detik = jam * 3600;
                    cout << jam << " jam = " << detik << " detik" << endl;
                } else if (pilihan == 3) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Menit ke Jam" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan waktu dalam menit: ";
                    cin >> menit;
                    system("cls");
                    jam = menit / 60;
                    cout << menit << " menit = " << jam << " jam" << endl;
                } else if (pilihan == 4) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Menit ke Detik" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan waktu dalam menit: ";
                    cin >> menit;
                    system("cls");
                    detik = menit * 60;
                    cout << menit << " menit = " << detik << " detik" << endl;
                } else if (pilihan == 5) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Detik ke Jam" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan waktu dalam detik: ";
                    cin >> detik;
                    system("cls");
                    jam = detik / 3600;
                    cout << detik << " detik = " << jam << " jam" << endl;
                } else if (pilihan == 6) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Detik ke Menit" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan waktu dalam detik: ";
                    cin >> detik;
                    system("cls");
                    menit = detik / 60;
                    cout << detik << " detik = " << menit << " menit" << endl;
                } else if (pilihan == 7) {
                    break;
                } else {
                    cout << "Pilihan tidak valid. Silahkan pilih menu yang tersedia." << endl;
                }
            }
        } else if (pilihan == 4) {
            while (true) {
                cout << string(67, '=') << endl;
                cout << "            Selamat datang di program konversi suhu" << endl;
                cout << string(67, '=') << endl;
                cout << "                Pilih menu konversi yang diinginkan:   " << endl;
                cout << string(67, '=') << endl;
                cout << "1. Celcius ke Fahrenheit" << endl;
                cout << "2. Celcius ke Kelvin" << endl;
                cout << "3. Fahrenheit ke Celcius" << endl;
                cout << "4. Fahrenheit ke Kelvin" << endl;
                cout << "5. Kelvin ke Celcius" << endl;
                cout << "6. Kelvin ke Fahrenheit" << endl;
                cout << "7. Kembali ke menu utama" << endl;
                cout << string(67, '=') << endl;
                cout << "Masukkan pilihan anda: ";
                cin >> pilihan;
                system("cls");

                if (pilihan == 1) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Celcius ke Fahrenheit" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan suhu dalam celcius: ";
                    cin >> celcius;
                    system("cls");
                    fahrenheit = (celcius * 9 / 5) + 32;
                    cout << celcius << " celcius = " << fahrenheit << " fahrenheit" << endl;
                } else if (pilihan == 2) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Celcius ke Kelvin" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan suhu dalam celcius: ";
                    cin >> celcius;
                    system("cls");
                    kelvin = celcius + 273.15;
                    cout << celcius << " celcius = " << kelvin << " kelvin" << endl;
                } else if (pilihan == 3) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Fahrenheit ke Celcius" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan suhu dalam fahrenheit: ";
                    cin >> fahrenheit;
                    system("cls");
                    celcius = (fahrenheit - 32) * 5 / 9;
                    cout << fahrenheit << " fahrenheit = " << celcius << " celcius" << endl;
                } else if (pilihan == 4) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Fahrenheit ke Kelvin" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan suhu dalam fahrenheit: ";
                    cin >> fahrenheit;
                    system("cls");
                    kelvin = (fahrenheit - 32) * 5 / 9 + 273.15;
                    cout << fahrenheit << " fahrenheit = " << kelvin << " kelvin" << endl;
                } else if (pilihan == 5) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Kelvin ke Celcius" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan suhu dalam kelvin: ";
                    cin >> kelvin;
                    system("cls");
                    celcius = kelvin - 273.15;
                    cout << kelvin << " kelvin = " << celcius << " celcius" << endl;
                } else if (pilihan == 6) {
                    cout << string(50, '=') << endl;
                    cout << "            Konversi Kelvin ke Fahrenheit" << endl;
                    cout << string(50, '=') << endl;
                    cout << "Masukkan suhu dalam kelvin: ";
                    cin >> kelvin;
                    system("cls");
                    fahrenheit = (kelvin - 273.15) * 9 / 5 + 32;
                    cout << kelvin << " kelvin = " << fahrenheit << " fahrenheit" << endl;
                } else if (pilihan == 7) {
                    break;
                } else {
                    cout << "Pilihan tidak valid. Silahkan pilih menu yang tersedia." << endl;
                }
            }
        } else if (pilihan == 5) {
            cout << "Program selesai. Terima kasih telah menggunakan program ini." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid. Silahkan pilih menu yang tersedia." << endl;
        }
    }

    return 0;
}