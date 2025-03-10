#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <limits>
#include <string>

using namespace std;

string listherometa[5][50] = {
    {"Fanny: Assasin, Mekanik tinggi", "Ling: Assasin, Mekanik tinggi", "Nolan: Assasin, Mekanik tinggi", "Julian: Assasin, Mage, Mekanik sedang", "Hayabusa: Assasin, Mekanik tinggi"},
    {"Gatot kaca: Tank, Fighter, Mekanik mudah", "Edith: Tank", "Chip: Support, Tank, Mekanik sedang", "Angela: Support", "Mathilda: Support, Mekanik rendah", "Grock: Support, Mekanik sedang"},
    {"Valentina: Mage, Mekanik sedang", "Yve: Mage, Mekanik Sedang", "Faramis: Mage, Mekanik sedang", "Aurora: Mage, Mekanik rendah", "Zhuxin: Mage, Mekanik sedang"},
    {"Harith: Mage, Mekanik tinggi", "Moskov: Marskman, Mekanik tinggi", "Claude: Marskman", "Nathan: Marksman, Mekanik tinggi", "Roger: Fighter, Marskman, Mekanik tinggi", "Lunox: Mage", "Miya: Marskman, Mekanik tinggi", "", "", ""},
    {"Ruby: Fighter, Mekanik sedang", "Edith: Tank, Fighter, Mekanik sedang", "Terizla: Fighter, Mekanik sedang", "Arlott: Fighter, Mekanik sedang", "Phoveus: Fighter, Mekanik sedang", "Gatotkaca: Tank, Fighter, Mekanik sedang", "Hylos: Tank, Mekanik rendah", "Benedetta: Assasin, Fighter, Mekanik tinggi"}
};

string listakun[100][3] = {
    {"admin", "123", "role"},
    {"user", "password", "user"}
};

void cls()
{
    system("cls"); // Membersihkan layar konsol
}

void viewhero()
{
    cls();
    for (int i = 0; i < 5; ++i) {
        if (i == 0) {
            cout << "Kategori Jungle:" << endl;
            cout << endl;
        } else if (i == 1) {
            cout << endl;
            cout << "Kategori Tank:" << endl;
            cout << endl;
        } else if (i == 2) {
            cout << endl;
            cout << "Kategori Mid:" << endl;
            cout << endl;
        } else if (i == 3) {
            cout << endl;
            cout << "Kategori Gold:" << endl;
            cout << endl;
        } else if (i == 4) {
            cout << endl;
            cout << "Kategori Exp:" << endl;
            cout << endl;
        }
        for (int j = 0; j < 50; ++j) {
            if (!listherometa[i][j].empty()) {
                cout << listherometa[i][j] << endl;
            }
        }
    }
    cout << endl;
    cout << "Tekan Enter untuk kembali ke menu utama." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter newline yang tersisa
    cin.get(); // Menunggu input dari pengguna
}

int user() {
    viewhero();
    return 0;
}

int main() {
    cls();
    while (true) {
        cout << "Selamat datang di program Mobile Legends" << endl;
        cout << "1. Login" << endl;
        cout << "2. Daftar Akun" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu : "; int menu; cin >> menu;
        cls();

        if (menu == 1) {
            cout << "Masukkan username dan password untuk login." << endl;
            while (true) {
                cout << "Input 0 untuk keluar dari program." << endl;
                cout << "Masukkan username : "; string inputUsername; cin >> inputUsername;
                cout << "Masukkan password : "; string inputPassword; cin >> inputPassword;
        
                bool isLogin = false;
                for (int i = 0; i < 100; ++i) {
                    if (inputUsername == listakun[i][0] && inputPassword == listakun[i][1]) {
                        cout << "Selamat datang, " << inputUsername << "." << endl;
                        if (listakun[i][2] == "user") {
                            user();
                            cls();
                            break;
                        } else if (listakun[i][2] == "admin") {
                            cout << "Anda memiliki akses admin." << endl;
                            cout << "Kembali ke menu utama." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter newline yang tersisa
                            cin.get(); // Menunggu input dari pengguna
                            cls();
                            break;
                        }
                    } else if (inputUsername == "0" || inputPassword == "0") {
                        cout << "Anda kembali ke menu sebelumnya." << endl;
                        isLogin = true;
                        break;
                    }
                }
                
                if (!isLogin) {
                    cout << "Username atau password salah. Silakan coba lagi." << endl;
                    continue;
                }
                cls();
                break;
            }

        } else if (menu == 2) {
            cout << "Masukkan username dan password untuk daftar." << endl;
            string newUsername, newPassword, newRole;
            int newRolePilihan;
            cout << "Username: "; cin >> newUsername;
            cout << "Password: "; cin >> newPassword;
            cout << "Role (1: admin, 2: user): "; cin >> newRolePilihan;
            
            if (newRolePilihan == 1) {
                newRole = "admin";
            } else if (newRolePilihan == 2) {
                newRole = "user";
            } else {
                cout << "Role tidak valid. Silakan coba lagi." << endl;
                continue;
            }
            
            for (int i = 0; i < 100; ++i) {
                if (listakun[i][0].empty()) {
                    listakun[i][0] = newUsername;
                    listakun[i][1] = newPassword;
                    listakun[i][2] = newRole;
                    cls();
                    cout << "Akun berhasil dibuat." << endl;
                    break;
                }
            }
        } else if (menu == 0) {
            cout << "Anda keluar dari program." << endl;
            return 0;
        } else {
            cout << "Menu tidak valid. Silakan coba lagi." << endl;
        }      
    }
}